#include <iostream>

struct Piste{
	float	_x;
	float	_y;
	char	_nimi[20];
};

inline float laske_etaisyys(Piste &p) {
	return sqrt((p._x * p._x) + (p._y * p._y));
}

int main() {
	const int LUKUMAARA = 1;
	Piste piste[LUKUMAARA];

	float x = 0, y = 0;
	char nimi[20];

	for (int i = 0; i < LUKUMAARA; i++) {
		std::cin >> piste[i]._x >> piste[i]._y >> piste[i]._nimi;
	}

	for (int j = 0; j < LUKUMAARA; j++) {
		std::cout << laske_etaisyys(piste[j]) << " " << piste[j]._nimi << std::endl;
	}
}