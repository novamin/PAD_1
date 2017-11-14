/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   functions.cpp
 * Author: Sebastian Pauli
 * 
 * Created on 12. November 2017, 19:11
 */

#include "functions.h"
#include <iostream>
#include <vector>

using namespace std;

// Hier der Enum für die einzelnen Buchkategorien.
enum Categorie{
    Sachbuch = 1,
    Ratgeber,
    Fantasy,
    SciFi,
    Manga
    };
    

// Hier der Struct als "Blaupause" für den Vector.
struct book {
    string title;
    string autor;
    int release;
    int pages;
    Categorie cat;
};

// Vector mit dem namen books erstellen und den struct book als "Blaupause"   
vector<book> books;

// ein Object mit dem Namen newBook erstellen, welches auch die Struktur von book besitzt.
book newBook;

// Hier wird ein Buch dem Vector hinzugefügt.
// Dazu werden die Daten zunächst abgefragt und in newBook gespeichert.
// Zum schluss werden dann die Daten von newBook dem Vector übergeben.
void add_book(){
    int in = 0;
    
    cout << "Bitte geben Sie den Titel ein: " << endl;
    cin >> newBook.title;
    
    cout << "Bitte geben Sie den Autor ein: " << endl;
    cin >> newBook.autor;
    
    cout << "Bitte geben Sie das Erscheinungsjahnr ein: " << endl;
    cin >> newBook.release;
    
    cout << "Bitte geben Sie die Seitenanzahl ein: " << endl;
    cin >> newBook.pages;
    
    cout << "Bitte wählen Sie die Buchkategorie aus: "  << endl;
    cout << "1 -> Sachbuch " << endl;
    cout << "2 -> Ratgeber " << endl;
    cout << "3 -> Fantasy " << endl;
    cout << "4 -> SciFi " << endl;
    cout << "5 -> Manga " << endl;
    
    cin >> in;

//Ein int kann nicht direkt in einem Enum-Typ gespeichert werden, ausdem Grund muss der Typ gecastet werden.
    newBook.cat = static_cast<Categorie>(in); 
    books.push_back(newBook);
    
}

// Funktion für das Anzeigen der Bücher
/*
 * Die for-Schleife durchläuft den Vektor solange, bis sie das Ende des Vektores erreicht hat.
 * Bei jedem Durchlauf werden die Daten für jedes einzelne Buch ausgegeben.
 * Da der Enum im Hintergrund die Objekte mit Zahlen verwaltet, werden diese Zahlen mit Hilfe
 * eines Sitch-Cases wieder lesbar ausgegeben. 
 */
void show_books(){
    for (int i = 0; i < books.size(); i++){
        cout << "Buch_Nr.: " << i << endl;
        cout << "Titel: " << books[i].title << endl;
        cout << "Autor: " << books[i].autor << endl;
        cout << "Erscheinungsjahr: " << books[i].release << endl;
        cout << "Seitenzahl: " << books[i].pages << endl;
        switch(books[i].cat){
            case 1: cout << "Buchkategorie: Sachbuch " << endl; break;
            case 2: cout << "Buchkategorie: Ratgeber " << endl; break;
            case 3: cout << "Buchkategorie: Fantasy " << endl; break;
            case 4: cout << "Buchkategorie: SciFi " << endl; break;
            case 5: cout << "Buchkategorie: Manga " << endl; break;
            default: cout << "Buchkategorie: Keine Buchkategorie. " << endl; break;
        } 
    }
   
}

// Hier werden die Beispieldaten generiert

void generate_data(){

//Buch 1 - Datengenerieren
newBook.title = "Titel 1";
newBook.autor = "Autor 1";
newBook.release = 2000;
newBook.pages = 100;
newBook.cat = static_cast<Categorie>(1);
books.push_back(newBook);

//Buch 2 - Datengenerieren
newBook.title = "Titel 2";
newBook.autor = "Autor 2";
newBook.release = 2002;
newBook.pages = 500;
newBook.cat = static_cast<Categorie>(2);
books.push_back(newBook);

//Buch 3 - Datengenerieren
newBook.title = "Titel 3";
newBook.autor = "Autor 3";
newBook.release = 2004;
newBook.pages = 800;
newBook.cat = static_cast<Categorie>(3);
books.push_back(newBook);

//Buch 4 - Datengenerieren
newBook.title = "Titel 4";
newBook.autor = "Autor 4";
newBook.release = 2006;
newBook.pages = 300;
newBook.cat = static_cast<Categorie>(4);
books.push_back(newBook);

//Buch 5 - Datengenerieren
newBook.title = "Titel 5";
newBook.autor = "Autor 5";
newBook.release = 2008;
newBook.pages = 250;
newBook.cat = static_cast<Categorie>(5);
books.push_back(newBook);

}


