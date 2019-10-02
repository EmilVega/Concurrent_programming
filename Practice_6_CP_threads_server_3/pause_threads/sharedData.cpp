

#include <iostream>
#include <thread>
#include <vector>
struct Counter {
	int value;

	Counter() : value(0){}

	void increment(){
		++value;
	}
};
int main(){
	Counter counter;

	// Create a vector of threads
	std::vector<std::thread> threads;
	for (int i = 0; i < 5; ++i){
		threads.push_back(std::thread([&counter](){
			for (int i = 0; i < 100; ++i){
				counter.increment();
			}
		}));
	}

	for (auto& thread : threads){
		thread.join();
	}

	std::cout << counter.value << std::endl;
	getchar();
	return 0;
}
