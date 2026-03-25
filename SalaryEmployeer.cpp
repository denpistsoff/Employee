#include "Employee.hpp"

Employee::Employee(std::string name, double salary)
{
	SetName(name);
	SetSalary(salary);
}

void Employee::SetName(std::string name)
{
	while (true)
	{
		if (name.size() < 2 || name.size() >= 20)
		{
			std::cout << "Wrong size! 2-20 symbols\nSet new name: ";
			std::cin >> name;
		}
		else
		{
			this->name = name;
			break;
		}
	}
}

void SalariedEmployee::SetSalary(double salary)
{
	while (true)
	{
		if (salary < 0.0)
		{
			std::cout << "Wrong salary!\nSet new salary: ";
			std::cin >> salary;
		}
		else
		{
			this->salary = salary;
			break;
		}
	}
}



std::string Employee::GetName() const
{
	return name;
}

double SalariedEmployee::GetSalary() const
{
	return salary;
}

double Employee::Earning() const
{
	return SalariedEmployee::GetSalary();
}

std::string SalariedEmployee::toString const{
	return std::format("Name: {}\nSalary: {:.2f}\n", name, salary);
}

