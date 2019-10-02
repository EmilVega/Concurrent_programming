#include <stdio.h>
#include <thread>
#include <mutex>
#include<iostream>
#include <chrono>

std::mutex mutex1, mutex2;

int MAX = 10;
int count = 0;
int balance = 1000;
bool ready = false;
int saldo, cant;
int id;

void suma(int idn, int cantidad, int sec)
{
	
	// critical section (exclusive access to std::cout signaled by locking lck):
	mutex1.lock();
	std::this_thread::sleep_for(std::chrono::milliseconds(sec));
	printf("thread %i ", idn);
	printf("suma %i ", cantidad);
	
	saldo = saldo + cantidad;
	
	printf("saldo %i \n", saldo);
	
	getchar();
	mutex1.unlock();
	
	
}
//----------------------------------------------------------

void resta(int id, int cantidad)
{

	
	// critical section (exclusive access to std::cout signaled by locking lck):
	mutex2.lock();
	if (saldo - cantidad > 0)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		printf("thread %i ", id);
		printf("resta %i ", cantidad);
		saldo = saldo - cantidad;
		printf("saldo %i \n", saldo);

		//getchar();
	}

	mutex2.unlock();
	return;
}


//----------------------------------------
//    LOOP
//----------------------------------------
//-------------------------------------------------------------
void loop_server(void)
{
	do
	{
		cant = rand() % 1000 + 1;
		std::thread t1(suma, 1, 100,100);
		std::thread t2(resta, 2, cant);
		std::thread t3(suma,3,10,610);
		t1.join();
		t2.join();
		t3.join();
		getchar();
	} while (1);
}
//--------------------------------------------------------------
int main()
{
	std::cout << "Balance inicial " << balance << "  \n";
	ready = true;
	saldo = balance;
	loop_server();
	return 0;
}