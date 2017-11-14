/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Sebastian Pauli
 *
 * Created on 21. Oktober 2017, 20:09
 */

#include <iostream>
#include "funktions.h"
using namespace std;


int main(int argc, char** argv) {
    
//Deklaration
    
//Aufgabe 1
int input = 0;    
//Aufgabe 2
int start = 0;
int end = 0;
//Aufgabe 4
int year = 0;

//Deklaration ende



// Aufgabe 1
    cout << "Geben Sie eine Zahl ein: " << endl;
    cin >> input;
    split(input);

     
// Aufgabe 2 Gerade Zahlen
    cout << "Bitte geben Sie eine Start Zahl ein: ";
    cin >> start;
    cout << "Bitte geben Sie eine Ende Zahl ein: ";
    cin >> end;
    cout << "Alle gerade Zahlen zwischen: " << start << " und " << end << ": " << endl;
    even(start, end);
    
    
//Aufgabe 3 Zahlenfolge
    numbers();
    
    
    
//Aufgabe 4 Schaltjahre abfragen
    cout << "Bitte geben Sie das Jahr ein: " << endl;
    cin >> year;
    if(isLeapYear(year)){
        cout << "Das Jahr ist ein Schaltjahr.";
    }else{
        cout << "Das Jahr ist kein Schaltjahr.";
    }
    return 0;
}

