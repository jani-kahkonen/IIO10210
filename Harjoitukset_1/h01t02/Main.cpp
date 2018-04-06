#include <iostream>
#include "Header.h"

int main(){
	const int LUKUMAARA = 5;
	Koira koira[LUKUMAARA];

	for (int i = 0; i < LUKUMAARA; i++){
		std::cout << "Anna koiran nimi ja ika" << std::endl;
		std::cin >> koira[i].nimi >> koira[i].ika;
	}

	for (int i = 0; i < LUKUMAARA - 1; i++){
		for (int j = i + 1; j < LUKUMAARA; j++){
			if (koira[i].ika > koira[j].ika){
				std::swap(koira[i], koira[j]);	//Koira temp = koira[i];koira[i] = koira[j];koira[j] = temp;
			}
		}
	}

	for (int i = 0; i < LUKUMAARA; i++){
		std::cout << "Anna koiran nro:  " << koira[i].getNro() << std::endl;
		std::cout << "Anna koiran nimi: " << koira[i].getNimi() << std::endl;
		std::cout << "Anna koiran ika:  " << koira[i].getIka() << std::endl;
		std::cout << "-------------------" << std::endl;
	}
}