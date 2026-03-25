#ifndef _EMPLOYEE_HPP_
#define _EMPLOYEE_HPP_

#include <iostream>
#include <Windows.h>
#include <string>
#include <format>

class Employee
{
public:
	Employee(std::string name);

	virtual void SetName(std::string name);
	std::string GetName() const;

	void SetSalary(double salary);
	double GetSalary() const;

	double Earning() const;
	std::string toString() const;

	void SetSales(double sales);
	void SetCommissionRate(double commissionRate);

protected:
	std::string name{};
};


class SalariedEmployee : public Employee
{
public:

	SalariedEmployee(std::string name, double salary);
	void SetSalary(double salary);
	double GetSalary() const;

private:
	std::string name{};
	double salary = 0.0;
};

class SalariedCommissionEmployee final : public Employee
{
public:
	SalariedCommissionEmployee(std::string name, double salary, double sales, double commissionRate);

	void SetSales(double sales);
	void SetCommissionRate(double commissionRate);

	double GetSales() const;
	double GetCommisiionRate() const;

private:
	double sales = 0.0;
	double commissionRate = 0.0;

};



#endif // !_EMPLOYEE_HPP_