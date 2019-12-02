#include <iostream>
#include <map>

int main() {
	// map is a SORTED container !!
	std::map<int, const char*> sorted_container = {
		{3, "third value"},
		{1, "first value"},
		{100, "100th value"},
		{5, "fifth value"},
		{2, "second value"}
	};

	std::cout << "iterating in a ranged-based for" << std::endl;
	for (auto pair : sorted_container)
		std::cout << pair.first << " : " << pair.second << std::endl;
	std::cout << "========================================" << std::endl;

	std::cout << "iterating in an st::map<int, const char*>::iterator" << std::endl;
	for (std::map<int, const char*>::iterator it = sorted_container.begin(); it != sorted_container.end(); it++) {
		if (it == std::prev(sorted_container.end()))
			std::cout << "last item found here!" << std::endl;

		std::cout << it->first << " : " << it->second << std::endl;
	}
	std::cout << "========================================" << std::endl;

	std::cin.get();
}