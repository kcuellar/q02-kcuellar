/**
 * Unit Tests for Piezas
 **/

#include <iostream>
using namespace std;

#include <gtest/gtest.h>
#include "Piezas.h"

class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/*TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}*/

TEST(PiezasTest, resetBoard)
{
	Piezas game;
	Piece one;
	Piece two;
	game.dropPiece(3);
	game.dropPiece(3);
	one = game.dropPiece(3);
	game.reset();
	two = game.pieceAt(2,3);
	ASSERT_NE(one, two);
}

TEST(PiezasTest, placeX)
{
	Piezas game;
	Piece one;
	Piece two;
	one = game.dropPiece(1);
	two = game.pieceAt(0,1);
	ASSERT_EQ(one, two);
}

TEST(PiezasTest, placeO)
{
	Piezas game;
	Piece one;
	Piece two;
	game.dropPiece(1);
	one = game.dropPiece(1);
	two = game.pieceAt(1,1);
	ASSERT_EQ(one, two);
}


TEST(PiezasTest, outOfBounds1)
{
	Piezas game;
	Piece one;
	one = game.dropPiece(-1);
	ASSERT_EQ(one, Invalid);
}

TEST(PiezasTest, outOfBounds2)
{
	Piezas game;
	Piece one;
	one = game.dropPiece(4);
	ASSERT_EQ(one, Invalid);
}

TEST(PiezasTest, outOfBounds3)
{
	Piezas game;
	Piece one;
	game.dropPiece(3);
	one = game.dropPiece(4);
	ASSERT_EQ(one, Invalid);
}

TEST(PiezasTest, columnFull)
{
	Piezas game;
	Piece one;
	game.dropPiece(3);
	game.dropPiece(3);
	game.dropPiece(3);
	one = game.dropPiece(3);
	ASSERT_EQ(one, Blank);
}

TEST(PiezasTest, columnFull1)
{
	Piezas game;
	Piece one;
	game.dropPiece(3);
	game.dropPiece(3);
	game.dropPiece(3);
	game.dropPiece(2);
	one = game.dropPiece(3);
	ASSERT_EQ(one, Blank);
}

TEST(PiezasTest, noPiece)
{
	Piezas game;
	Piece one;
	game.dropPiece(2);
	one = game.pieceAt(2,3);
	ASSERT_EQ(one, Blank);
}

TEST(PiezasTest, pieceAtOut1)
{
	Piezas game;
	Piece one;
	one = game.pieceAt(-1,0);
	ASSERT_EQ(one, Invalid);
}

TEST(PiezasTest, pieceAtOut2)
{
	Piezas game;
	Piece one;
	one = game.pieceAt(3,0);
	ASSERT_EQ(one, Invalid);
}

TEST(PiezasTest, pieceAtOut3)
{
	Piezas game;
	Piece one;
	one = game.pieceAt(0,-1);
	ASSERT_EQ(one, Invalid);
}

TEST(PiezasTest, pieceAtOut4)
{
	Piezas game;
	Piece one;
	one = game.pieceAt(0,4);
	ASSERT_EQ(one, Invalid);
}

TEST(PiezasTest, notOver)
{
	Piezas game;
	Piece one;
	one = game.gameState();
	ASSERT_EQ(one, Invalid);
}

TEST(PiezasTest, winner1X)
{
	Piezas game;
	Piece one;
	game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(1);
	game.dropPiece(3);
	game.dropPiece(1);
	game.dropPiece(0);


	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(2);
	game.dropPiece(2);
	game.dropPiece(4);
	game.dropPiece(3);
	game.dropPiece(3);

	one = game.gameState();
	ASSERT_EQ(one, X);
}

TEST(PiezasTest, tie)
{
	Piezas game;
	Piece one;

	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(3);

	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(3);

	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(3);

	one = game.gameState();
/*	cout << X << endl;
	cout << O << endl;
	cout << Blank << endl;
	cout << Invalid << endl; */
	ASSERT_EQ(one, Blank);
}

TEST(PiezasTest, winnerOH)
{
	Piezas game;
	Piece one;

	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(0);

	game.dropPiece(3);
	game.dropPiece(1);
	game.dropPiece(0);
	game.dropPiece(2);

	game.dropPiece(1);
	game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(3);

	one = game.gameState();
	ASSERT_EQ(one, O);
}

TEST(PiezasTest, winnerOV)
{
	Piezas game;
	Piece one;

	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(0);

	game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(1);
	game.dropPiece(2);

	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(3);
	game.dropPiece(3);

	one = game.gameState();
	ASSERT_EQ(one, X);
}
