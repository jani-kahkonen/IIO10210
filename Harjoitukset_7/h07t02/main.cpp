#include <iostream>

void FunktioCee(int a)
{
	a++;
	std::cout << "FunktioCee: a:n arvo  " << a << " ja osoite		" << &a << std::endl;
}

void viittausFunktioCee(int *a) {
	*a += 1;
	std::cout << "viittausFunktioCee a:n arvo " << *a << " ja osoite	" << a << std::endl;
}

void viittausFunktioCeeRef(int **a) {
	**a += 1;
	std::cout << "viittausFunktioCeeRef a:n arvo " << **a << " ja osoite	" << &*a << std::endl;
}

void viittausFunktioCplus(int &a) {
	a += 1;
	std::cout << "viittausFunktioCeeRef a:n arvo " << a << " ja osoite	" << &a << std::endl;
}


int main()
{
	int a = 10;

	// Tavallinen funktiokutsu
	std::cout << "main: a = " << a << " ja &a = " << &a << std::endl;
	FunktioCee(a);
	std::cout << "main: a = " << a << " ja &a = " << &a << std::endl;

	// Funktiokutsu käyttäen C:n osoittimia. Tässä osoitin välitetään arvona (passed by value). 
	// Argumenttina muistiosoite (&a) -> voidaan antaa osoittimelle
	std::cout << "main: a = " << a << " ja &a = " << &a << std::endl;
	viittausFunktioCee(&a);
	std::cout << "main: a = " << a << " ja &a = " << &a << std::endl;

	// Funktiokutsu, jossa itse funktiossa käytetään C++:n viittausmuuttujaa (reference variable)
	std::cout << "main: a = " << a << " ja &a = " << &a << std::endl;
	viittausFunktioCplus(a);
	std::cout << "main: a = " << a << " ja &a = " << &a << std::endl;

	// Funktiokutsu käyttäen C:n osoittimia välittäen itse osoitin viitteenä (passed by reference)

	int* p_a = &a;
	int** p_p_a(&p_a); // Osoitin osoittimeen

	std::cout << "main: a = " << a << " ja &a = " << &a << std::endl;
	viittausFunktioCeeRef(p_p_a);
	std::cout << "main: a = " << a << " ja &a = " << &a << std::endl;

	return(0);
}
