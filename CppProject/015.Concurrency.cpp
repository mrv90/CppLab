#include <iostream>
#include <thread>

bool is_finished = false;

void do_work() {
	
	std::cout << "the thread " << std::this_thread::get_id() << " started working " << std::endl;
	
	while (!is_finished) {
		std::cout << "working ..." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

int main() {
	std::thread worker{ do_work };

	std::cin.get();
	is_finished = true;

	worker.join();

	std::cout << "main thread with id " << std::this_thread::get_id() << " stopped as expected " << std::endl;
	std::cin.get();

	return 0;
}