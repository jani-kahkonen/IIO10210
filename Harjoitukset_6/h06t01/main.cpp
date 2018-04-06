#include <iostream>
#include <fstream>

struct HenkiloTiedot {
	char etunimi[10], sukunimi[10], puhNum[10];
};

const char FILENAME[] = "Henkilotiedot.dat";
const int  LKM_MAX = 3;

int main() {
	HenkiloTiedot henkilotiedot[LKM_MAX] = { {"Henkilo_A","AAA","111"},{ "Henkilo_B","BBB","222" },{ "Henkilo_C","CCC","333" } };

	/*-----------------------------------------------*/

	std::ios_base::openmode openflags = std::ios_base::binary;
	std::ofstream kohde(FILENAME, openflags);

	if (!kohde.is_open()) {
		std::cout << "Tiedoston avausvirhe, ei tallennusta";
		return(-1);
	}

	for (int i = 0; i < LKM_MAX; i++){
		kohde.write((char *)&henkilotiedot[i], sizeof(HenkiloTiedot));
	}

	kohde.close();
	std::cout << "Tiedosto " << FILENAME << " luotu\n";

	/*-----------------------------------------------*/

	std::ifstream lahde(FILENAME, openflags);
	if (!lahde.is_open()) {
		std::cout << "Tiedoston avausvirhe, ei lukemista";
		return(-1);
	}

	while (lahde.peek() != EOF) {
		lahde.read((char *)&henkilotiedot, sizeof(HenkiloTiedot));
		std::cout << "Luettu Henkilotieto: " << henkilotiedot->etunimi << " " << henkilotiedot->sukunimi << " " << henkilotiedot->puhNum << "\n";
	}
	lahde.close();
}