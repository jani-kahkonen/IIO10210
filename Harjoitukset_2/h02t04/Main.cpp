#include <iostream>
#include <assert.h>

class Perusluokka{
public:
	void aseta_rajat(int ar, int yr){ _ar = ar; _yr = yr;	}
	void aseta_arvo(int ua){
		assert(ua <= _yr && ua >= _ar);
		_arvo = ua;
	}

	long int palauta_arvo() const{	return _arvo;	}
	void tulosta() const{	std::cout << _arvo << std::endl;	}

	Perusluokka() : _arvo(0), _ar(0), _yr(0) {}
	Perusluokka(int ua, int ar, int yr) : _arvo(ua), _ar(ar), _yr(yr) {}
	~Perusluokka(){}
private:
	long int _arvo;
	int _ar, _yr;
};

int main(){
	Perusluokka p;

	p.aseta_rajat(2, 4);
	p.aseta_arvo(2);
	std::cout << p.palauta_arvo() << std::endl;

	//p.aseta_rajat(4, 2);
	//p.aseta_arvo(3);
	//std::cout << p.palauta_arvo() << std::endl;
}