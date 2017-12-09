/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mastermind.cpp
 * Author: Sebastian Pauli
 * 
 * Created on 27. November 2017, 20:50
 */

#include "Mastermind.h"
#include "functions.hpp"
#include <iostream>

//Funktion für das Spiel-spielen
void Mastermind::Game() {
    //bool match = true;
    int rounds = 8;
 
    std::cout << "Bitte geben Sie die Zahl ein, die erraten werden soll. " << std::endl;
    std::vector<int> correct = check_input();

//Schleife für die 8 Runden, die zu spielen sind
    for(int i = 0; i < rounds; i++){
        std::cout << "Bitte geben Sie eine Zahl ein. " << std::endl;
        std::vector<int> code = check_input();
            
        if(black(code, correct) == 4){
            std::cout << "Gewonnen! " << std::endl;
            return;
        }
        
        std::cout << "Black_markers" << black(code, correct) << std::endl;
        std::cout << "White_Markers" << white(code,correct) << std::endl;
    }
    
    std::cout << "Game Over!!! " << std::endl;
}

//Funktion für das Einlesen und checken der Eingabe
//Eingabe wird gesplittet und isValid übergeben. Falls true, wird der
//Vector guess zurückgegeben. Falls false wird die Eingabe erneut abgefragt
    std::vector<int> Mastermind::check_input(){
        int in = 0;
        int maxlen = 4;
        int isvalid_min = 1;
        int isvalid_max = 6;
        std::vector<int> guess;
        
        while(true){
            std::cin >> in;
            guess = split(in);
            if(isValidInput(guess, maxlen, isvalid_min, isvalid_max)){
                break;
            }
            std::cout << "Die Eingabe ist ungültig, bitte versuchen Sie es erneut. " << std::endl;
        }
        return guess;
    }
    
    
    
//Funktion für das Aufteilen der Zahl in Ihre Ziffern (Praktikum 2)
    std::vector<int> Mastermind::split(int in){
    int in2 = in;
    int len = 1;
    std::vector<int> splitVec;
    
    while(in2 > 10){
       in2 = in2 / 10;
       len = len * 10;
   }
    for (int i = len; i > 0; i = i/10){
        int out = in / i %10; 
        splitVec.push_back(out);         
    }
    return splitVec;
} 