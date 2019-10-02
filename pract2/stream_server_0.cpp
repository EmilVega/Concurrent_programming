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
//-----------------------------------------------
#include <stdlib.h>
//#include <graphics.h>
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <iostream.h>
#include <time.h>
#include <windows.h>

#include "structures_lib.H" 

//#include "structures_lib.h" 

//using namespace std;  
char dummy[1];
char buffer[80];
int  quit_flag;
int repeat_flag;
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
    
    receiver =message.receiver[0];         //  receiver
    sender =message.sender[0];           //  sender                      MOV A,B   content of B is move to A      
    amount =message.amount[0];          // max transaction allowed =  +7  a  -7
    
    local_capital[sender]= local_capital[sender] - amount;
    
    local_capital[receiver]=local_capital[receiver] + amount;    

    cout <<endl << "transaction done for " << amount<<endl;
    
    total_transactions++;    
}
//-------------------------
void get_circulatig_capital(void) 
{
 int i;
        total_circulating_capital=0;  // total_circulating_capital
        for(i=0;i<10;i++) total_circulating_capital=total_circulating_capital+local_capital[i];  
        cout <<endl << "total_circulating_capital " << total_circulating_capital <<endl;  
        cout <<endl << "total_initial_capital " << total_initial_capital <<endl; 
        
        //cout <<endl << "total_initial_capital " << total_initial_capital<<endl;                                             total_initial_capital        
}

//-------------------------
void attend_stream_0(void)
{
 int asigned_time;

  asigned_time=random(101)+100;     // minimo= 100ms,  max=200 ms  
  cout << endl;  
    
  cout << "Executing stream " << winner<< endl ;  
  
      
    
  //if (repeat_flag==0){
  //    cout<< endl<< "TRANSACTION REPEATED"<<endl; 
  //}else{
  //    repeat_flag=0;
  //}
  
  if (message.occupied[0]==1){
    transaction_0();
    message.occupied[0]=0;
    get_circulatig_capital();  
    
    Sleep(asigned_time); 
  
    cout <<endl << "The sender is " << message.sender[0] <<"     The receiver is " << message.receiver[0]<<endl;
    cout <<endl << "the local capital is " << local_capital[winner]<< endl;
    cout <<endl << "total transactions " << total_transactions << endl;  
                                             
    cout << endl<< "end stream  " << winner; 
      
  }else{
    cout<<endl<<"TRANSACTION NOT DONE" << endl; 
  }  
  
  
    
  Sleep(master_delay);     //  to wacht in slow motion  
    
  Sleep(1000);  
  gets(dummy);     
  cout << endl;     
} 
//---------------------------------------
void attend_stream_1(void)
{
 int asigned_time;
 int amount_1, receiver_1, sender;
    
  cout << endl << "Executing stream " << winner << endl;   
    
  asigned_time=random(100)+100;     // minimo= 10ms,  max=60 ms  
     
  amount_1= random(11)-5;  //    Cantidad a enviar entre 5 a -5
  receiver_1=random(10);
  sender=1;
    
  

  if(!message.occupied[0]){
      
      cout <<endl << "ready to send " << amount_1;
      message.receiver[0]=receiver_1;
      message.sender[0]=sender;
      message.amount[0]=amount_1;
      // repeat_flag=1;
      message.occupied[0]=1;
  } else{
      cout<<endl<<"PENDING TRANSACTION"<<endl;
  }
  
  Sleep(asigned_time); 
  cout <<endl << "the local capital is " << local_capital[winner];
  cout << endl<< "end stream  " << winner; 
  Sleep(master_delay);     //  to wacht in slow motion  
  cout << endl;  
  gets(dummy);     
} 
//---------------------------------------
void attend_stream_2(void)
{
 int asigned_time;
 int amount_2, receiver_2;
    
  asigned_time=random(100)+100;     // minimo= 10ms,  max=60 ms  
  cout << endl;  
  cout << "Executing stream " << winner<< endl;  
   
  
  amount_2= random(11)-5;  //    Cantidad a enviar entre 5 a -5
  receiver_2=random(10);
    
  if(!message.occupied[0]){
      
      cout <<endl << "ready to send " << amount_2;
      message.receiver[0]=receiver_2;
      message.sender[0]=2;
      message.amount[0]=amount_2;
      // repeat_flag=1;
      message.occupied[0]=1;
  } else{
      cout<<endl<<"PENDING TRANSACTION"<<endl;
  }
  
  Sleep(asigned_time);
      
  cout <<endl << "the local capital is " << local_capital[winner];
  cout << endl<< "end stream  " << winner; 
  Sleep(master_delay);     //  to wacht in slow motion  
  cout << endl;
  gets(dummy);  
} 
//---------------------------------------
void attend_stream_3(void)
{
 int asigned_time;
 int amount_3, receiver_3;

  asigned_time=random(100)+100;     // minimo= 10ms,  max=60 ms  
  cout << endl;  
  cout << "Executing stream " << winner<<endl;

  amount_3= random(11)-5;  //    Cantidad a enviar entre 5 a -5
  receiver_3=random(10);
    
  if(!message.occupied[0]){
      
      cout <<endl << "ready to send " << amount_3;
      message.receiver[0]=receiver_3;
      message.sender[0]=3;
      message.amount[0]=amount_3;
      // repeat_flag=1;
      message.occupied[0]=1;
  } else{
      cout<<endl<<"PENDING TRANSACTION"<<endl;
  }
    
  Sleep(asigned_time); 
  cout <<endl << "the local capital is " << local_capital[winner];
  cout << endl<< "end stream  " << winner; 
  Sleep(master_delay);     //  to wacht in slow motion  
  cout << endl;     
  gets(dummy);
} 

//----------------------------------------
//    LOOP
//----------------------------------------
void stream_server(void) 
{
   do {
       winner=random(10);
       //cout << endl; 
       //cout << "winner " << winner; 
       system("cls");
       if(winner==0) attend_stream_0();
       if(winner==1) attend_stream_1();
       if(winner==2) attend_stream_2();
       if(winner==3) attend_stream_3();    
             
       Sleep(100);
       if(quit_flag) break;
       
      } while (1); 
           
}
//----------------------------------------
main()
{
 int i;  

   for(i=0;i<10;i++) local_capital[i]=random(101); 
   total_initial_capital=0;
   for(i=0;i<10;i++) total_initial_capital=total_initial_capital+local_capital[i];   
   //quit_flag=0; 
   
   master_delay=1000;
   cout << "stream_server_version_1.0"<<endl; 
   stream_server(); 
  
}

//--------------------------------------------------------