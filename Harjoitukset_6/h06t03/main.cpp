#include <iostream>
#include <fstream>

struct HLO {
	char fName[10], lName[10], pNum[10];
};

const char FILENAME[] = "Henkilotiedot.dat";
const int  LKM_MAX = 3;

int main() {
	HLO *hlo = new HLO[LKM_MAX];
	hlo[0] = { "AAA", "AAA", "111" };
	hlo[1] = { "BBB", "BBB", "222" };
	hlo[2] = { "CCC", "AAA", "333" };

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

	int num = 0;
	char haku[10];
	std::cout << "Poista lName: " << "\n";  std::cin >> haku;
	for (int i = 0; i < LKM_MAX; ++i) {
		if (strcmp(haku, hlo[i].lName) == 0) {
			num++;
			std::cout << "VALITUT: " << hlo[i].fName << " " << hlo[i].lName << " " << hlo[i].pNum << "\n";
		}
	}

	/*-----------------------------------------------*/

	HLO *temp = new HLO[LKM_MAX - num];
	for (int i = 0; i < LKM_MAX; ++i) {
		for (int j = 0; j < LKM_MAX - num; ++j) {
			if (!strcmp(haku, hlo[i].lName) == 0) {
				temp[j] = hlo[i];
			}
		}
	}

	/*-----------------------------------------------*/

	for (int i = 0; i < LKM_MAX - num; ++i) {
		std::cout << "UUSI: " << temp[i].fName << " " << temp[i].lName << " " << temp[i].pNum << "\n";
	}
}