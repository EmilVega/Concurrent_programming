#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <iostream.h>
#include <time.h>
#include <windows.h>

const int fl=11;
const int cl=11;

float M[fl][cl];



float f1[3][3]={{-1,0,1},{-1,0,1},{-1,0,1}};
int f2[3][3]={{-1,-1,-1},{0,0,0},{1,1,1}};
int f3[3][3]={{0,1,1},{-1,0,1},{-1,-1,0}};
int f4[3][3]={{1,1,0},{1,0,-1},{0,-1,-1}};

const int st =2;
float mAux[3][3];
float mResult[25][25];

char dummy[1];


float sum=0;

/*
//PARA RECORRER LAS MATRICES
int i,j;
//DEFINIR TAMAÑO DE LAS MATRICES
int row,column;
//VARIABLE RESULTADO FINAL
int result;
//DEFINIR LAS MATRICES
int A[row][column]={//AQUI VAN LOS VALORES DE LA MATRIZ 1};
int B[row][column]={//AQUI VAN LOS VALORES DE LA MATRIZ 2};
int C[row][column]={0};

for(i=0; i<row; i++){
	for(j=0; j<column; j++){
		C[i][j]=A[i][j]*B[i][j];
	}
}
for(i=0; i<row; i++){
	for(j=0; j<column; j++){
		result+=C[i][j];
	}
}
*/
main()
{
    
    
    //randonmize();
    for(int i=0;i<fl;i++){
        for(int j=0;j<cl;j++){
            if (j==cl-1 || i==fl-1){ M[i][j]=0;}
           else{M[i][j]=rand()%9;}
            
        }
    }
    
    /*std::cout<<"Imprimiendo Matriz original \n";
    
    for(int i=0;i<fl;i++){
        for(int j=0;j<cl;j++){
           
            std::cout<<M[i][j]<<" ";
           
        }
        std:: cout<<"\n";
    }
    
    std::cout<<"\n";*/
    

    
    int f=0,c;
    for(int i=1;i<fl-1;i=i+st){
        
        c =0;
        for(int j=1;j<cl-1;j=j+st){
           
           
            float m1[3][3]={{M[i-1][j-1]*f1[0][0],M[i-1][j]*f1[0][1], M[i-1][j+1]*f1[0][2] },
                        {M[i][j-1]*f1[1][0],M[i][j]*f1[1][1], M[i][j+1]*f1[1][2] },
                        {M[i+1][j-1]*f1[2][0],M[i+1][j]*f1[2][1], M[i+1][j+1] *f1[2][2]}};
            
           float m2[3][3]={{M[i-1][j-1]*f2[0][0],M[i-1][j]*f2[0][1], M[i-1][j+1]*f2[0][2] },
                        {M[i][j-1]*f2[1][0],M[i][j]*f2[1][1], M[i][j+1]*f2[1][2] },
                        {M[i+1][j-1]*f2[2][0],M[i+1][j]*f2[2][1], M[i+1][j+1] *f2[2][2]}};
                            
           float m3[3][3]={{M[i-1][j-1]*f3[0][0],M[i-1][j]*f3[0][1], M[i-1][j+1]*f3[0][2] },
                        {M[i][j-1]*f3[1][0],M[i][j]*f3[1][1], M[i][j+1]*f3[1][2] },
                        {M[i+1][j-1]*f3[2][0],M[i+1][j]*f3[2][1], M[i+1][j+1] *f3[2][2]}};
                            
           float m4[3][3]={{M[i-1][j-1]*f4[0][0],M[i-1][j]*f4[0][1], M[i-1][j+1]*f4[0][2] },
                        {M[i][j-1]*f4[1][0],M[i][j]*f4[1][1], M[i][j+1]*f4[1][2] },
                        {M[i+1][j-1]*f4[2][0],M[i+1][j]*f4[2][1], M[i+1][j+1] *f4[2][2]}};
            
           /* std::cout<<"\nImprimiendo filtro 1 \n";
            for(int k=0;k<3;k++){
                for(int l=0;l<3;l++){
                    
                std::cout<<m1[k][l]<<" ";
                }
                std::cout<<"\n";
            }
            
            std::cout<<"\nImprimiendo filtro 2 \n";
            for(int k=0;k<3;k++){
                for(int l=0;l<3;l++){
                    
                std::cout<<m2[k][l]<<" ";
                }
                std::cout<<"\n";
            }
            
            std::cout<<"\nImprimiendo filtro 3 \n";
            for(int k=0;k<3;k++){
                for(int l=0;l<3;l++){
                    
                std::cout<<m3[k][l]<<" ";
                }
                std::cout<<"\n";
            }
            
            std::cout<<"\nImprimiendo filtro 4 \n";
            for(int k=0;k<3;k++){
                for(int l=0;l<3;l++){
                    
                std::cout<<m4[k][l]<<" ";
                }
                std::cout<<"\n";
            }
            
             std::cout<<"\n";*/
            
            float result=0;
            int row=3,column=3;
            for(int h=0; h<row; h++){
                for(int k=0; k<column; k++){
                    result=result+m1[h][k]+m2[h][k]+m3[h][k]+m4[h][k];
                }
                
            }
            /*std:: cout<<"\n result is: "<<result;
            std:: cout<<"\n I is: "<<i<<" J: "<<j;
            
            
            
             std:: cout<<"\n F is: "<<f<<" C: "<<c;           
            
            
            std:: cout<<"\n Matriz resultante is: "<< mResult[f][c];*/
            mResult[f][c]=result;
            c++;
        }
        f++;
    }    
     
    std:: cout<<"\n Matriz resultante is: \n";
    for(int i=0;i<fl/2;i++){
        for(int j=0;j<cl/2;j++){
            std::cout<<mResult[i][j]<<" ";
        }
        std:: cout<<"\n";
    }
  
}