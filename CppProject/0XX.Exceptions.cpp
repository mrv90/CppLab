#include <iostream>
#include <exception>

class MyException : public std::exception
{
	std::string _msg;
	int _type;

public:
	MyException(const std::string& msg, int type) : _msg(msg), _type(type) {}

	virtual const char* what() const noexcept override
	{
		return _msg.c_str();
	}

	const int type() const noexcept {
		return _type;
	}
};

int main() {
	
	try
	{
		throw MyException("Something went wrong...\n", 1);
		//throw std::exception("This IS visible when caught in visual studio");
	}
	/*catch (const std::exception& e)
	{
	}*/
	catch (const MyException& e) {
		std::cerr << e.what() << std::endl;
		std::cerr << "exception type: " << e.type() << std::endl;
	}
	
	std::cin.get();
}