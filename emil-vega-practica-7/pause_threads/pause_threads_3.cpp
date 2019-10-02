// example for thread::join
#include <iostream>       // std::cout
#include <thread>         // std::thread, std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <windows.h>

#include <stdio.h>

#include "structures_lib_a.H" 

int total_initial_capital;
int total_circulating_capital;
int local_capital[10];
int  quit_flag;
int master_delay;

int winner;
int total_transactions;
int cycles_count;
float efficiency;
int v1 = 0;


void pause_thread(int n, int ID, int amount)
{
	//Blocks the execution of the current thread for at least the specified sleep_duration.
	std::this_thread::sleep_for(std::chrono::seconds(n)); 
	/* initialize random seed: */
	//srand(time(NULL));
	//v1 = v1 +rand()%10;
	std::cout << "thread ID " << ID << " valor v1 = " << v1;
	v1 = v1 + amount;
	std::cout << " nuevo v1 = "<<v1 <<"\n";
}

//----------------------------------------------------------
//----------------------------------------
//    LOOP
//----------------------------------------
//-------------------------------------------------------------
void loop_server(void)
{
	do
	{
		//std::cout << "Spawning 3 threads...\n";
		std::thread t1(pause_thread, 1,1,1);
		std::thread t2(pause_thread, 1,2,2);
		std::thread t3(pause_thread, 1,3,3);
		std::cout << "Done spawning threads. Now waiting for them to join:\n";
		t1.join();
		t2.join();
		t3.join();
		std::cout << "All threads joined!\n";
		getchar();
    }while(1);
}
//--------------------------------------------------------------
int main()
{
	
	int i;

	for (i = 0; i < 10; i++)
	{
		local_capital[i] = rand() % 101;
		printf("%i \n", local_capital[i]);
	}
	total_initial_capital = 0;
	for (i = 0; i<10; i++) total_initial_capital = total_initial_capital + local_capital[i];
	//quit_flag=0; 
	cycles_count = 0;
	master_delay = 1;
	std::cout << "stream_server_version_1.0" << std::endl;
	loop_server();
	return 0;
}