/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   functions.hpp
 * Author: Sebastian Pauli
 *
 * Created on 27. November 2017, 20:50
 */

#include <vector>

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

//Funktion um zu prüfen, ob die Eingabe valide ist.
// Prüfung der Länge des Vectors und die Einzelnen Zahlen des Vektors.
template <typename T>
bool isValidInput(const std::vector<T>& guess, int length, T min, T max)
{
    if(guess.size() != length){
        return false;
    }
    for(int i = 0; i < guess.size(); i++){
        if(guess[i] < min || guess[i] > max){
            return false;
        }    
    }
     return true;
    
}

//Schauen, ob die Eingegebene Zahl irgendwo in dem "Zu-Erratenen Vektor" vorkommt
//Treffer Zählen und zurückgeben 
template <typename T>
int white(const std::vector<T>& solution, const std::vector<T>& guess)
{
    int counter = 0;
    for(int i = 0; i < guess.size(); i++){
        for(int j = 0; j < solution.size(); j++){
            if(solution[j] == guess[i]){
                counter++;
            }
        }
    }
    return counter;    
}

//Schauen, ob die Eingegebene Zahl irgendwo in dem Vektor vorkommt und auch die selbe Stelle ist.
//Gesamtanzahl der Treffer zurückgeben.
template <typename T>
int black(const std::vector<T>& solution, const std::vector<T>& guess)
{
int counter = 0;
    for(int i = 0; i < guess.size(); i++){
        if(guess[i] == solution[i]){
            counter++;
        }
    }
    return counter;
}






#endif /* FUNCTIONS_HPP */
