/* 
 * File:   GameOfLife.h
 * Author: Sebastian Pauli
 *
 * Created on January 12, 2018, 9:52 PM
 */

#pragma once
#include <string>
#include <vector>

class gameOfLife {
public:
    gameOfLife();
    gameOfLife(int numbRow, int numbCol, int NumbGen);
    void playGame(int** gameField);
    int** standardGameField();
    virtual ~gameOfLife();
private:
    int row = 0;
    int col = 0;
    int generations = 0;
    int neighborsAlive = 0;
    int numbRow = 0;
    int numbCol = 0;
    int numbGen = 0;
    int** gameField_0;
    int** gameField_1;
    int** createGameField(int row, int col);
    int** calculateNextGeneration();
    void printGameField(int** outputGameField);
    int checkNeighbor(int i, int j);
    void swapGameField();
    void bitmap(int** field, int generation);
    
};

