#include <iostream>
#include <thread>
#include <mutex>
#include <windows.h>
#include <chrono>
#include <vector>
#include <signal.h>

std::mutex mutxbarber;        //booleano 0 dormido 1 activo Da exclusividad al recurso barbero
std::mutex mch;               //cuando sea 1 el numero de sillas puede aumentar o disminuir
std::mutex listaCliente;      //numero de clientes en la sala de espera

size_t n_chairs = 5;               //numero de sillas disponibles
//std::vector<int> avail_chair(n_chairs);
int clients_population = 10;
int chair_queue[5] = {0,0,0,0,0};
int client_ID[10];
int clients_waiting = 0;
int ID;
int client_being_attended;
int timer;
//std::this_thread::sleep_for(std::chrono::milliseconds(x));
sig_atomic_t signal_barber = 0;

struct chair_queue {
	std::mutex mut;

} chairs;

void handler_barber(int param)
{
	signal_barber = 1;
}
//===================================================
void show_queue()
{
	int i;
	std::cout << "Chairs Queue:";
	for (unsigned i = 0; i<n_chairs; i++)
	std::cout << ' ' << chair_queue[i];
	std::cout << '\n';
}

//=============================================================
	void shift_clients()
	{
		int i;
		for (i = 0; i <n_chairs-1; i++)
		{
			chair_queue[i] = chair_queue[i+1];
		}
		chair_queue[n_chairs-1]=0;
		std::cout << "queue_shifted ";
		show_queue();
	}
//=============================================================
void barber_attend_costum()
{
	if ((chair_queue[0])&&(!timer)){ client_being_attended=chair_queue[0]; timer = 10; }//tiempo de servicio
	if (timer){ std::cout <<"Barber attending : "<< client_being_attended<<" \n"; }
	if (timer)timer--;
	if (timer == 1){ shift_clients(); timer = 0; }
}
//==============================================================
void get_into_queue(int ID1)
{
	chairs.mut.lock();
	int j;
	int flag_in_queue=0;
	for (j = 0; j < n_chairs;j++)
	{
		if (ID1 == chair_queue[j]) flag_in_queue=1; // client ID1 is alrready sitting in the chairs
	}
	if (!flag_in_queue)
	for (j = 0; j < n_chairs; j++)
	{
		if (chair_queue[j] == 0){ chair_queue[j] = ID1; break; }
	}
	show_queue();
	chairs.mut.unlock();
}
//==============================================================
//Atiende a los clientes
void client_life()
{
	int dice;      //dado
	int i;
	srand(time(NULL));

	std::thread t1(get_into_queue, 1);
	std::thread t2(get_into_queue, 2);
	std::thread t3(get_into_queue, 3);
	std::thread t4(get_into_queue, 4);
	std::thread t5(get_into_queue, 5);
	std::thread t6(get_into_queue, 6);
	std::thread t7(get_into_queue, 7);
	std::thread t8(get_into_queue, 8);
	std::thread t9(get_into_queue, 9);
	

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	t9.join();

	


	//for (i = 1; i < clients_population; i++)
	//{
	//   dice = rand() % 5;   //probabilidad de que un cliente necesite servicio 1/n
	//  // if (!dice){ id = i; get_into_queue(id); }
	//   
	//   if (!dice){id = i; get_into_queue(id); }
	//}
}
//-------------------------------------------------------------
void loop_barbero(void)
{
	do
	 {
			std::thread t1(client_life);
			std::thread t2(barber_attend_costum);
			t1.join();
			t2.join();
			//t3.join();
			if (chair_queue[0] == 0) std::cout << "barber sleeping";
			getchar();
     }while (1);
}

//--------------------------------------------------------------
int main()
{
	std::cout << "The Sleeping Barber Problem \n"; 
	std::cout << "--------------------";
	loop_barbero();
	getchar();
	return 0;
}