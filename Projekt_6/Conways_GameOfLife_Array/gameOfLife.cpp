/* 
 * File:   GameOfLife.cpp
 * Author: Sebastian Pauli
 * 
 * Created on January 12, 2018, 9:52 PM
 */

#include "gameOfLife.h"
#include "Bitmap.h"
#include <iostream>
#include <unistd.h>
#include <iomanip>

gameOfLife::gameOfLife(): row(32), col(32), generations(150) {
    gameField_0 = createGameField(row,col);
    gameField_1 = createGameField(row,col);
    
}

gameOfLife::gameOfLife(int numbRow, int numbCol, int numbGen)  {
    row = numbRow;
    col = numbCol;
    generations = numbGen;
    gameField_0 = createGameField(row,col);
    gameField_1 = createGameField(row,col);
    
}

//Standard Start Spielfeld, welches zu beginn in gamefield_0 geladen wird, dabei wird der String vorher in einen integer umgewandelt.
int** gameOfLife::standardGameField(){
    int j = 0;
    int k = 0;
    int** startGameField = createGameField(row,col);
        std::string board = "";
        board += "                                ";
        board += " ##                          ## ";
        board += " # #                         ## ";
        board += "                                ";
        board += "   # #                          ";
        board += "                                ";
        board += "     # #                        ";
        board += "      ##                        ";
        board += "                                ";
        board += "                                ";
        board += "                           #  # ";
        board += "                          #     ";
        board += "                          #   # ";
        board += "                          ####  ";
        board += "                                ";
        board += "                                ";
        board += "                                ";
        board += "                                ";
        board += "  #                             ";
        board += "   #                            ";
        board += " ###                            ";
        board += "                                ";
        board += "                                ";
        board += "                                ";
        board += "                                ";
        board += "                                ";
        board += "                      ## #      ";
        board += " ##                ## # ## ###  ";
        board += " # #            ####  ##      # ";
        board += "   #           #    #   #   ##  ";
        board += "   ##           ##              ";
        board += "                                ";   
       
        for(int i = 0; i < board.length(); i++){
            if(board.at(i) == '#'){
                j = i/32;
                k = i%32;
                startGameField[j][k] = 1;
            }else{
             j = i/32;
             k = i%32;
            startGameField[j][k] = 0;
            }
    } 
    return startGameField;
    
}


//Erstellen der 2-Dimensionalen-Arrays, die für Spielfeld 1 und 2 benötigt werden und gibt diese zurück.
int** gameOfLife::createGameField(int row, int col){
    int** gameField = new int*[row]; 
    for(int i = 0; i < row; i++)
    gameField[i] = new int[col];
    return gameField;
}
       

//nächsten Tick für Spielfeld anhand der Regeln vorberechnen
//Aktuelle Spielfeld wird in gameField_0 gespeichert und ausgegeben.
//Das Spielfeld gameField_1 wird hier berechnet und anschließend in gameField_0 gespeichert.
//Dies wiederholt sich solange wie die Anzahl der Generationen ist.
//Regeln: 
//1. Eine tote Zelle mit genau drei lebenden Nachbarn wird in der Folgegeneration neu geboren.
//2. Lebende Zellen mit weniger als zwei lebenden Nachbarn sterben in der Folgegeneration an Einsamkeit.
//3. Eine lebende Zelle mit zwei oder drei lebenden Nachbarn bleibt in der Folgegeneration am Leben.
//4. Lebende Zellen mit mehr als drei lebenden Nachbarn sterben in der Folgegeneration an Überbevölkerung.
int** gameOfLife::calculateNextGeneration(){
    for(int i = 1; i < row-1; i++){
        for(int j = 1; j < col-1; j++){
            neighborsAlive = checkNeighbor(i, j);
            if(gameField_0[i][j] == 0 && neighborsAlive == 3){
                    gameField_1[i][j] = 1;
            }else if(gameField_0[i][j] == 1 && neighborsAlive < 2){
                gameField_1[i][j] = 0;
            }else if(gameField_0[i][j] == 1 && (neighborsAlive == 2 || neighborsAlive == 3)){
                gameField_1[i][j] = 1;
            }else if(gameField_0[i][j] == 1 && neighborsAlive > 3){
                gameField_1[i][j] = 0;
            }else{
                gameField_1[i][j] = gameField_0[i][j];
            }
        }
    }
    
   return gameField_1;
}

//Spiel starten (wird in der main mit einem übergebenen Spielfeld aufgerufen)
void gameOfLife::playGame(int** field){
    gameField_0 = field;
    int** gameField;
    for(int i = 0; i < generations; i++){
        gameField = calculateNextGeneration();
        std::cout << "Generation_" << i << std::endl;
        bitmap(gameField, i);
        for(int i = 0; i < row; i++ ){
        for(int j = 0; j < col; j++){
            std::cout << gameField[i][j];
        }
        }
        std::cout << std::endl;
        swapGameField();
        sleep(1);
    }
    
}

//Prüfen, ob und wie viele lebende Nachbarzellen es gibt.
//Anzahl wird zurückgegeben (wird für die Prüfung der Regeln benötigt)
int gameOfLife::checkNeighbor(int i, int j){
    int neighborsAlive = 0;        
            if(gameField_0[i-1][j] == 1)
                neighborsAlive++; 
            if(gameField_0[i+1][j] == 1)
                neighborsAlive++;
            if(gameField_0[i][j-1] == 1)
                neighborsAlive++;
            if(gameField_0[i][j+1] == 1)
                neighborsAlive++;
            if(gameField_0[i-1][j-1] == 1)
                neighborsAlive++;
            if(gameField_0[i+1][j+1] == 1)
                neighborsAlive++;
            if(gameField_0[i-1][j+1] == 1)
                neighborsAlive++;
            if(gameField_0[i+1][j-1] == 1)
                neighborsAlive++;   
    return neighborsAlive;
}

//Spielfelder switchen ("Double Buffering")
void gameOfLife::swapGameField(){
    int** gameField;
    gameField = gameField_0;
    gameField_0 = gameField_1;
    gameField_1 = gameField;
    
}

//Output des Spiels für jeden einzelnen Tick
void gameOfLife::bitmap(int** field, int generation){
    int picnumb = generation;
    std::string name = "Game_of_Life_";
    std::string scaled_name = "Game_of_Life_scaled_";
    name +=  std::to_string(picnumb);
    scaled_name += std::to_string(picnumb);
    name += ".bmp";
    scaled_name += ".bmp";
    
    //Einfaches Farbbild mit ein paar Testpixeln
    RgbImage rgb(32, 32);
    rgb.fill(RgbPixel(200, 200, 200));    
    int** gameField = field;
    for(int i = 0; i < row; i++ ){
        for(int j = 0; j < col; j++){
            if(gameField[i][j] == 1){
            rgb.setPixel(j, i, COLOR::Black); 
            }else{
            rgb.setPixel(j, i, COLOR::White);
            }
        }
    }    
    //Als Datei speichern
    //rgb.store(name);
    //Skalierte Version erstellen und speichern
    RgbImage tmp = rgb.scale(50);
    tmp.store(scaled_name);
}


//Deconstruktor ... gibt den Speicher, der für die 2 Dimensionalen Arrays verwendet wurde wieder frei.
gameOfLife::~gameOfLife() {
    for(int i = 0; i < row; i++){
        delete [] gameField_0[i];
        delete [] gameField_1[i];
    }
    delete [] gameField_0;
    delete [] gameField_1;
}

