#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

#define MAX_NAME_LENGTH 100;
#define MAX_PRODUCT_NAME_LENGTH 10;

const int max_name_length = MAX_NAME_LENGTH;
const int max_prod_name_length = MAX_PRODUCT_NAME_LENGTH;

struct order {
	char name[max_prod_name_length];
	int amount;
	double price;
};


int main(int argc, char* argv[]) {
	std::cout << argv[1] << std::endl;
	std::ofstream fout(argv[1], std::ios::binary);
	std::cout << "Input number of orders: ";
	int count;
	std::cin >> count;
	for (int i = 0; i < count; ++i) {
		order tmp;
		std::cout << "Input: name, amount and price : ";
		std::cin >> tmp.name >> tmp.amount >> tmp.price;
		fout.write((const char*)&tmp, sizeof(tmp));
	}
	fout.close();
	std::cout << "Success! Press enter\n";
	_getch();
	return 0;
}

