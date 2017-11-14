/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funktions.cpp
 * Author: Sebastian Pauli
 * 
 * Created on 26. Oktober 2017, 20:12
 */

#include <iostream>
#include "funktions.h"

using namespace std;

//Aufgabe 1:
void split(int input){
    int input2 = input;
    int length = 1;
    
    while(input2 > 10){
       input2 = input2 / 10;
       length = length * 10;
   }
    
    for (int i = length; i > 0; i = i/10){
        int out = input / i %10; 
        cout << out << endl;         
    }

} 
    



//Aufgabe 2:
void even(int start, int end){
    while (start < end){
        if (start % 2 == 0){
            cout << start << endl;
            start++;
        }else{
            start++;
        }
    }
}



//Aufgabe 3:
void numbers(){
    int number = 0;
    int avgNumber = number;
    int minNumber = number;
    int anz = 0;
    
    cout << "Bitte geben Sie eine Zahl ein: " << endl;
    cin >> number;
    anz++;
 
    for(int i = 0; number > 0; number = number){
        
        
        avgNumber = (avgNumber + number)/anz;
        anz++;
        
        if (number < minNumber){
            minNumber = number;
        }    
        cout << "Bitte geben Sie die nächste Zahl ein: " << endl;
        cin >> number;
    }
    cout << "Die durchschnittliche Zahl ist: " << avgNumber << endl;
    cout << "Die Minimalzahl ist: " << minNumber << endl;
}


    
// Aufgabe 4. Ermittlung der Schaltjahre
bool isLeapYear(int year){
    if(year %4 == 0){
        return true;
    }else{
        return false;
    }  
}



 

