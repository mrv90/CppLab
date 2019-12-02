#include <iostream>

class X {
public:
	X();
	X(int integer);
	X(const X& other);
	X(X&& other);
	X& operator=(const X& other);
	X& operator=(X&& other);
	~X();

	int *m_int;
	//TODO implement and thes rule of 3,5,0 in a seperate file!
};

X::X() : m_int { 0 }
{
	std::cout << "initilizing with no argument constrcutor" << std::endl;
}

X::X(int integer) : m_int {&integer}
{
	std::cout << "initilizing with 1 argument constrcutor" << std::endl;
}

X::X(const X & other) : m_int {other.m_int}
{
	std::cout << "initilizing with copy constrcutor" << std::endl;
}

X::X(X && other) : m_int{other.m_int}
{
	std::cout << "initilizing with move constrcutor" << std::endl;
	other.m_int = nullptr;
}

X & X::operator=(const X &other)
{
	std::cout << "initilizing with copy assingnment" << std::endl;
	if (this != &other)
		m_int = other.m_int;

	return *this;
}

X & X::operator=(X &&other)
{
	std::cout << "initilizing with move assingnment" << std::endl;
	if (this != &other) {
		m_int = other.m_int;
		other.m_int = nullptr;
	}

	return *this;
}

X::~X()
{
	std::cout << "cleaning up with destructor" << std::endl;
}

void main() {
	X x;
	X x1(10);
	X x2 = x;
	X x3 = std::move(x2);
	x2 = x1;
	x3 = std::move(x);

	std::cin.get();
}