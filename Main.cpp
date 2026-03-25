#include "SalariedEmpoyee.hpp"
#include "SalariedCommissionEmployee.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	SalariedEmpoyee one("Alex", -10000);
	std::cout << one.toString();

	SalariedCommissionEmployee two("Alex", 2000, 10000000, 0.3);
	std::cout << two.toString();



	return 0;
}