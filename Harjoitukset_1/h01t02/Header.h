#include <string>

struct Koira{
	int nro, ika;
	static int counter;
	std::string nimi;

	inline int getNro()const{ return nro; }
	inline std::string getNimi()const{ return nimi; }
	inline int getIka()const{ return ika; }

	Koira() : nro(counter++), ika(0), nimi(""){}
};

int Koira::counter = 1;