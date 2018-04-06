#include <iostream> 
#include <string>

using namespace std;

class Hotelli {
public:
	Hotelli() { cout << "Hotellin konstruktori\n"; };
	virtual ~Hotelli() { cout << "Hotellin destruktori\n"; };

	virtual bool isKavelymatka() = 0;

	void setHuoneita(int num);
	int getHuoneita();
	void setKuvaus(string k);
	string getKuvaus();

protected:
	int huoneita;
	string kuvaus;
};

class KaupunginHotelli : public Hotelli {
public:
	KaupunginHotelli() { cout << "KaupunginHotellin konstruktori\n"; };
	~KaupunginHotelli() { cout << "KaupunginHotellin destruktori\n"; };
	void setEtaisyys(float);
	float getEtaisyys();
	void setTiedot(float, int, string);
	bool isKavelymatka();
private:
	float etaisyys;

};

void Hotelli::setHuoneita(int lkm) {
	huoneita = lkm;
}

int Hotelli::getHuoneita() {
	return huoneita;
}

void Hotelli::setKuvaus(string kuv) {
	kuvaus = kuv;
}

string Hotelli::getKuvaus() {
	return kuvaus;
}

// KaupunginHotelli - peritty Hotellista

void KaupunginHotelli::setEtaisyys(float kms) {
	etaisyys = kms;
}

float KaupunginHotelli::getEtaisyys() {
	return etaisyys;
}

void KaupunginHotelli::setTiedot(float km, int lkm, string kuv) {
	etaisyys = km;
	huoneita = lkm;
	kuvaus = kuv;

}
bool KaupunginHotelli::isKavelymatka() {
	if (etaisyys <= 2.0)
		return true;
	return false;
}


int main() {
	int x;
	float a = 0; int b = 0; string c = "";

	cout << "Anna hotellien lukumaara väliltä 3 - 5: " << endl;
	cin >> x;

	if (x >= 3 && x <= 5) {
		int huoneet = 0;
		KaupunginHotelli *taulu = new KaupunginHotelli[x];

		cout << "Aseta: etaisyys >> huoneet >> kuvaus " << endl;

		for (int i = 0; i < x; i++) {
			cin >> a >> b >> c;
			taulu[i].setTiedot(a, b, c);

		}
		for (int i = 0; i < x; i++) {
			huoneet += taulu[i].getHuoneita();
		}
		for (int i = 0; i < x; i++) {
			cout << "hotelli nro: " << i << "	" << "kavelu: " << taulu[i].isKavelymatka() << endl;
		}

		delete[]taulu;

		cout << "huoneita oli yhteensä: " << huoneet << endl;
	}
	else
	{
		cout << "hajotit tietokoneen" << endl;
	}
}

