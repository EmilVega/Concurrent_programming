//        GLOBALS   -------------------

 char comm_1[] = "ls";
 char comm_2[] = "clear";
 char comm_3[] = "quit";
//-----------------------------------------------
#include <stdlib.h>
//#include <graphics.h>
//#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <string.h>
//#include <windows.h>

using namespace std;  
char dummy[1];
char buffer[80];
int  quit_flag;
//---------------------------------------
void list_files(void)
{
 int i;
    
  for(i=0;i<10;i++)
    {
      cout << "file " << i; 
      cout << endl;         
    } 
 
} 
//---------------------------------------
void clear_screen(void)
{
    system("cls");
} 
//---------------------------------------

void command_analyzer(void) 
{
 int valid_flag;

      valid_flag=0;  
      if(!strcmp(comm_1,buffer)) {list_files();valid_flag=1;}
      
      if(!strcmp(comm_2,buffer)) {clear_screen();valid_flag=1;}
      
      if(!strcmp(comm_3,buffer)) {quit_flag=1;valid_flag=1;}
          
      if(!valid_flag) cout << "command not found--"; 
           
}

//----------------------------------------
main()
{
   quit_flag=0;    
    
   do {
       
       cout << endl; 
       cout << "YOP_Version_3.0-$$:";
       fgets(buffer,80,stdin);   
       command_analyzer();
       if(quit_flag) break;
       
      } while (1); 
}

//--------------------------------------------------------
