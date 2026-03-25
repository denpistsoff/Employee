#include "Employee.hpp"

SalariedCommissionEmployee::SalariedCommissionEmployee(std::string name, double salary, double sales, double commissionRate)
	: SalariedEmployee(name, salary)
{
	SetSales(sales);
	SetCommissionRate(commissionRate);
}

void SalariedCommissionEmployee::SetSales(double sales)
{
	while (true)
	{
		if (sales < 0.0)
		{
			std::cout << "Wrong sales!\nSet new sales: ";
			std::cin >> sales;
		}
		else
		{
			this->sales = sales;
			break;
		}
	}
}

void SalariedCommissionEmployee::SetCommissionRate(double commissionRate)
{
	while (true)
	{
		if (commissionRate < 0.0 || commissionRate > 1.0)
		{
			std::cout << "Wrong commissionRate!\nSet new commissionRate: ";
			std::cin >> commissionRate;
		}
		else
		{
			this->commissionRate = commissionRate;
			break;
		}
	}
}

double SalariedCommissionEmployee::GetSales() const
{
	return sales;
}

double SalariedCommissionEmployee::GetCommisiionRate() const
{
	return commissionRate;
}

double SalariedCommissionEmployee::Earning() const
{
	return SalariedEmployee::Earning() + sales + commissionRate;
}

std::string SalariedCommissionEmployee::toString() const
{
	return std::format("{}Sales: {}\nRate: {}\nTotal: {}\n", SalariedEmployee::toString(), sales, commissionRate, Earning());
}


