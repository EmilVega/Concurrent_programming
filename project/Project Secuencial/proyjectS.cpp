/* CONCURRENT PROJECT : Convolution matrix for images
Students: Maria F. Molina - Winter Morejon - Osiris Roman - Emil Vega*/


#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <iostream.h>
#include <time.h>
#include <windows.h>
#include <graphics.h>

#include "mMultiplication.h"
#include "loadImage.h"
#include "PRINT_MATRIX.h"


float mMultiplication(float[][3],float[][3]);
float f1[3][3]={{-1,0,1},{-1,0,1},{-1,0,1}};
float f2[3][3]={{-1,-1,-1},{0,0,0},{1,1,1}};
float f3[3][3]={{0,1,1},{-1,0,1},{-1,-1,0}};
float f4[3][3]={{1,1,0},{1,0,-1},{0,-1,-1}};
const int st =2;
char dummy[1];

float mResult[50][50];
float M[101][101];

void fill_matrix_result(void)         
{
  
  for(int i=0;i<matrix_row;i++)    
    {
		for(int j=0;j<matrix_column;j++)  
		{
            matrix_data[i][j]= mResult[i][j];
           
		}
	      
    }
}

void fill_matrix_origin(void)         
{
  
  for(int i=0;i<100;i++)   
    {
		for(int j=0;j<100;j++)   
		{
            matrix_data_origin[i][j]= M[i][j];
           
		}
	      
    }
}


void train(void)                                                 
{

    fill_matrix_result();
    fill_matrix_origin();     
    plot_matrix_data();  
    plot_matrix_data_origin();
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
    
    
    
   
   
    for(int i=0;i<fl;i++){
        for(int j=0;j<cl;j++){
            if (j==cl-1 || i==fl-1){ M[i][j]=0;}
           else{M[i][j]=matImg[i][j];}
        }
    }
    
    /*std:: cout<<"\n Matriz Original is: \n";
    for(int i=0;i<fl;i++){
        for(int j=0;j<cl;j++){
            std::cout<<M[i][j]<<" ";
        }
        std:: cout<<"\n";
    }
    
    gets(dummy);*/
    
    int f=0,c;
    for(int i=1;i<fl-1;i+=st){
        c =0;
        for(int j=1;j<cl-1;j+=st){           
            float subMatriz[3][3]={{M[i-1][j-1],M[i-1][j], M[i-1][j+1]},
                        {M[i][j-1],M[i][j], M[i][j+1]},
                        {M[i+1][j-1],M[i+1][j], M[i+1][j+1]}};
            float resultado1=mMultiplication(subMatriz,f1);
            float resultado2=mMultiplication(subMatriz,f2);
            float resultado3=mMultiplication(subMatriz,f3);
            float resultado4=mMultiplication(subMatriz,f4);
            mResult[f][c]=resultado1+resultado2+resultado3+resultado4;
            
            c++;
        }
        
        f++;
    }    
    
    /*std:: cout<<"\n Matriz resultante is: \n";
    for(int i=0;i<fl/2;i++){
        for(int j=0;j<cl/2;j++){
            std::cout<<mResult[i][j]<<" ";
        }
        std:: cout<<"\n";
    }
    
    gets(dummy);*/
   
    train(); 
    clrscr();
    
    getch();
  
}