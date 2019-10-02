// example for thread::join
#include <iostream>       // std::cout
#include <thread>         // std::thread, std::this_thread::sleep_for
#include <condition_variable>
#include <mutex>
#include <chrono>         // std::chrono::seconds
#include <windows.h>

#include <stdio.h>

std::mutex mutex1;
std::condition_variable cond;

int MAX = 10;
int count = 0;
int balance = 1000;
bool ready = false;
int saldo , cant;
int id;

void suma(int idn, int cantidad)
{
		std::unique_lock<std::mutex> lck(mutex1,std::defer_lock);
		
	// critical section (exclusive access to std::cout signaled by locking lck):
	
		while (!ready) cond.wait(lck);
		printf("thread %i ", id);
		printf("suma %i ", cantidad);
		//lck.lock();
		saldo = saldo + cantidad;
        //lck.unlock();
		printf("saldo %i \n",  saldo);
		getchar();
return;
}
//----------------------------------------------------------

void resta(int id, int cantidad)
{
	   
		//std::unique_lock<std::mutex> lck(mutex1, std::defer_lock);
		// critical section (exclusive access to std::cout signaled by locking lck):
		//while (!ready)cond.wait(lck);
		
		if (saldo - cantidad > 0)
		{printf("thread %i ", id);
			printf("resta %i ", cantidad);
			saldo = saldo - cantidad;
			printf("saldo %i \n", saldo);
			//getchar();
		}


	//return;
}

void resta3(int id, int cantidad)
{

	std::unique_lock<std::mutex> lck(mutex1, std::defer_lock);
	// critical section (exclusive access to std::cout signaled by locking lck):
	while (!ready)cond.wait(lck);

	if (saldo - cantidad > 20)
	{
		printf("thread %i ", id);
		printf("resta %i ", cantidad);
		saldo = saldo - cantidad;
		printf("saldo %i \n", saldo);
		//getchar();
	}


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
		cant = rand() % 100 + 1;
		std::thread t1(suma, 1,100);
		std::thread t2(resta,2, cant);
		//std::thread t3(resta3,3, cant);
		//std::cout << "Done spawning threads. Now waiting for them to join:\n";
		t1.join();
		t2.join();
		//t3.join();
		getchar();
	} while (1);
}
//--------------------------------------------------------------
int main()
{
	std::cout << "Balance inicial " << balance << "  \n";
	ready = true;
	//cond.notify_all();
	saldo = balance;
	loop_server();
	return 0;
}