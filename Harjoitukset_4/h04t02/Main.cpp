#include <iostream>
#include <string>

class Hotelli {
public:
	virtual void setHuoneita() {}
	virtual int getHuoneita() { return _huoneita; }
	virtual void setKuvaus() {}
	virtual std::string getKuvaus() { return _kuvaus; }
	virtual bool isKavelymatka() = 0;

	Hotelli() { std::cout << "+Hotellin" << std::endl; }
	~Hotelli() { std::cout << "-Hotellin" << std::endl; }
protected:
	int _huoneita;
	std::string _kuvaus;
};

class KaupunginHotelli : public Hotelli {
public:
	void setTiedot(double a, int b, std::string c) { _etaisyys = a; _huoneita = b; _kuvaus = c; }
	void setEtaisyys() {}
	double getEtaisyys() { return _etaisyys; }
	bool isKavelymatka() {
		if (_etaisyys > 10) {
			return true;
		}
		return false;
	}

	KaupunginHotelli() { std::cout << "+KaupunginHotelli" << std::endl; }
	~KaupunginHotelli() { std::cout << "-KaupunginHotelli" << std::endl; }
private:
	double _etaisyys;
};

class KetjuHotelli : public KaupunginHotelli {
public:
	void setHuonehinta(){}
	int getHuonehinta() { return _huoneHinta; }
	void setEtukortti(bool a) {
		_alennus = a;
	}
	bool isEtukortti(){
		if (_alennus) {
			_huoneAlennus = _huoneHinta - 20;
			return true;
		}
		return false;
	}
	float getAlennus() { return _huoneAlennus; }

	KetjuHotelli(){ std::cout << "+KetjuHotelli" << std::endl; }
	~KetjuHotelli() { std::cout << "-KetjuHotelli" << std::endl; }
private:
	bool _alennus;
	int _huoneHinta = 100, _huoneAlennus;
};

int main() {
	KaupunginHotelli *ht = new KaupunginHotelli;

	ht->setTiedot(11, 80, "JyväsHovi");
	std::cout << ht->getEtaisyys() << std::endl;

	if (ht->isKavelymatka()) {
		std::cout << "ei kavelymatkan paassa" << std::endl;
	}
	else {
		std::cout << "on kavelymatkan paassa" << std::endl;
	}

	delete ht;

	std::cout << std::endl;

	KetjuHotelli *kh = new KetjuHotelli;

	kh->setTiedot(11, 80, "JyväsHovi");
	kh->setEtukortti(true);
	std::cout << "normaali hinta: " << kh->getHuonehinta() << std::endl;

	if (kh->isEtukortti()) {
		std::cout << "alennettu hinta: " << kh->getAlennus() << std::endl;
	}
	else {
		std::cout << " ei alennusta: " << kh->getAlennus() << std::endl;
	}

	delete kh;
}