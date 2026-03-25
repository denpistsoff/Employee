#include "Employee.hpp"
#include <Windows.h>
#include <vector>
#include <memory>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Демонстрация динамического полиморфизма
    std::vector<std::unique_ptr<Employee>> employees;

    employees.push_back(std::make_unique<SalariedEmployee>("Иван Иванов", 85000.0));
    employees.push_back(std::make_unique<SalariedCommissionEmployee>("Пётр Петров", 45000.0, 1200000.0, 0.12));
    employees.push_back(std::make_unique<SalariedEmployee>("Анна Сидорова", 120000.0));
    employees.push_back(std::make_unique<SalariedCommissionEmployee>("Мария Козлова", 60000.0, 850000.0, 0.08));

    std::cout << "=== Список сотрудников и их заработок ===\n\n";

    for (const auto& emp : employees) {
        std::cout << emp->ToString() << "------------------------------\n";
    }

    std::cout << "Общее количество сотрудников: " << employees.size() << "\n";

    return 0;
}