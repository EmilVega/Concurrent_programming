//  Program base for hash algorithm
//  Prof Oscar Chang
//  February  2018
//-----------------------------------
//    GLOBALS

#define text_length 80
char dummy[10];
char key;
unsigned char ascii = (unsigned char)'a';
//-----------------------------------
#include <stdlib.h>
//#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
//#include <windows.h>
#include <string.h>
//#include <boost/utility/binary.hpp>
//--------------------------------
using namespace std;
//-----------------------------------
char hex_number[]= "0123456789abcdef";
//-----------------------------------
void analize_command(void)
{
 int valid_flag;

      valid_flag=0;
      //key=dummy[1];
      switch (dummy[0])
           {
            case 'a':          {
                                cout << endl;
                                cout << "command <a> executed:";
                                valid_flag=1;
                               }
            break;

            case 'z':          {
                                cout << endl;
                                cout << "command <z> executed:";
                                valid_flag=1;
                               }
            break;
           }

        cout << endl;
        if(!valid_flag) cout << "command--"<< dummy[0]<< "--no found";

}
//-----------------------------------
//        MAIN
//----------------------------------
int main()
{
   char plaintext[80];
   system("cls");


loop1:

   cout << "YOP_Version_1.0-$$:";


   
   fgets(dummy,10,stdin);
   //gets(dummy);            //   get string
   analize_command();
   cout << endl;
   goto loop1;

}

/*

     int hash_frame[]= {15,14,13,12,11,10,1,2,3,4};
    for(i=0;i<10;i++)cout << hash_frame[i]<<" ";  //  imprime hash en digital

    for(i=0;i<10;i++)cout << hex_number[hash_frame[i]]; //  imprime hash en HEX
    cout << endl;



"Splitting into nibbles" usually means 0x3B >4 (to get the upper
nibble) and 0x3B & 0xF (to get the lower nibble).

*/
