float matImg[100][100];
float mResult[50][50];
int cargarImagenes(void)
{
	int i, aux;
	float numero;
	FILE *in_file;
    
    
    //FILE *in_file;
	aux=0;
	if ((in_file = fopen ("shakira.dat", "rt")) == NULL)
		aux=1;
	else
	{
		fseek(in_file, 0, SEEK_SET);
    
			for (i=0; i<100; i++)
			{
                for (int j=0; j<100; j++){
                    fscanf(in_file, "%f", &numero);
                    matImg[i][j]=numero;  
                }
				
			}
	}
	fclose(in_file);
    
    return(aux);
}



int cargarResul(void)
{
	int i, aux;
	float numero;
	FILE *in_file;
    
    
    //FILE *in_file;
	aux=0;
	if ((in_file = fopen ("mat.dat", "rt")) == NULL)
		aux=1;
	else
	{
		fseek(in_file, 0, SEEK_SET);
    
			for (i=0; i<50; i++)
			{
                for (int j=0; j<50; j++){
                    fscanf(in_file, "%f", &numero);
                    mResult[i][j]=numero;  
                }
				
			}
	}
	fclose(in_file);
    
    return(aux);
}