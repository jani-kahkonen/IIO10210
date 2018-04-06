#include <iostream>

double laske_neg( const int pos, const int neg) {
	double pro = 0;
	return pro = (double)neg / (double)(pos + neg) * 100.0;
}

double laske_pos(const int pos, const int neg) {
	double pro = 0;
	return pro = (double)pos / (double)(pos + neg) * 100.0;
}

int main() {
	int luku = -1, pos = 0, neg = 0;
	while (luku != 0) {
		std::cout << "Syota kokonaisluku: " << std::endl;
		std::cin >> luku;
		if (luku < 0) {
			neg++;
		}
		else if (luku > 0) {
			pos++;
		}
	}
	std::cout << "-------------------" << std::endl;
	std::cout << "Neg: " << neg << "kpl" << " " << laske_neg( pos, neg ) << "%" << std::endl;
	std::cout << "Pos: " << pos << "kpl"  << " " << laske_pos(pos, neg  ) << "%" << std::endl;
	std::cout << "Yht: " << pos + neg << "kpl" << " " << laske_pos(pos, neg) + laske_neg(pos, neg) << "%" << std::endl;
}