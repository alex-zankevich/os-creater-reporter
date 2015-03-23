#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <string>

#define MAX_NAME_LENGTH 200;
#define MAX_PRODUCT_NAME_LENGTH 10;

const int max_name_length = MAX_NAME_LENGTH;
const int max_prod_name_length = MAX_PRODUCT_NAME_LENGTH;

const std::string creater_path = "Creater.exe";
const std::string reporter_path = "Reporter.exe";

struct order {
	char   name[max_prod_name_length];
	int    amount;
	double price;
};

int main()
{
	char lpszAppName[max_name_length];
	std::string bin_file_name;
	std::cout << "Enter file name : " << std::endl;
	std::getline(std::cin,bin_file_name);

	sprintf_s(lpszAppName,"%s %s",creater_path.c_str(),bin_file_name.c_str());

	STARTUPINFO si;
	PROCESS_INFORMATION piApp;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);

	if (!CreateProcess(NULL, 
		lpszAppName,
		NULL,
		NULL,
		FALSE,
		CREATE_NEW_CONSOLE, 
		NULL, 
		NULL,
		&si,
		&piApp)) return 0;

	WaitForSingleObject(piApp.hProcess, INFINITE);

	std::ifstream bfin(bin_file_name);

	order list;
	while (bfin.read((char*)&list, sizeof list))
		std::cout << list.name << list.amount << list.price << std::endl;

	bfin.close();

	int max_amount;
	double max_price;
	std::string report_file;

	std::cout << "Input name of report file: ";
	std::cin >> report_file;
	std::cout << "Input max_amount and max_price: ";
	std::cin >> max_amount >> max_price;

	char lpszAppName_2[max_name_length*2];
	sprintf_s(lpszAppName_2, "%s %s %s %i %f", reporter_path.c_str(), bin_file_name.c_str(), report_file.c_str(), max_amount, max_price);

	STARTUPINFO si_2;
	PROCESS_INFORMATION piApp_2;
	ZeroMemory(&si_2, sizeof(STARTUPINFO));
	si_2.cb = sizeof(STARTUPINFO);

	if (!CreateProcess(NULL,
		lpszAppName_2,
		NULL,
		NULL,
		FALSE,
		CREATE_NEW_CONSOLE,
		NULL,
		NULL,
		&si_2,
		&piApp_2)) return 0;

	WaitForSingleObject(piApp_2.hProcess, INFINITE);
	
	return 0;

}