//
// Created by Jens on 21/02/2023.
//

#include <iostream>
#include <thread>


void threadFunction(int id) {
	std::cout << "Thread " << id << std::endl;
	sleep(id);
}

int main() {
	std::thread t1(threadFunction, 1);
	std::thread t2(threadFunction, 2);
	std::thread t3([] {std::cout << "Lambda thread" << std::endl;});

	t1.join(); // Wait for thread to finish.
	t2.detach(); // Let thread run on its own.
	t3.join(); // Wait for thread to finish.

	std::cout << "Main thread" << std::endl;
	return 0;
}1
