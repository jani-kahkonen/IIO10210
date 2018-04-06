#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

class PisteException {
private:
	string message;
public:
	string getMessage() {
		return "PisteExecption: " + message;
	}
	PisteException(string m) : message(m){}
};


class Piste {
public:
	Piste() {};
	Piste(float, float, char*);
	Piste(const Piste& p);
	~Piste();
	float laske_etaisyys();
	void  tulosta();
	friend ostream& operator<<(ostream& output, const Piste& p);
private:
	float x;
	float y;
	char *nimi;
};

Piste::Piste(float x, float y, char *n) {
	if (x < 0 || x > 1024 || y < 0 || y > 768) throw PisteException("pisterajan ulkopuolella");

	if (strlen(n)>20) throw PisteException("jono liian pitkä");

	this->x = x;
	this->y = y;
	this->nimi = n;
}

float Piste::laske_etaisyys() {
	return sqrt(this->x*this->x + this->y*this->y);
}

void Piste::tulosta() {
	cout << "(" << this->x << "," << this->y << ")etäisyys origosta = " << laske_etaisyys() << endl;
}

Piste::Piste(const Piste& p) {
	x = p.x;
	y = p.y;
	nimi = p.nimi;
}

Piste::~Piste() {
	cout << "destruktoria kutsuttu ..." << this->nimi << endl;
}
 
ostream& operator<<(ostream& output, const Piste& p) {
	output << *p.nimi << "(" << p.x << ", " << p.y << ")";
	return output;
}

int main(void)
{
	// Muistia varataan viidelle pisteelle
	Piste *pisteet = new Piste[2];
	int   n = 0;

	// Syötteen lukeminen
	float x, y;

	cout << "Anna arvot pisteelle seuraavasti: nimi x y" << endl;
	while (n < 2) {
		char* nimi = new char[40];
		cin >> nimi >> x >> y;
		try
		{
			Piste tempPiste(x, y, nimi);
			pisteet[n] = tempPiste; // kutsuu kopiointialustajaa
			n++;
		}
		catch(PisteException e)
		{
			cout << e.getMessage() << endl;
		}
	}

	// Kaikki etäisyydet laskettu ja tulostettu kerralla
	for (int i = 0; i < 2; i++) {
		// 
		cout << pisteet[i] << endl;
	}
	delete[] pisteet; // muistin vapautus
	return 0;
}
