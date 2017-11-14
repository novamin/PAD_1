/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: bonny
 *
 * Created on 11. November 2017, 16:44
 */
#include <math.h>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int x = 0;
    int y = 0;
    int z = 0;
    int u = 2;
    int v = 1;
    
    /*
     Die Formel für die Tripel: 
     * x = u^2 - v^2; 
     * y = 2uv;
     * z = u^2 + v^2; 
     */
    
    for (int i = 0; i < 10; i++){
            //for (int i = v; i < u; i++){    
            if ( v < u){
            x = pow(u,2) - pow(v,2);
            y = 2*(u*v);
            z = pow(u,2) + pow(v,2);
            cout << x << " " << y << " " << z << endl; 
            v++;
            }
            else{
                u++;
                v = 1;
        //    }
        }
        
        
    
}
    
    return 0;
}

