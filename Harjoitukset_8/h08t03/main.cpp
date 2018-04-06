#include <iostream>
#include <cstdlib>
using namespace std;
struct Alkio {
	int luku;
	Alkio *seuraava;
};
int etsiAlkio(Alkio *p_alku, int apu);
int PoistaLuku(Alkio*&, int);
int LisaaLuku(Alkio *&, int);
void TulostaLuvut(Alkio *);
int KysyValinta();

int main() {
	Alkio *alku = NULL;
	int vastaus, ok, apu;
	vastaus = KysyValinta();
	while (vastaus != 0) {
		switch (vastaus) {
		case 1:
			cout << "\nLuku: ";
			cin >> apu;
			ok = LisaaLuku(alku, apu);
			if (ok == 0)
				cout << "Tilanvaraus ei onnistunut\n";
			break;
		case 2:
			TulostaLuvut(alku);
			break;
		case 3:
			cout << "\n Poistettava Luku: ";
			cin >> apu;
			if (ok == PoistaLuku(alku, apu))
				cout << "Poistaminen ei onnistunut\n";
			break;
		case 4:
			cout << "\n Etsittävä luku ";
			cin >> apu;
			if (!ok == etsiAlkio(alku, apu)) {
				cout << "NULL\n";
			}
		
			
			break;
		default:	cout << "\nVirheellinen valinta";
		} //switch
		vastaus = KysyValinta();
	} //while
	Alkio *seuraava;
	Alkio *kohdalla = alku;
	while (kohdalla) {
		seuraava = kohdalla->seuraava;
		delete kohdalla;
		kohdalla = seuraava;
	}
	return 0;
}

int PoistaLuku(Alkio *&p_alku, int p_luku) {

	Alkio * edellinen = NULL, *pois = p_alku; // POISTETTAVA VUOROSSA

	while (pois != NULL && pois->luku != p_luku) { //ei listan lopppu, ei poistettava: plarataan etteenpäin.
		edellinen = pois;
		pois = pois->seuraava;
	}
	if (pois == NULL)
	{
		return 0;
	}
	else
	{
		if (pois == p_alku) {
			p_alku = pois->seuraava;
		}
		else
		{
			edellinen->seuraava = pois->seuraava;
		}
		delete pois;
	}
	return 0;
}

int KysyValinta() {
	int vastaus;
	cout << "\nVALIKKO";
	cout << "\n1) Lisää uusi luku";
	cout << "\n2) Näytä kaikki luvut";
	cout << "\n3) Poista luku";
	cout << "\n4) Etsi alkio";
	cout << "\n0) Lopetus\n";
	cin >> vastaus;
	//system("cls");
	return vastaus;
}

int LisaaLuku(Alkio *&p_alku, int p_luku) { // *& = viittaus osoittimeen
	Alkio *uusi = new Alkio;

	if (uusi) {

		uusi->luku = p_luku;
		uusi->seuraava = NULL;
		Alkio *ed = NULL;
		Alkio *seur = p_alku;

		while (seur && seur->luku < uusi->luku) {
			ed = seur;
			seur = seur->seuraava;

		}

		if (seur && uusi->luku <= seur->luku) {
			uusi->seuraava = seur;
		}
		if (ed) {
			ed->seuraava = uusi;
		}
		else
		{
			p_alku = uusi;
			uusi->seuraava = seur;
		}
		return 1;
	}
	else return 0;

}

int etsiAlkio(Alkio *p_alku, int apu) {
	Alkio *kohdalla;
	kohdalla = p_alku;
	while (kohdalla) {
		if (kohdalla->luku == apu) {
			
			cout << " osoite: " << &kohdalla->luku;
			break;
			
		}
		else {
			kohdalla = kohdalla->seuraava;
		}
	}
	return 0;
}


void TulostaLuvut(Alkio *p_alku) {
	Alkio *kohdalla;
	kohdalla = p_alku;
	while (kohdalla) {
		cout << "\nLuku: " << kohdalla->luku;
		cout << " osoite: " << &kohdalla->luku;
		kohdalla = kohdalla->seuraava;
	}
}
