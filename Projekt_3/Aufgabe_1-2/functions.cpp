/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   functions.cpp
 * Author: Sebastian Pauli
 * 
 * Created on 4. November 2017, 22:55
 */
#include <iostream>
#include "functions.h"

using namespace std;

// Aufgabe 1 - Histogramm
void histogramm(int a[], int laenge){
    for (int i = 0; laenge-1 >= i; i++){
        
        for (int j = a[i]; a[i] > 0; a[i]--){
            cout << "*";
        }
        cout << endl;
    }    
}


// Aufgabe 2 - Funktion Primzahlen prüfen

bool primpruef(int i){
    int counter = 2;
// Da 1 & 2 keine Primzahl ist, muss i > 2 sein.
    if(i > 2){

        while (counter < i){
    //Prüfung auf Primzahl hier.
    
            /* Da eine Primzahl nur durch 1 und sich selber teilbar ist,
            ** wird hier die Zahl nacheinander durch alle Zahlen zwischen 1 und < i geteilt und geprüft,
            ** ob es ein Restwert gibt (mithilfe von Modulo.) 
            ** Falls eine Zahl gefunden wird, die teilbar ist (bei der der Restwert 0 ist) wird false zurückgegeben, da die Zahl dann keine
            ** Primzahl sein kann.
            */
            
            if(i%counter == 0){
                return false;
            }
            counter++;
        }
        return true;
    }
        return false;
    }


//Aufgabe 2 - Primzahlen

void prim(){
    int start = 0;
    int end = 0;
    
    cout << "Bitte geben Sie eine Startzahl ein: " << endl;
    cin >> start;
    cout << "Bitte geben Sie eine Endzahl ein: " << endl;
    cin >> end;
    
// Schleife, die nacheinander alle Zahlen zwischen Start und Ende an die Funktion "primpruef" übergibt.    
    for (int i = start; i < end; i++){
        if(primpruef(i)){ 
            cout << i << endl;
        }
        }
}
    



