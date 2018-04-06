#include <iostream>
#include <string>

class Kuvio2d {
protected:
	double leveys;
	double korkeus;
	std::string nimi;

public:
	Kuvio2d() {
		nimi = "nimetön";
	}
	Kuvio2d(double l, double k, std::string n) {
		leveys = l;
		korkeus = k;
		nimi = n;
	}
	Kuvio2d(double s, std::string n) {
		leveys = korkeus = s;
		nimi = n;
	}
	Kuvio2d(const Kuvio2d& k) {
		leveys = k.leveys;
		korkeus = k.korkeus;
		nimi = k.nimi;
	}
	virtual ~Kuvio2d() {}
	double getLeveys() { return leveys; }
	double getKorkeus() { return korkeus; }
	void setLeveys(double l) { leveys = l; }
	void setKorkeus(double k) { korkeus = k; }

	std::string getNimi() { return nimi; }
	virtual double getAla() =0;

};

class Kolmio : public Kuvio2d {
public:
	Kolmio(double l) {
		leveys = l;
	}
	Kolmio(double l, double k) {
		leveys = l;korkeus = k;
	}
	double getAla(){
		return (leveys*korkeus)/2;
	}
};

class Suorakulmio : public Kuvio2d {
public:
	Suorakulmio(double l) {
		leveys = l;
	}
	Suorakulmio(double l, double k) {
		leveys = l;korkeus = k;
	}
	double getAla(){
		return leveys*korkeus;
	}
};

int main() {

	Kuvio2d *kuviot[4]; // Kuvio2d-olioita osoittavia osoittimia sisaltava taulukko

	Kolmio *a = new Kolmio(10.0, 5.0);
	Suorakulmio *b = new Suorakulmio(10);
	Suorakulmio *c = new Suorakulmio(6, 4);
	Kolmio *d = new Kolmio(5.0);
	kuviot[0] = a;
	kuviot[1] = b;
	kuviot[2] = c;
	kuviot[3] = new Kolmio(5.0);

	for (int i = 0; i < 4; i++) {
		std::cout << kuviot[i]->getNimi() << ":" << kuviot[i]->getLeveys() << "*" << kuviot[i]->getKorkeus() << "=" << kuviot[i]->getAla() << std::endl;
	}

	// ****************************************************************************  
	/* Kokeile myös tätä. Mitä ongelmia havaitset? */
	Kuvio2d kuviot1[4]; // Kuvio2d-olioita sisaltava taulukko

	Kolmio a1(10.0, 5.0);
	Suorakulmio b1(10);
	Suorakulmio c1(6, 4);
	Kolmio d1(5.0);
	kuviot1[0] = a1;
	kuviot1[1] = b1;
	kuviot1[2] = c1;
	kuviot1[3] = d1;

	for (int i = 0; i < 4; i++) {
		std::cout << kuviot1[i].getNimi() << ":" << kuviot1[i].getLeveys() << "*" << kuviot1[i].getKorkeus() << "=" << kuviot1[i].getAla() << std::endl;

	}

	return 0;
}