//--------------------------
//Practica 1
// sistema operativo basico
// Prof Oscar Chang
//--------------------------//        GLOBALS   -------------------
#define number_of_participants 10;

 char comm_1[] = "ls";
 char comm_2[] = "clear";
 char comm_3[] = "quit";
 
 int local_capital[10];
 int total_initial_capital;
 int total_circulating_capital;
 int winner;
 int total_transactions;
 int cycles_count;
//-----------------------------------------------
#include <stdlib.h>
//#include <graphics.h>
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <iostream.h>
#include <time.h>
#include <windows.h>

#include "structures_lib_a.H" 

//#include "structures_lib.h" 

//using namespace std;  
char dummy[1];
char buffer[80];
int  quit_flag;
//---------------------------------------
int master_delay;
//--------------------------------------

void clear_screen(void)
{
    system("cls");
} 
//---------------------------------------

void command_analyzer(void) 
{
 int valid_flag;

            
      if(!valid_flag) cout << "command not found--"; 
           
}
//--------------------------------------
void transaction_0(void)                        //         TRANSACTION 0
{
 int i,j,k;
 int receiver, sender, amount;
     
    //    MOV  CAP [receiver], CAP[sender]                  sender-> receiver
    
    receiver =message_simplex.receiver;        
    sender =message_simplex.sender;               
    amount =message_simplex.amount ;           
    
    local_capital[sender]= local_capital[sender] - amount;
    
    local_capital[receiver]=local_capital[receiver] + amount;    

    cout <<"transaction done for " << amount<<endl;
    cout <<"sender " << message_simplex.sender<<"--receiver "<<message_simplex.receiver<< endl;
    total_transactions++;    
}
//-------------------------
void get_circulatig_capital(void) 
{
 int i;
        total_circulating_capital=0;  // total_circulating_capital
        for(i=0;i<10;i++) total_circulating_capital=total_circulating_capital+local_capital[i];  
        cout <<"total_circulating_capital " << total_circulating_capital <<endl;  
        cout <<"total_initial_capital " << total_initial_capital <<endl; 
        
        //cout <<endl << "total_initial_capital " << total_initial_capital<<endl;                                             total_initial_capital        
}

//-------------------------
void attend_stream_0(void)
{
 int asigned_time;

  asigned_time=random(101)+100;     // minimo= 100ms,  max=200 ms  
     
  cout << "Executing stream " << winner<< endl ;  
  if(message_simplex.occupied==1) {transaction_0();message_simplex.occupied=0;} 
    
  get_circulatig_capital();  
    
  Sleep(asigned_time); 
   
  cout <<"the local capital is " << local_capital[winner]<< endl;
  cout <<"total transactions " << total_transactions << endl; 
  cout <<"cycles_count " << cycles_count << endl;  
  
  double efficiency = (double)total_transactions / (double) cycles_count;

  cout <<"Efficiency " << efficiency << endl;  
                                             
  cout <<"end stream  " << winner<<endl; 
    
  Sleep(master_delay);     //  to wacht in slow motion  
    
  Sleep(1);
  if (total_transactions==100) gets(dummy);     
} 
//---------------------------------------
void attend_stream_1(void)
{
 int asigned_time;
 int amount_1, receiver_1, sender;
    
  cout <<"Executing stream " << winner<<endl;   
    
  asigned_time=random(100)+100;     // minimo= 10ms,  max=60 ms  
     
  amount_1= random(11)-5;  //    Cantidad a enviar entre 5 a -5
  receiver_1=random(4);
  sender=1;   

  if(!message_simplex.occupied)
     { 
      cout << "ready to send " << amount_1<<endl ;
      message_simplex.receiver=receiver_1;        
      message_simplex.sender=1;              
      message_simplex.amount=amount_1; 
      message_simplex.occupied=1;
     }
  Sleep(asigned_time); 
  cout <<"the local capital is " << local_capital[winner]<<endl;
  cout <<"end stream  " << winner<<endl; 
  Sleep(master_delay);     //  to wacht in slow motion  
  cout << endl;  
  //gets(dummy);     
} 
//---------------------------------------
void attend_stream_2(void)
{
 int asigned_time;
 int amount_2, receiver_2;

  asigned_time=random(100)+100;     // minimo= 10ms,  max=60 ms  
  cout << "Executing stream " << winner<< endl;;  
    
  amount_2= random(11)-5;  //    Cantidad a enviar entre 5 a -5
  receiver_2=random(4);

  if(!message_simplex.occupied)
     { 
      cout << "ready to send " << amount_2<<endl ;
      message_simplex.receiver=receiver_2;        
      message_simplex.sender=2;              
      message_simplex.amount=amount_2; 
      message_simplex.occupied=1;
     }
    
  Sleep(asigned_time); 
  cout <<"the local capital is " << local_capital[winner]<<endl;
  cout <<"end stream  " << winner<<endl;; 
  Sleep(master_delay);     //  to wacht in slow motion  
  cout << endl;     
} 
//---------------------------------------
void attend_stream_3(void)
{
 int asigned_time;
 int amount_3, receiver_3;

  asigned_time=random(100)+100;     // minimo= 10ms,  max=60 ms  
  cout << "Executing stream " << winner;  
    
  amount_3= random(11)-5;  //    Cantidad a enviar entre 5 a -5
  receiver_3=random(4);

  if(!message_simplex.occupied)
     { 
      cout << "ready to send " << amount_3<<endl ;
      message_simplex.receiver=receiver_3;        
      message_simplex.sender=3;              
      message_simplex.amount=amount_3; 
      message_simplex.occupied=1;
     }
    
  Sleep(asigned_time); 
  cout <<"the local capital is " << local_capital[winner]<< endl;
  cout <<"end stream  " << winner<< endl; 
  Sleep(master_delay);     //  to wacht in slow motion  
  cout << endl;     
} 

//----------------------------------------
//    LOOP
//----------------------------------------
void stream_server(void) 
{
   do {
       winner=random(20);
       //cout << endl; 
       //cout << "winner " << winner; 
       system("cls");
                    
       if(winner==0) attend_stream_0();
       if(winner==1) attend_stream_1();
       if(winner==2) attend_stream_2();
       if(winner==3) attend_stream_3(); 
       if(winner>10) attend_stream_0();
             
       //Sleep(100);
       cycles_count++;
       if(quit_flag) break;
       
      } while (1); 
           
}
//----------------------------------------
main()
{
 int i;  
    
   randomize();

   for(i=0;i<10;i++) local_capital[i]=random(101); 
   total_initial_capital=0;
   for(i=0;i<10;i++) total_initial_capital=total_initial_capital+local_capital[i];   
   //quit_flag=0; 
   cycles_count=0;
   master_delay=1;
   cout << "stream_server_version_1.0"<<endl; 
   stream_server(); 
  
}

//--------------------------------------------------------
