#include <iostream>
#include <string>

class A {
public:
	A(std::string A1);
	
	std::string m_strOfA = "";
};

A::A(std::string A1) : m_strOfA(A1)
{
	std::cout << "constructing A with " << A1 << std::endl;
}

class B : public A {
public:
	B(std::string A2);
};

B::B(std::string A2) : A(A2)
{
	std::cout << "constucting B with " << A2 << std::endl;
}

int main() {
	B b = B("my value");
	return 0;
}