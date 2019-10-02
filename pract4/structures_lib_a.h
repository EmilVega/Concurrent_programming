//============================================================================
//    Constantes  
//============================================================================


//=======================================================================================================================
//  DEFINICION DE ESTRUCTURAS VARIAS
//=======================================================================================================================
struct  pass_mesagge
	  {
           int  occupied;  
	   int  receiver;
	   int  sender;
	   int  amount;
       } message_simplex;
//---------------------------------------------------------------------------------------------------------
       
void attend_stream_1(void)
{
 int asigned_time;
 int amount, receiver;
    
  cout <<"Executing stream " << winner<<endl;   
    
   asigned_time=random(2)+1;       // minimo= 10ms,  max=60 ms  
     
  amount= random(11)-5;  //    Cantidad a enviar entre 5 a -5
  receiver=random(11); 

  if(!message_simplex.occupied)
     { 
      cout << "ready to send " << amount<<endl ;
      message_simplex.receiver=receiver;        
      message_simplex.sender=1;              
      message_simplex.amount=amount; 
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
 int amount, receiver;
    
  cout <<"Executing stream " << winner<<endl;   
    
   asigned_time=random(2)+1;       // minimo= 10ms,  max=60 ms  
     
  amount= random(11)-5;  //    Cantidad a enviar entre 5 a -5
  receiver=random(11); 
  
  if(!message_simplex.occupied)
     { 
      cout << "ready to send " << amount<<endl ;
      message_simplex.receiver=receiver;        
      message_simplex.sender=2;              
      message_simplex.amount=amount; 
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

void attend_stream_3(void)
{
 int asigned_time;
 int amount, receiver;
    
  cout <<"Executing stream " << winner<<endl;   
    
   asigned_time=random(2)+1;       // minimo= 10ms,  max=60 ms  
     
  amount= random(11)-5;  //    Cantidad a enviar entre 5 a -5
  receiver=random(11); 
  
  if(!message_simplex.occupied)
     { 
      cout << "ready to send " << amount<<endl ;
      message_simplex.receiver=receiver;        
      message_simplex.sender=3;              
      message_simplex.amount=amount; 
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

void attend_stream_4(void)
{
 int asigned_time;
 int amount, receiver;
    
  cout <<"Executing stream " << winner<<endl;   
    
   asigned_time=random(2)+1;       // minimo= 10ms,  max=60 ms  
     
  amount= random(11)-5;  //    Cantidad a enviar entre 5 a -5
  receiver=random(11); 
  
  if(!message_simplex.occupied)
     { 
      cout << "ready to send " << amount<<endl ;
      message_simplex.receiver=receiver;        
      message_simplex.sender=4;              
      message_simplex.amount=amount; 
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

void attend_stream_5(void)
{
 int asigned_time;
 int amount, receiver;
    
  cout <<"Executing stream " << winner<<endl;   
    
   asigned_time=random(2)+1;       // minimo= 10ms,  max=60 ms  
     
  amount= random(11)-5;  //    Cantidad a enviar entre 5 a -5
  receiver=random(11); 
  
  if(!message_simplex.occupied)
     { 
      cout << "ready to send " << amount<<endl ;
      message_simplex.receiver=receiver;        
      message_simplex.sender=5;              
      message_simplex.amount=amount; 
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

void attend_stream_6(void)
{
 int asigned_time;
 int amount, receiver;
    
  cout <<"Executing stream " << winner<<endl;   
    
   asigned_time=random(2)+1;       // minimo= 10ms,  max=60 ms  
     
  amount= random(11)-5;  //    Cantidad a enviar entre 5 a -5
  receiver=random(11); 
  
  if(!message_simplex.occupied)
     { 
      cout << "ready to send " << amount<<endl ;
      message_simplex.receiver=receiver;        
      message_simplex.sender=6;              
      message_simplex.amount=amount; 
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

void attend_stream_7(void)
{
 int asigned_time;
 int amount, receiver;
    
  cout <<"Executing stream " << winner<<endl;   
    
   asigned_time=random(2)+1;       // minimo= 10ms,  max=60 ms  
     
  amount= random(11)-5;  //    Cantidad a enviar entre 5 a -5
  receiver=random(11); 
  
  if(!message_simplex.occupied)
     { 
      cout << "ready to send " << amount<<endl ;
      message_simplex.receiver=receiver;        
      message_simplex.sender=7;              
      message_simplex.amount=amount; 
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

void attend_stream_8(void)
{
 int asigned_time;
 int amount, receiver;
    
  cout <<"Executing stream " << winner<<endl;   
    
   asigned_time=random(2)+1;       // minimo= 10ms,  max=60 ms  
     
  amount= random(11)-5;  //    Cantidad a enviar entre 5 a -5
  receiver=random(11); 
  
  if(!message_simplex.occupied)
     { 
      cout << "ready to send " << amount<<endl ;
      message_simplex.receiver=receiver;        
      message_simplex.sender=8;              
      message_simplex.amount=amount; 
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

void attend_stream_9(void)
{
 int asigned_time;
 int amount, receiver;
    
  cout <<"Executing stream " << winner<<endl;   
    
   asigned_time=random(2)+1;       // minimo= 10ms,  max=60 ms  
     
  amount= random(11)-5;  //    Cantidad a enviar entre 5 a -5
  receiver=random(11); 
  
  if(!message_simplex.occupied)
     { 
      cout << "ready to send " << amount<<endl ;
      message_simplex.receiver=receiver;        
      message_simplex.sender=9;              
      message_simplex.amount=amount; 
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

void attend_stream_10(void)
{
 int asigned_time;
 int amount, receiver;
    
  cout <<"Executing stream " << winner<<endl;   
    
   asigned_time=random(2)+1;       // minimo= 10ms,  max=60 ms  
     
  amount= random(11)-5;  //    Cantidad a enviar entre 5 a -5
  receiver=random(11); 
  
  if(!message_simplex.occupied)
     { 
      cout << "ready to send " << amount<<endl ;
      message_simplex.receiver=receiver;        
      message_simplex.sender=10;              
      message_simplex.amount=amount; 
      message_simplex.occupied=1;   
     }
  Sleep(asigned_time); 
  cout <<"the local capital is " << local_capital[winner]<<endl;
  cout <<"end stream  " << winner<<endl; 
  Sleep(master_delay);     //  to wacht in slow motion  
  cout << endl;  
  //gets(dummy);     
}