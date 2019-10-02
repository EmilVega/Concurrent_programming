//--------------------------
//Practica 1
// sistema operativo basico
// Prof Oscar Chang
//--------------------------//        GLOBALS   -------------------
#define number_of_participants 10;

//~ char comm_1[] = "ls";
//~ char comm_2[] = "clear";
//~ char comm_3[] = "quit";

 
 int local_capital[10];
 int total_initial_capital;
 int total_circulating_capital;
 int winner;
 int total_transactions;
 int cycles_count;
 
 float efficiency;
 int master_delay;
 
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

//--------------------------------------

void clear_screen(void)
{
    system("cls");
} 
//---------------------------------------

//~ void command_analyzer(void) 
//~ {
 //~ int valid_flag;

            
      //~ if(!valid_flag) cout << "command not found--"; 
           
//~ }
//--------------------------------------
void transaction_0(void)                        //         TRANSACTION 0
{
 //int i,j,k;
 int receiver, sender, amount;
 float tran,cic;   
     
    //    MOV  CAP [receiver], CAP[sender]                  sender-> receiver
    
    receiver =message_simplex.receiver;        
    sender =message_simplex.sender;               
    amount =message_simplex.amount ;           
    
    local_capital[sender]= local_capital[sender] - amount;
    local_capital[receiver]=local_capital[receiver] + amount;    
    total_transactions++; 
    
    tran=total_transactions;
    cic=cycles_count;
    
    efficiency=tran/cic;
    cout <<"transaction done for " << amount<<endl;
    cout <<"sender " << message_simplex.sender<<"--receiver "<<message_simplex.receiver<< endl;
    cout <<"efficiency " << efficiency<<endl;  
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
 int asigned_time, local_flag;
 //float efficiency, trans, cic;   
 float trans, cic; 
  asigned_time=random(2)+1;     // minimo= 100ms,  max=200 ms  
     
  cout << "Executing stream " << winner<< endl ;  
  local_flag=0;  
  if(message_simplex.occupied==1) {transaction_0();message_simplex.occupied=0;local_flag=1;} // OJO THERE WAS A BUG ;
    
  get_circulatig_capital();  
    
  Sleep(asigned_time); 
  
  trans=total_transactions;
  cic=cycles_count;
  efficiency=trans/cic;
   
  cout <<"the local capital is " << local_capital[winner]<< endl;
  cout <<"total transactions " << total_transactions << endl; 
  cout <<"cycles_count " << cycles_count << endl;   
                                             
  cout <<"end stream  " << winner<<endl; 
    
  Sleep(master_delay);     //  to wacht in slow motion  
    
  if(local_flag) Sleep(5);  
  //gets(dummy);     
} 
//---------------------------------------
//    LOOP
//----------------------------------------
void stream_server(void) 
{
 int base;   
   do {
       if(message_simplex.occupied)base=30;
       else base=11;
           
       winner=random(base);
       //cout << endl; 
       //cout << "winner " << winner; 
       system("cls");
       if(winner==0) attend_stream_0();
       if(winner>10)  attend_stream_0();   
           
       if(winner==1) attend_stream_1();
       if(winner==2) attend_stream_2();
       if(winner==3) attend_stream_3(); 
       if(winner==4) attend_stream_4(); 
       if(winner==5) attend_stream_5(); 
       if(winner==6) attend_stream_6();         
       if(winner==7) attend_stream_7();     
       if(winner==8) attend_stream_8(); 
       if(winner==9) attend_stream_9();         
       if(winner==10) attend_stream_10();
       
       //Sleep(100);
       cycles_count++;
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
   cycles_count=0;
   master_delay=1;
   cout << "stream_server_version_1.0"<<endl; 
   stream_server(); 
  
}

//--------------------------------------------------------
