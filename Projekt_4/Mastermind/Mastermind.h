/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mastermind.h
 * Author: Sebastian Pauli
 *
 * Created on 27. November 2017, 20:50
 */
#include<vector>
#ifndef MASTERMIND_H
#define MASTERMIND_H

class Mastermind {
public:
   void Game();
private: 
    std::vector<int> check_input();
    std::vector<int> split(int input);
};

#endif /* MASTERMIND_H */

