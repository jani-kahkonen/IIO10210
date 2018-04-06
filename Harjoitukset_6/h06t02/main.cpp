#include <iostream>
#include <fstream>

struct HLO {
	char fName[10], lName[10], pNum[10];
};

const char FILENAME[] = "Henkilotiedot.dat";
const int  LKM_MAX = 3;

int main() {
	HLO hlo[LKM_MAX] = { { "Henkilo_A","AAA","111" },{ "Henkilo_B","BBB","222" },{ "Henkilo_C","CCC","333" } };

	std::ios_base::openmode openflags = std::ios_base::binary;

	/*-----------------------------------------------*/

	std::ofstream kohde(FILENAME, openflags);
	if (!kohde.is_open()) {
		std::cout << "Tiedoston avausvirhe, ei tallennusta";
		return(-1);
	}

	for (int i = 0; i < LKM_MAX; ++i) {
		kohde.write((char *)&hlo[i], sizeof(HLO));
		std::cout << "Write HLO: " << hlo[i].fName << " " << hlo[i].lName << " " << hlo[i].pNum << "\n";
	}

	kohde.close();
	std::cout << "Tiedosto " << FILENAME << " luotu\n";

	/*-----------------------------------------------*/

	std::ifstream lahde(FILENAME, openflags);
	if (!lahde.is_open()) {
		std::cout << "Tiedoston avausvirhe, ei lukemista";
		return(-1);
	}

	for (int i = 0; i < LKM_MAX; ++i) {
		lahde.read((char *)&hlo[i], sizeof(HLO));
		std::cout << "Read HLO: " << hlo[i].fName << " " << hlo[i].lName << " " << hlo[i].pNum << "\n";
	}

	lahde.close();

	/*-----------------------------------------------*/

	std::cout << "Hae indX: " << std::endl;
	for (int i = 0; i != -1; std::cin >> i) {
		if (i >= 0 && i < LKM_MAX) {
			std::cout << "Read HLO: " << hlo[i].fName << " " << hlo[i].lName << " " << hlo[i].pNum << "\n";
		}
	}

	/*-----------------------------------------------*/

	char haku[10];
	std::cout << "Hae lName: " << "\n";  std::cin >> haku;
	for (int i = 0; i < LKM_MAX; ++i) {
		if (strcmp(haku, hlo[i].lName) == 0) {
			std::cout << "Read HLO: " << hlo[i].fName << " " << hlo[i].lName << " " << hlo[i].pNum << "\n";
		}
	}
}
