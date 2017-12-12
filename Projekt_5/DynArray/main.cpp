/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Sebastian Pauli
 *
 * Created on 9. Dezember 2017, 20:03
 */

#include <cstdlib>
#include <iostream>
#include "DynArray.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    DynArray array;
    
    array.print();
    
    array.push_back(1.1);
    array.push_back(2.2);
    array.push_back(3.3);
    array.push_back(111.1);
    array.capacity();
    array.erase(3);
    cout << array.capacity() << endl;
    array.print();
    
    return 0;
}

