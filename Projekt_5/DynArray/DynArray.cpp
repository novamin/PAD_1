/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DynArray.cpp
 * Author: Sebastian Pauli
 * 
 * Created on 9. Dezember 2017, 20:03
 */

#include "DynArray.h"
#include <iostream>

DynArray::DynArray(): m_capacity(8)  {
    m_data = new double[8];
    
}


DynArray::DynArray(int newCapacity): m_capacity(newCapacity){
    m_data = new double[newCapacity];
    
}

//Warum muss der Rückgabedatentyp double& sein, warum reicht double nicht aus?
double& DynArray::at(int index){
    return m_data[index];
}

int DynArray::size(){
    return m_size;
}

int DynArray::capacity(){
    return m_capacity;
}


void DynArray::print(){
    for (int i = 0; i < m_size; i++){
        std::cout << m_data[i] << std::endl;
    }
}


void DynArray::resize(int newCapacity){
    double* array = new double[newCapacity];
    for(int i = 0; i < m_size; i++){
        array[i] = m_data[i];
    }
    delete [] m_data;
    m_data = array;
     
}


void DynArray::push_back(double elem) {        
        if (m_size < m_capacity) {
            int capacity = m_capacity*2;
            DynArray::resize(capacity);
            m_data[m_size] = elem;
        } else {
            m_data[m_size] = elem;
        }
    m_size++;
}


void DynArray::pop_back(){
    m_size--;
}


void DynArray::erase(int index){
    
    for(int i = index; i <= m_size; i++){
        m_data[i] = m_data[i+1];
    }
    m_size--;
}


DynArray::~DynArray() {
    delete [] m_data;
    
}
