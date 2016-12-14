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
#include "loadjpg.h" // ConvertJpgFile(..)

#include "savejpg.h"    // SaveJpgFile(..)

/***************************************************************************/
/*                                                                         */
/ FeedBack Data                                                           /
/*                                                                         */
/***************************************************************************/

//Saving debug information to a log file
void dprintf(const char *fmt, ...) 
{
 va_list parms;
 char buf[256];

 // Try to print in the allocated space.
 va_start(parms, fmt);
 vsprintf (buf, fmt, parms);
 va_end(parms);

 // Write the information out to a txt file
 FILE *fp = fopen("output.txt", "a+");
 fprintf(fp, "%s", buf);
 fclose(fp);

}// End dprintf(..)


 
/***************************************************************************/
/*                                                                         */
/ Entry Point                                                             /
/*                                                                         */
/***************************************************************************/


int __stdcall WinMain (HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmd, int nShow)
{

 // Create a jpg from a bmp
 //SaveJpgFile("smiley.bmp", "ex.jpg");

 // Create a bmp from a jpg
 ConvertJpgFile("smiley.jpg", "smiley.bmp");


 //ConvertJpgFile("cross.jpg", "cross.bmp");

 return 0;
}// End WinMain(..)
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
void CompressFile( FILE *input, BFILE *output, int quality ) 
{ 
int row; 
int col; 
int i; 
uchar *input_array[N]; 
int output_array[N][N]; 

if ( quality < 0 || quality > 50 ) 
return; 
Initialize( quality ); 
OutputBits( output, (ulong) quality, 8 ); 
for ( row = 0 ; row < ROWS ; row += N ) 
{ 
ReadPixelStrip( input, PixelStrip ); 
for ( col = 0 ; col < COLS ; col += N ) 
{ 
for ( i = 0 ; i < N ; i++ ) 
input_array[i] = PixelStrip[i] + col; 
ForwardDCT( input_array, output_array ); 
WriteDCTData( output, output_array ); 
} 
} 
OutputCode( output, 1 ); 
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
