#include <iostream>

class A {
public:
	int &f() { return this->a; }
	int &g() { return this->b; }
	int &h() { return this->c; }

	A(int a, int b, int c) : a(a), b(b), c(c){ std::cout << "A:n konstruktori: " << a << " " << b << " " << c << std::endl; }
private:
	int a, b, c;
};

class B : protected  A {
public:
	int& p1() { return f(); }
	int& p2() { return g(); }
	int& p3() { return h(); }

	B(int a, int b, int c) : A(a, b, c) { std::cout << "B:n konstruktori" << std::endl; };
};

class C : public B {
public:
	C(int a, int b, int c) : B(a, b, c) { std::cout << "C:n konstruktori" << std::endl; };
};

class D : public C {
public:
	D(int a, int b, int c) : C(a, b, c) { std::cout << "D:n konstruktori" << std::endl; };
};

int main(){
	B b(10, 20, 30);
	std::cout << b.p1() << " " << b.p2() << " " << b.p3() << std::endl;

	C c(1, 2, 3);
	std::cout << c.p1() << " " << c.p2() << " " << c.p3() << std::endl;

	D d(3, 2, 1);
	std::cout << d.p1() << " " << d.p2() << " " << d.p3() << std::endl;


}