#include <iostream>
#include <fstream>
#include <conio.h>

#define MAX_NAME_LENGTH 100;
#define MAX_PRODUCT_NAME_LENGTH 10;

const int max_name_length = MAX_NAME_LENGTH;
const int max_prod_name_length = MAX_PRODUCT_NAME_LENGTH;

struct order {
	char   name[max_prod_name_length];
	int    amount;
	double price;
};

int main(int argv, char* argc[]) {
	int n = 5;
	while (n--) {
		std::cout << argc[n] << std::endl;
	}
	int max_amount = atoi(argc[3]);
	double max_price = atof(argc[4]);
	std::ifstream bin_in(argc[1], std::ios::in | std::ios::binary);
	std::ofstream out(argc[2]);

	out << argc[1] << std::endl;
	order ord;
	while (bin_in.read((char*)&ord, sizeof ord)) {
		if (ord.amount < max_amount || ((ord.amount * ord.price) < max_price)) {
			out << ord.name << " " << ord.amount << " " << (ord.amount * ord.price) << "\n";
		}
	}
	bin_in.close();
	out.close();
	std::cout << "Success! Press enter\n";
	_getch();
	return 0;
}