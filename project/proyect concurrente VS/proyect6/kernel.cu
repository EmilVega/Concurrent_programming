#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//#include <graphics.h>
#include <math.h>

#include <iostream>
#include "loadImage.h"
#include <ctime>
//#include "PRINT_MATRIX.h"
int start_s = clock();
const int st = 2;
char dummy[1];
double M[101][101];
double mResult[50][50];

// CUDA kernel. Each thread takes care of one element of c
__global__ void vecMult(double *a, double *b, double *c, int n)
{
	// Get our global thread ID
	int id = blockIdx.x*blockDim.x + threadIdx.x;

	// Make sure we do not go out of bounds
	if (id < n)
		c[id] = a[id] * b[id];
}


int main(int argc, char* argv[])
{
	
	cargarImagenes();
	
	const int fl = (sizeof matImg / sizeof matImg[0]) + 1;
	const int cl = (sizeof matImg[0] / sizeof(int)) + 1;

	
	
	// Size of vectors
	int n = 9;

	//Pass to matrux with 0s at the end
	for (int i = 0; i < fl; i++) {
		for (int j = 0; j < cl; j++) {
			if (j == cl - 1 || i == fl - 1) { M[i][j] = 0; }
			else { M[i][j] = matImg[i][j]; }
		}
	}

	/*std::cout << "\n Matriz origen is: \n";
	for (int i = 0; i<fl; i++) {
		for (int j = 0; j<cl; j++) {
			std::cout << M[i][j] << " ";
		}
		std::cout << "\n";
	}*/

	

	// Host input vectors
	double *f1;
	double *f2;
	double *f3;
	double *f4;
	double *sbm;

	//double *h_a;
	//double *h_b;

	//Host output vector
	double *r_c;

	// Device input vectors
	double *d_f1;
	double *d_f2;
	double *d_f3;
	double *d_f4;
	double *d_sbm;

	//Device output vector
	double *d_rc;

	// Size, in bytes, of each vector
	size_t bytes = n * sizeof(double);

	// Allocate memory for each vector on host
	f1 = (double*)malloc(bytes);
	f2 = (double*)malloc(bytes);
	f3 = (double*)malloc(bytes);
	f4 = (double*)malloc(bytes);
	sbm = (double*)malloc(bytes);
	r_c = (double*)malloc(bytes);

	// Allocate memory for each vector on GPU
	cudaMalloc(&d_f1, bytes);
	cudaMalloc(&d_f2, bytes);
	cudaMalloc(&d_f3, bytes);
	cudaMalloc(&d_f4, bytes);
	cudaMalloc(&d_sbm, bytes);
	cudaMalloc(&d_rc, bytes);

	//int i;
	// Initialize vectors on host

	f1[0] = -1; f1[1] = 0; f1[2] = 1; f1[3] = -1; f1[4] = 0; f1[5] = 1; f1[6] = -1; f1[7] = 0; f1[8] = 1;
	f2[0] = -1; f2[1] = -1; f2[2] = -1; f2[3] = 0; f2[4] = 0; f2[5] = 0; f2[6] = 1; f2[7] = 1; f2[8] = 1;
	f3[0] = 0; f3[1] = 1; f3[2] = 1; f3[3] = -1; f3[4] = 0; f3[5] = 1; f3[6] = -1; f3[7] = -1; f3[8] = 0;
	f4[0] = 1; f4[1] = 1; f4[2] = 0; f4[3] = 1; f4[4] = 0; f4[5] = -1; f4[6] = 0; f4[7] = -1; f4[8] = -1;

	/*for (i = 0; i < n; i++) {
	h_a[i] = sin(i)*sin(i);
	h_b[i] = cos(i)*cos(i);
	}*/


	// Copy host vectors to device
	cudaMemcpy(d_f1, f1, bytes, cudaMemcpyHostToDevice);
	cudaMemcpy(d_f2, f2, bytes, cudaMemcpyHostToDevice);
	cudaMemcpy(d_f3, f4, bytes, cudaMemcpyHostToDevice);
	cudaMemcpy(d_f4, f4, bytes, cudaMemcpyHostToDevice);

	int blockSize, gridSize;

	// Number of threads in each thread block
	blockSize = 1024;

	// Number of thread blocks in grid
	gridSize = (int)ceil((float)n / blockSize);

	// Execute the kernel
	
	int f = 0, c=0;
	for (int i = 1; i < fl - 1; i += st) {
		c = 0;
		for (int j = 1; j < cl - 1; j += st) {
			sbm[0] = M[i - 1][j - 1];	sbm[1] = M[i - 1][j];	sbm[2] = M[i - 1][j + 1];
			sbm[3] = M[i][j - 1];		sbm[4] = M[i][j];		sbm[5] = M[i][j + 1];
			sbm[6] = M[i + 1][j - 1];	sbm[7] = M[i + 1][j];	sbm[8] = M[i + 1][j + 1];

			cudaMemcpy(d_sbm, sbm, bytes, cudaMemcpyHostToDevice);

			vecMult << <gridSize, blockSize >> > (d_sbm, d_f1, d_rc, n);

			// Copy array result back to host
			cudaMemcpy(r_c, d_rc, bytes, cudaMemcpyDeviceToHost);

			double resultado1 = 0;
			for (int k = 0; k < n; k++) {
				resultado1 += r_c[k];
			}
			
			vecMult << <gridSize, blockSize >> > (d_sbm, d_f2, d_rc, n);

			
			// Copy array result back to host
			cudaMemcpy(r_c, d_rc, bytes, cudaMemcpyDeviceToHost);
          
			
			double resultado2 = 0;
			for (int k = 0; k < n; k++) {
				resultado2 += r_c[k];
			}

			
			vecMult << <gridSize, blockSize >> > (d_sbm, d_f3, d_rc, n);

			// Copy array result back to host
			cudaMemcpy(r_c, d_rc, bytes, cudaMemcpyDeviceToHost);
			
			double resultado3 = 0;
			for (int k = 0; k < n; k++) {
				resultado3 += r_c[k];
			}

			
			vecMult << <gridSize, blockSize >> > (d_sbm, d_f4, d_rc, n);

			// Copy array result back to host
			cudaMemcpy(r_c, d_rc, bytes, cudaMemcpyDeviceToHost);
			
			double resultado4 = 0;
			for (int k = 0; k < n; k++) {
				resultado4 += r_c[k];
			}

			
			mResult[f][c] = resultado1 + resultado2 + resultado3 + resultado4;

			

			c++;
			
		}
		f++;
		//getchar();
	}


	/*std::cout << "\n Matriz resultante is: \n";
	for (int i = 0; i<fl / 2; i++) {
		for (int j = 0; j<cl / 2; j++) {
			std::cout << mResult[i][j] << " ";
		}
		std::cout << "\n";
	}*/



	FILE* fichero;
	fichero = fopen("mat.dat", "wt");
	for (int i = 0; i<fl / 2; i++) {
		for (int j = 0; j<cl / 2; j++) {
			fprintf(fichero,"%f\n", mResult[i][j]);
		}
	}
	fclose(fichero);
	/*
		fprintf(fichero, "%s%s%sEscritas %d+1 lineas en fichero", cadena1, cadena2, cadena3, i);
	fclose(fichero);
	fputs("Aprender a programar (linea 1)\n", fichero);
	fputs("requiere esfuerzo (linea 2)\n", fichero);
	fputs("y dedicacion (linea 3)", fichero);
	fclose(fichero);
	printf("Proceso completado");*/

	// Release device memory
	cudaFree(d_f1);
	cudaFree(d_f2);
	cudaFree(d_f3);
	cudaFree(d_f4);
	cudaFree(d_sbm);
	cudaFree(d_rc);

	// Release host memory
	free(f1);
	free(f2);
	free(f3);
	free(f4);
	free(sbm);
	free(r_c);

	// -------------------- del main de print matrix

	
	/*train();
	clrscr();*/


	int stop_s = clock();
	std::cout << "el tiempo de este código fue: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000;


	getch();

	return 0;
}