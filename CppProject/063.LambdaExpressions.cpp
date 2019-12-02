#include <iostream>
#include <string>

int main() {
	std::string target_variable = "target_value";
	auto lambda1 = [target_variable]()
	{ 
		std::cout << target_variable << std::endl;
	};

	auto lambda2 = [](std::string simple_parameter) {
		std::cout << simple_parameter << std::endl;
	};

	/*A lambda is also just a function object, so you need to have a () to call it, so if you need it directly, 
	there is no way around it (except of course some function that invokes the lambda like std::invoke).*/
	
	std::invoke(lambda1);
	std::invoke(lambda2, "simple string");
	
	std::cin.get();
}