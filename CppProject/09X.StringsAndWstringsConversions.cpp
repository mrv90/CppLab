#include <iostream>

int main() {
	std::string fancy("old string now wstring");
	std::wstring wfancy(L"old wstring now string");
		
	std::cout << std::wstring(fancy.begin(), fancy.end()).c_str() << std::endl; // NOTE: not working correctly on output!
	std::cout << std::string(wfancy.begin(), wfancy.end()).c_str() << std::endl;

	std::cin.get();
}