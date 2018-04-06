#include <iostream>

int main() {


	int a, b, c;    // Käytetään vain muistin varausta varten
	int nro = 5;

	std::cout << nro << std::endl;

	int *ptr = &nro;
	int **ptr_ptr = &ptr;

	nro += 1;

	std::cout << nro << std::endl;

	*ptr += 1;

	std::cout << nro << std::endl;

	**ptr_ptr += 1;

	std::cout << nro << std::endl;

	std::cout << "osoittaa	" << nro << "		omaosoite	"	<< &nro <<  std::endl;
	std::cout << "osoittaa	" << ptr << "	omaosoite	"	<< &ptr << std::endl;
	std::cout << "osoittaa	" << ptr_ptr << "	omaosoite	" << &ptr_ptr << std::endl;
}