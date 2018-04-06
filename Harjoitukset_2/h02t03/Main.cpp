#include <iostream>

class Perusluokka{
public:
	void aseta_arvo(int uusi_arvo){
		arvo = uusi_arvo;
	}
	int palauta_arvo() const{
		return arvo;
	}
	void kerro(int kerroin){
		arvo = arvo * kerroin;
	}

	Perusluokka(){}
	Perusluokka(int uusi_arvo) : arvo(uusi_arvo) {}
	~Perusluokka(){}
private:
	int arvo;  // luokan ainoa tietojäsen!
};

int main(){
	Perusluokka p;
	p.aseta_arvo(2);
	std::cout << p.palauta_arvo() << std::endl;

	p.kerro(2);
	std::cout << p.palauta_arvo() << std::endl;
}