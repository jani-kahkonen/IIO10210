#include <iostream>

class Piste {
public:
	inline	float	getX() { return _x; }
	inline	float	getY() { return _y; }
	inline	char	*getNimi() { return _nimi; }

	Piste() : _x(0), _y(0) {}
	Piste(float x, float y, char *nimi) : _x(x), _y(y){	strcpy_s(_nimi, nimi);	}
private:
	float	_x, _y;
	char	_nimi[20];
};

inline float laske_etaisyys(Piste &p) {
	return sqrt((p.getX() * p.getX()) + (p.getY() * p.getY()));
}

int main() {
	const int LUKUMAARA = 5;
	Piste piste[LUKUMAARA];

	float x = 0, y = 0;
	char nimi[20];

	for (int i = 0; i < LUKUMAARA; i++) {
		std::cin >> x >> y >> nimi; piste[i] = Piste(x, y, nimi);
	}

	for (int j = 0; j < LUKUMAARA; j++) {
		std::cout << laske_etaisyys(piste[j]) << " " << piste[j].getNimi() << std::endl;
	}
}
