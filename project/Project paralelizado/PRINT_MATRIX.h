/************************ top_eye_flop.cpp **********************************
Name:         CHAPLIN Shakira.cpp
codigo fuente base:   prof.    oscar  chang
August  2018
/*********************************************************************/
#define matrix_row     50
#define matrix_column  50
//---------   GLOBALs


int x_roi;     //   coordenadas de la posicion de la camara o roi, pequeña zona donde capturamos pixels 
int y_roi;     //
float cutter;
float matrix_data[matrix_row][matrix_column]; 
float matrix_data_origin[matrix_row*2][matrix_column*2]; 
//------------------------------------------
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>



using namespace std;


/******************* variables locales  ***************************************/


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
  
     for(j=0;j<matrix_row;j++)  
     { 
      sy = y_matrix+j*scale+j;  
      x_matrix=10;   
      for(i=0;i<matrix_column;i++)  
         {    
          sx = x_matrix+i*scale+i;
          timp= matrix_data[j][i];    
          //timp= Entrada[counter];  
          color=WHITE;   
          if(timp==0) color=LIGHTGRAY;        
          if(timp>0) color=DARKGRAY;
          if(timp<0) color=WHITE;                
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
    

 y_matrix=50; 
    
  
   scale=2;
  
     for(j=0;j<100;j++)  
     { 
      sy = y_matrix+j*scale+j;  
      x_matrix=320;   
      for(i=0;i<100;i++) 
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

