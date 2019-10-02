/************************ top_eye_flop.cpp **********************************
Name:         CHAPLIN Shakira.cpp
codigo fuente base:   prof.    oscar  chang
August  2018
/*********************************************************************/
#define matrix_row     50
#define matrix_column  50
//---------   GLOBALs
/*float copy[10000][3];  //    matriz de las imagenes de entrada [numero de pixels] [numero de imagenes]
int picture_video;


float energy_band;
float energy_average;
int b_flag;
int blue_column;




int x_discharge_image;  //  coordenadas de la zona donde descargamos la imagen a ser analizada
int y_discharge_image;
int hidden_pointer; 

int winner_x, winner_y;

int x_barrido, y_barrido;

float matrix_data[matrix_row][matrix_column];  

float  main_barrier=0.1001;   */

int x_roi;     //   coordenadas de la posicion de la camara o roi, pequeña zona donde capturamos pixels 
int y_roi;     //
float cutter;
float matrix_data[matrix_row][matrix_column]; 
float matrix_data_origin[matrix_row*2][matrix_column*2]; 
//------------------------------------------
#include <stdlib.h>
//#include <graphics.h>
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>



using namespace std;


/******************* variables locales  ***************************************/
/*int  winner;           // contadores genericos

char color;

int trace_flag;


int picture_video_flag;
int plot_counter;*/

char key;
int  x,y;
int  xd,yd,alfa;
int stop;
//-------------------------------------
//    inicia el modo grafico             
//-------------------------------------    
void grafico(void)
{
    int    GraphDriver;  /* The Graphics device driver */
    int    GraphMode;    /* The Graphics mode value */
    int    ErrorCode;    /* Reports any graphics errors */
   
    initgraph(&GraphDriver, &GraphMode, "");

    ErrorCode = graphresult();            /* Read result of initialization*/
    if( ErrorCode != grOk )              /* Error occured during init    */
    {
       printf(" Graphics System Error: %s", grapherrormsg( ErrorCode ) );
       exit( 1 );
    }
}
//--------------------------------------------------------------

void plot_matrix_data(void)                                                    // PLOT GIANT CELL
{
 int i,j,k,sx,sy,counter, scale,color,x,y; 
 int x_matrix, y_matrix;   
 float timp; 
    
 //x_matrix=60;
 y_matrix=50; 
    
  
   scale=5;
  
     for(j=0;j<matrix_row;j++)  //  22
     { 
      sy = y_matrix+j*scale+j;  
      x_matrix=10;   
      for(i=0;i<matrix_column;i++)   // 10
         {    
          sx = x_matrix+i*scale+i;
          timp= matrix_data[j][i];    
          //timp= Entrada[counter];  
          color=WHITE;   
          if(timp==0) color=LIGHTGRAY;        // fROZEN
          if(timp>0) color=WHITE;
          if(timp<0) color=DARKGRAY;      
          /*if(timp==0) color=LIGHTGRAY;        // fROZEN
          if(timp>0) color=DARKGRAY;
          if(timp<0) color=WHITE;*/
          setcolor(color); 
          //setcolor(GREEN); 
          setfillstyle(SOLID_FILL,color); 
          bar(sx,sy,sx+scale,sy+scale) ;
          //putpixel(sx,sy, color);      
          //if(i==10) x_matrix=x_matrix+10;
         }
     } 
         
    
}
//--------------------------------------------------------------------------

void plot_matrix_data_origin(void)                                                    // PLOT GIANT CELL
{
 int i,j,k,sx,sy,counter, scale,color,x,y; 
 int x_matrix, y_matrix;   
 float timp; 
    
// x_matrix=60;
 y_matrix=50; 
    
  
   scale=2;
  
     for(j=0;j<100;j++)  //  22
     { 
      sy = y_matrix+j*scale+j;  
      x_matrix=320;   
      for(i=0;i<100;i++)   // 10
         {    
          sx = x_matrix+i*scale+i;
          timp= matrix_data_origin[j][i];    
          //timp= Entrada[counter];  
          color=WHITE;   
          if(timp==0.5) color=LIGHTGRAY;        // fROZEN
          if(timp>0.5) color=WHITE;
          if(timp<0.5) color=DARKGRAY;                
          setcolor(color); 
          //setcolor(GREEN); 
          setfillstyle(SOLID_FILL,color); 
          bar(sx,sy,sx+scale,sy+scale) ;
          //putpixel(sx,sy, color);      
          //if(i==10) x_matrix=x_matrix+10;
         }
     } 
         
    
}


//---------------------------------------------
/*void fill_matrix(void)         //              **    PUMP_FIFO_M   **    
{
  int i,j,k;
  float temp;

  j=matrix_row-2;  

   
  for(i=0;i<matrix_row;i++)    //   matrix_row=10
    {
		for(j=0;j<matrix_column;j++)   //  matrix_column=22
		{
            k=random(3);
            if(k==0) matrix_data[i][j]= 0.0;
            if(k==1) matrix_data[i][j]= 0.5;
            if(k==2) matrix_data[i][j]= -0.5;    
			
		}
	      
    }
}*/
//--------------------------------------------------------------





//--------------------------------------------------------

/*void train(void)  //                                                  TRAIN                          ***************                                                                                                                      TRAIN  !!
{

   while(1)
    {  
    
         
     fill_matrix_true();  
     plot_matrix_data();                     //   plot space matrix
         
     Sleep(10); 
     if(stop)break;
     if(kbhit()) break;
  
    }
}  */
//===================================================================================================
/*void main(void)
{ 
 int i;  
    x=xd=300;
    y=yd= 430;
    alfa=90;                  //     posicion inicial de la camara
    clrscr();                   // limpia la pantalla
    grafico();                   // prepara modo grafico
    cleardevice();               // lkimpia la pantalla windows
    floodfill(x,y,WHITE);
   
    cutter=0.38;                 // 18    unbral para B&W
   
    
    x_roi=320;
    y_roi=270;
  
    train();   
    
    do {
       //play_flag=0; 
       key=getch();
       switch (key) {
                       
            
    
                               
         }
   } while ((key!='x')&&(key!='X'));

   closegraph();
   clrscr();
}*/

//---------------------------------------
/*
BLACK        ³  0  ³ Yes ³ Yes
BLUE         ³  1  ³ Yes ³ Yes
GREEN        ³  2  ³ Yes ³ Yes
CYAN         ³  3  ³ Yes ³ Yes
RED          ³  4  ³ Yes ³ Yes
MAGENTA      ³  5  ³ Yes ³ Yes
BROWN        ³  6  ³ Yes ³ Yes
LIGHTGRAY    ³  7  ³ Yes ³ Yes
DARKGRAY     ³  8  ³ No  ³ Yes
LIGHTBLUE    ³  9  ³ No  ³ Yes
LIGHTGREEN   ³ 10  ³ No  ³ Yes
LIGHTCYAN    ³ 11  ³ No  ³ Yes
LIGHTRED     ³ 12  ³ No  ³ Yes
LIGHTMAGENTA ³ 13  ³ No  ³ Yes
YELLOW       ³ 14  ³ No  ³ Yes
WHITE        ³ 15  ³ No  ³ Yes

----------------------------------------------------------------
     if(x<0)    { x=0; if( heat<100) heat++;}     
     if(y<35)    { y=35; if( heat<100) heat++;}  
     if(x>640) { x=640; if( heat<100) heat++;}  //  x>1200 : full pantalla 
     if(y>470) { y=470; if( heat<100) heat++;}   // y>720 : full pantalla 
         
//--------------------------------------------------

************************ basic_robot.cpp ***************************
desarrollado usando Dev-C++ IDE V4.9.8.4 GNU / MinGW / GNU gcc
                    Sc1 IDE / BCC5.5
                    version orginal por Oscar Chang
*********************************************************************/

