/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DynArray.h
 * Author: Sebastian Pauli
 *
 * Created on 9. Dezember 2017, 20:03
 */

#ifndef DYNARRAY_H
#define DYNARRAY_H

class DynArray
{
public:
DynArray(); //Standardkonstruktor
DynArray(int newCapacity); //Weiterer Konstruktor
~DynArray(); //Destruktor
double& at(int index);
void push_back(double elem);
void pop_back();
void erase(int index);
int size();
int capacity();
void print();
private:
void resize(int newCapacity);
double* m_data;
int m_size = 0;
int m_capacity = 0;
};

#endif /* DYNARRAY_H */

