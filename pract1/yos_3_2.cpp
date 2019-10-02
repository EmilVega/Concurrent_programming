//        GLOBALS   -------------------

 char comm_1[] = "ls";
 char comm_2[] = "clear";
 char comm_3[] = "quit";
 char comm_4[] = "run/hello-world";
//-----------------------------------------------
#include <stdlib.h>
//#include <graphics.h>
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <iostream.h>
#include <time.h>
//#include <windows.h>
#include <dirent.h>

using namespace std;  
char dummy[1];
char buffer[80];
int  quit_flag;
//---------------------------------------
void list_files(void)
{
 DIR *dir;
 struct dirent *ent;
 dir = opendir(".");
 if (dir == NULL) 
    cout <<"No puedo abrir el directorio";
 while ((ent = readdir (dir)) != NULL) 
    {
      /* Nos devolverá el directorio actual (.) y el anterior (..), como hace ls */
      std::cout << ent->d_name << '\n';
    }
 closedir (dir);
 
} 
//---------------------------------------
void clear_screen(void)
{
    system("cls");
} 
//---------------------------------------

void run(void)
{
    cout << "HELLO WORLD";
} 
//---------------------------------------


void command_analyzer(void) 
{
 int valid_flag;

      valid_flag=0;  
      if(!strcmp(comm_1,buffer)) {list_files();valid_flag=1;}
      
      if(!strcmp(comm_2,buffer)) {clear_screen();valid_flag=1;}
      
      if(!strcmp(comm_3,buffer)) {quit_flag=1;valid_flag=1;}
      
      if(!strcmp(comm_4,buffer)) {run();valid_flag=1;}
          
      if(!valid_flag) cout << "command not found--"; 
           
}

//----------------------------------------
main()
{
   quit_flag=0;    
    
   do {
       
       cout << endl; 
       cout << "YOP_Version_3.0-$$:";
       gets(buffer);   
       command_analyzer();
       if(quit_flag) break;
       
      } while (1); 
}

//--------------------------------------------------------