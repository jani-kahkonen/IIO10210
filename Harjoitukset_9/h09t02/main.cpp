#include <iostream>
#include <vector>

int main() {
	const int N_NUM = 4, L_NUM = 2;
	// create a vector to store int
	std::vector<int> vecA, vecB, vecC, vecD, vecE;

	/*-------------------------------------------------------------*/

	// push values into the vector A B
	vecA.push_back(1);
	vecA.push_back(2);
	vecA.push_back(3);
	vecA.push_back(4);

	vecB.push_back(8);
	vecB.push_back(9);

	// push values into the vector C
	int x = 0;
	for (int i = 0; i < N_NUM; ++i) {
		std::cout << i << ". " << "numero: "; std::cin >> x;
		vecC.push_back(x);
	}

	/*-------------------------------------------------------------*/

	std::cout << "OmatNumerot" << std::endl;

	// access values from the vector
	for (int i = 0; i < N_NUM; ++i) {
		std::cout << "vecC [" << i << "] = " << vecC[i] << std::endl;
	}

	std::cout << "OikeatNumerot" << std::endl;

	// access values from the vector
	for (int i = 0; i < N_NUM; ++i) {
		std::cout << "vecA [" << i << "] = " << vecA[i] << std::endl;
	}

	std::cout << "LisaNumerot" << std::endl;

	// access values from the vector
	for (int i = 0; i < L_NUM; ++i) {
		std::cout << "vecB [" << i << "] = " << vecB[i] << std::endl;
	}

	/*-------------------------------------------------------------*/

	int a = 0, b = 0;

	for (int i = 0; i < N_NUM; ++i) {
		for (int j = 0; j < N_NUM; ++j) {
			if (vecC[i] == vecA[j]) {
				vecD.push_back(vecC[i]);
				++a;
			}
		}
	}

	for (int i = 0; i < N_NUM; ++i) {
		for (int j = 0; j < L_NUM; ++j) {
			if (vecC[i] == vecB[j]) {
				vecE.push_back(vecC[i]);
				++b;
			}
		}
	}

	/*-------------------------------------------------------------*/

	std::cout << "Osuneet numerot:" << std::endl;

	if (a > 0)
	{
		for (int i = 0; i < vecD.size(); ++i) {
			std::cout << "[" << vecD[i] << "]" << " ";
		}
	}
	if (b > 0)
	{
		for (int i = 0; i < vecE.size(); ++i) {
			std::cout << "(" << vecE[i] << ")" << " ";
		}
	}

	std::cout << std::endl;

	if ( a > 0 || b > 0)
	{
		std::cout << "Osumat: " << a << " + " << b << std::endl;
	}
	else
	{
		std::cout << "Ei osumia: " << std::endl;
	}
}