#include "Employee.hpp"
#include <iostream>
#include <format>



Employee::Employee(std::string name) : name(std::move(name)) {
    SetName(this->name);  
}

void Employee::SetName(std::string name) {
    while (true) {
        if (name.size() < 2 || name.size() >= 20) {
            std::cout << "Wrong size! 2-20 symbols\nSet new name: ";
            std::cin >> name;
        }
        else {
            this->name = std::move(name);
            break;
        }
    }
}

std::string Employee::GetName() const {
    return name;
}


SalariedEmployee::SalariedEmployee(std::string name, double salary)
    : Employee(std::move(name)) {
    SetSalary(salary);
}

void SalariedEmployee::SetSalary(double salary) {
    while (true) {
        if (salary < 0.0) {
            std::cout << "Wrong salary!\nSet new salary: ";
            std::cin >> salary;
        }
        else {
            this->salary = salary;
            break;
        }
    }
}

double SalariedEmployee::GetSalary() const {
    return salary;
}

double SalariedEmployee::Earning() const {
    return salary;
}

std::string SalariedEmployee::ToString() const {
    return std::format("Name: {}\nSalary: {:.2f}\n", name, salary);
}


SalariedCommissionEmployee::SalariedCommissionEmployee(std::string name, double salary,
    double sales, double commissionRate)
    : SalariedEmployee(std::move(name), salary) {
    SetSales(sales);
    SetCommissionRate(commissionRate);
}

void SalariedCommissionEmployee::SetSales(double sales) {
    while (true) {
        if (sales < 0.0) {
            std::cout << "Wrong sales!\nSet new sales: ";
            std::cin >> sales;
        }
        else {
            this->sales = sales;
            break;
        }
    }
}

void SalariedCommissionEmployee::SetCommissionRate(double commissionRate) {
    while (true) {
        if (commissionRate < 0.0 || commissionRate > 1.0) {
            std::cout << "Wrong commissionRate!\nSet new commissionRate: ";
            std::cin >> commissionRate;
        }
        else {
            this->commissionRate = commissionRate;
            break;
        }
    }
}

double SalariedCommissionEmployee::GetSales() const { return sales; }
double SalariedCommissionEmployee::GetCommissionRate() const { return commissionRate; }

double SalariedCommissionEmployee::Earning() const {
    return SalariedEmployee::Earning() + sales * commissionRate;
}

std::string SalariedCommissionEmployee::ToString() const {
    return std::format("{}Sales: {:.2f}\nRate: {:.1f}%\nTotal earning: {:.2f}\n",
        SalariedEmployee::ToString(), sales, commissionRate * 100, Earning());
}