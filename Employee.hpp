#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <iostream>
#include <string>
#include <format>
#include <vector>

class Employee {
public:
    explicit Employee(std::string name);
    virtual ~Employee() = default;                  

    virtual void SetName(std::string name);
    std::string GetName() const;

    virtual double Earning() const = 0;
    virtual std::string ToString() const = 0;

protected:
    std::string name;
};


class SalariedEmployee : public Employee {
public:
    SalariedEmployee(std::string name, double salary);

    void SetSalary(double salary);
    double GetSalary() const;

    double Earning() const override;
    std::string ToString() const override;

private:
    double salary = 0.0;
};


class SalariedCommissionEmployee final : public SalariedEmployee {
public:
    SalariedCommissionEmployee(std::string name, double salary,
        double sales, double commissionRate);

    void SetSales(double sales);
    void SetCommissionRate(double commissionRate);

    double GetSales() const;
    double GetCommissionRate() const;

    double Earning() const override;
    std::string ToString() const override;

private:
    double sales = 0.0;
    double commissionRate = 0.0;  
};

#endif // EMPLOYEE_HPP