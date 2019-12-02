#include <iostream>
#include <string>

class X {
public:
	X() = delete;
	X(bool enable_or_not = false);
	X(const X& other);
	X(X&& other);
	X& operator=(const X& other);
	X& operator=(X&& other);
	~X();

	bool m_enable;
};

X::X(bool enable_or_not)
{
	std::cout << "X constructed with " << enable_or_not << std::endl;
	m_enable = enable_or_not;
}

X::X(const X & other) : m_enable(other.m_enable)
{
	std::cout << "X copy constructed with " << other.m_enable << std::endl;
}

X::X(X && other) : m_enable(other.m_enable)
{
	std::cout << "X move constructed with " << other.m_enable << std::endl;
	other.m_enable = false;
}

X & X::operator=(const X & other)
{
	std::cout << "X copy initilized with " << other.m_enable << std::endl;

	if (this != &other)
		m_enable = other.m_enable;

	return *this;
}

X & X::operator=(X && other)
{
	std::cout << "X move initilized with " << other.m_enable << std::endl;

	this->m_enable = other.m_enable;
	other.m_enable = false;

	return *this;
}

X::~X()
{
	std::cout << "X destructed " << std::endl;

	m_enable = false;
}

class Y {
public:
	Y(bool enable_or_not = false);
	~Y();

	X* x;
};


Y::Y(bool enable_or_not)
{
	std::cout << "Y constructed with " << enable_or_not << std::endl;
	X x2(enable_or_not);
	x = &x2;
}

Y::~Y()
{
	std::cout << "Y destructed " << std::endl;
}

int main() {
	{
		Y y1(true);
	}
	
	{
		Y y2(false);
	}

	return 0;
}