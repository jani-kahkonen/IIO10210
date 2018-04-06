#include <iostream>
class Piste{
public:
	int getX()const{ return _x; }
	int getY()const{ return _y; }
	Piste(int x, int y) : _x(x), _y(y){}
private:
	int _x, _y;
};

class Kolmio {
public:
	void tulosta(int i){ std::cout << "X: "<< pisteet[i]->getX() << " " << "Y: " << pisteet[i]->getY() << std::endl; }
	Kolmio(Piste* p1, Piste* p2, Piste* p3){
		pisteet[0] = p1;
		pisteet[1] = p2;
		pisteet[2] = p3;
	}
	~Kolmio(){ delete pisteet[0]; delete pisteet[1]; delete pisteet[2]; }
private:
	Piste *pisteet[3];
};

int main(void)
{
	// Muistia varataan yhdelle kolmiolle, jossa kolme pistettä
	Kolmio kolmio(new Piste(1, 2), new Piste(2, 2), new Piste(4, 2));

	// TEHTÄVÄ: Tulosta kolmion sisältämät pisteet
	kolmio.tulosta(0);
	kolmio.tulosta(1);
	kolmio.tulosta(2);
}