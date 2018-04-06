#include <iostream>

class Omena_A{
public:
	Omena_A(){ std::cout << "+A: " << this << std::endl; }
	~Omena_A(){ std::cout << "-A: " << this << std::endl; }
};

class Omena_B{
public:
	Omena_B(){ std::cout << "+B: " << this << std::endl; }
	~Omena_B(){ std::cout << "-B: " << this << std::endl; }
};

class Kori{
public:
	Kori(){ std::cout << "+K: " << this << std::endl; }
	~Kori(){ std::cout << "-K: " << this << std::endl; }
private:
	Omena_A omena_A;
	Omena_B omena_B;
};

int main(){
	Kori k;
}