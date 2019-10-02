#include <thread>
#include <mutex>
#include <iostream>

int g_i = 0;
std::mutex g_i_mutex;  // protects g_i

void safe_increment()
{
	//std::lock_guard<std::mutex> lock(g_i_mutex);
	++g_i;

	std::cout << std::this_thread::get_id() << ": " << g_i << '\n';

	// g_i_mutex is automatically released when lock
	// goes out of scope
}
void loop_server(void)
{
	do
	{
		std::thread t1(safe_increment);
		std::thread t2(safe_increment);

		t1.join();
		t2.join();
		getchar();
	}while (1);
}
int main()
{
	std::cout << "main: " << g_i << '\n';

	loop_server();
	std::cout << "main: " << g_i << '\n';
}