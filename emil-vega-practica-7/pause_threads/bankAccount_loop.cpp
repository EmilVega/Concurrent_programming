#include <mutex>
#include <thread>
#include <iostream>

struct bank_account {
	explicit bank_account(int balance) : balance(balance) {}
	int balance;
	std::mutex m;
};

bank_account my_account(100);
bank_account your_account(50);

void transfer(bank_account &from, bank_account &to, int amount)
{
	// lock both mutexes without deadlock
	std::lock(from.m, to.m);
	// make sure both already-locked mutexes are unlocked at the end of scope
	std::lock_guard<std::mutex> lock1(from.m, std::adopt_lock);
	std::lock_guard<std::mutex> lock2(to.m, std::adopt_lock);

	// equivalent approach:
	//    std::unique_lock<std::mutex> lock1(from.m, std::defer_lock);
	//    std::unique_lock<std::mutex> lock2(to.m, std::defer_lock);
	//    std::lock(lock1, lock2);

	from.balance -= amount;
	to.balance += amount;
	std::cout << from.balance<<"\n";
	std::cout << to.balance << "\n";;
}
//-------------------------------------------------------------
void loop_server(void)
{
	do
	{
		

		std::thread t1(transfer, std::ref(my_account), std::ref(your_account), 10);
		std::thread t2(transfer, std::ref(your_account), std::ref(my_account), 5);

		t1.join();
		t2.join();
		getchar();
	} while (1);
}
int main()
{
	loop_server();
}