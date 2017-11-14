/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Sebastian Pauli
 *
 * Created on 12. November 2017, 18:37
 */

#include <iostream>
#include "functions.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int in = 0;
  
    //Textbasiertes Menü
    while (in != 4){
    cout << "Bitte Wählen Sie eine Aktion aus. " << endl;
    cout << "1 -> Alle Bücher anzeigen " << endl;
    cout << "2 -> Ein Buch hinzufügen " << endl;
    cout << "3 -> Testdaten erzeugen " << endl;
    cout << "4 -> Programm beenden " << endl << endl;
    cout << "Bitte geben Sie Ihre Auswahl ein: ";
    cin >> in;
    //Je nach auswahl -> Funktion ausführen
    switch(in){
        case 1: show_books();break;
        case 2: add_book();break;
        case 3: generate_data();break;
        case 4: break;
        default: cout << "Keine gültige Eingabe." << endl; break;
   }
}
    return 0;
}

