#include <iostream>
#include <thread>
#include <mutex>
#include <windows.h>

std::mutex barbero;                     //booleano 0 dormido 1 activo Da exclusividad al recurso barbero
std::mutex sillasAccesibles;           //cuando sea 1 el numero de sillas puede aumentar o disminuir
std::mutex listaCliente;                    //numero de clientes en la sala de espera

int sillasLibres = 5;               //numero de sillas disponibles
int numClientes = 0;

void waitCliente()
{
	printf("entra un cliente  ");

}
//==========================================================
void barberoListo()
{
	printf("Barbero listo  ");

}
//==========================================================
void cliente()
{
	printf("entra un cliente  ");
	//wait(sillasAccesibles);      //trata de acceder a una silla
		
	if (sillasLibres > 0) //Sillas disponibles
	{
		sillasLibres = -1;
		
		//espera que el barbero lo atienda
		//el barbero lo atiende
		//sale de la peluqueria
	}
	else //no hay sillas libres
	{

		//el cliente se va de la barberia
	}
}
//============================================================
void barbero()
{
	//Esperar al próximo cliente.Si no hay ninguno dormir >>
    //Cortar el pelo. >>
	//Abrir la puerta y esperar a que salga el cliente >>
		
}
//-------------------------------------------------------------
void loop_server(void)

	do
	{
		if (numClientes >= N) { pthread_mutex_unlock(&m); return LLENO; } // No cabe
		else {
			clientes++;
		//waitClientes;
		std::thread t1(cliente);
		//	waitSillasAccesibles;

	} while (1);
}
//--------------------------------------------------------------
int main()
{
	std::cout << "Barberia \n"; 
	numClientes = 1;
	loop_server();
	return 0;
}