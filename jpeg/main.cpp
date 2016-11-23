/*
Copyright 2016 AstToggie
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
 */

/* 
 * File:   main.cpp
 * Author: asttoggie
 * 
 * Created on October 11, 2016, 11:51 PM
 */

#include <cstdlib>
#include <stdio.h> // sprintf(..), fopen(..)
#include <stdarg.h> //dprintf(..)
#include <math.h> // sqrt(..), cos(..)

int main(int argc, char** argv) 
{    
    ///////////Convert RGB to YUB///////////////////
    int a,          //lengh line
        b,          //number columns
        R[a][b],    //array R
        G[a][b],    //array G
        B[a][b],    //array B
        Y[a][b],    //array Y
        U[a][b],    //array U
        V[a][b];    //array V
    
    for (int i = 0; i < a; i ++)
    {
        for (int q = 0; q < b; q ++)
        {
            Y[i][q] = (R[i][q] + (2 * G[i][q]) + V[i][q]) / 4;
            U[i][q] = R[i][q] - G[i][q];
            V[i][q] = B[i][q] - G[i][q];
        }
    }
    
          
  return 0;
}


/*
 char *JpgFileInName = "test.jpg";
    FILE *fp;
    fp = fopen(JpgFileInName, "rb");
    if (fp == NULL)
    {
        dprintf("Cannot open jpg file: %s\n", JpgFileInName);
        return 0;
    } 
 */
