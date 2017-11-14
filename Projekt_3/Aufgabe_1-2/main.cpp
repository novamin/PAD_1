/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Sebastian Pauli
 *
 * Created on 4. November 2017, 22:54
 */

#include <iostream>
#include "functions.h"

using namespace std;


/*
 * 
 */

int main() {
    //Aufgabe 1 - Deklaration 
   const int laenge = 5;
   int a[laenge] = {1,2,10,3,7};
   
   
   
   //Aufgabe 1 - Histogramm
   histogramm(a,laenge);
   
   
   //Aufgabe 2 - Primzahlen
   
   prim();
    
    
    return 0;
}

