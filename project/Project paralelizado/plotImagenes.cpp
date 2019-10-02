#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <iostream.h>
#include <time.h>
#include <windows.h>
#include <graphics.h>

#include "loadImage2.h"
#include "PRINT_MATRIX.h"



char dummy[1];


float M[101][101];

void fill_matrix_result(void)         //              **    PUMP_FIFO_M   **    
{
  
  for(int i=0;i<matrix_row;i++)    //   matrix_row=10
    {
		for(int j=0;j<matrix_column;j++)   //  matrix_column=22
		{
            matrix_data[i][j]= mResult[i][j];
           
		}
	      
    }
}

void fill_matrix_origin(void)         //              **    PUMP_FIFO_M   **    
{
  
  for(int i=0;i<100;i++)    //   matrix_row=10
    {
		for(int j=0;j<100;j++)   //  matrix_column=22
		{
            matrix_data_origin[i][j]= M[i][j];
           
		}
	      
    }
}


void train(void)  //                                                  TRAIN                          ***************                                                                                                                      TRAIN  !!
{

    fill_matrix_result();
    fill_matrix_origin();     
    plot_matrix_data();  
    plot_matrix_data_origin();
    
  /* while(1)
    {  
    
         
     fill_matrix_true();  
     plot_matrix_data();                     //   plot space matrix
         
     Sleep(10); 
     if(stop)break;
     if(kbhit()) break;
  
    }*/
} 

main()
{
 
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
    
    
    cargarImagenes();
    
    const int fl =  (sizeof matImg / sizeof matImg[0])+1;
    const int cl=   (sizeof matImg[0] / sizeof(int))+1; 
    
    
    cargarResul();
   
   
    for(int i=0;i<fl;i++){
        for(int j=0;j<cl;j++){
            if (j==cl-1 || i==fl-1){ M[i][j]=0;}
           else{M[i][j]=matImg[i][j];}
        }
    }

    
    // -------------------- del main de print matrix
    
   
    train(); 
    clrscr();
    
    getch();
  
}