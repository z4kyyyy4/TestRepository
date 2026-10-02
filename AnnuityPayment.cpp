#include <iostream>
#include <cmath>

double AnnuityPayment(int procent, int amount, int year);

int main(){
    int procent, amount, year;
    std::cout << "Программа высчитывает ежемесячные платеж при аннуитентном платеже\n";
    std::cout << "Введите сумму, которая планируется взять в кредит (в рублях):\n";
    std::cin >> amount;
    if (amount <= 0) {
        std::cerr << "Некоректная сумма\n";
        return 1;
    }
    std::cout << "Введите процентную ставку в год:\n";
    std::cin >> procent;
    if (procent <= 0) {
        std::cerr << "Некоректный процент\n";
        return 1;
    }
    std::cout << "Введите срок, на который берется кредит (в целых годах):\n";
    std::cin >> year;
    if ((year <= 0) || (year % 1 != 0)) {
        std::cerr << "Некорректный срок\n";
        return 1;
    }
    std::cout << "Ваш примерный ежемесячный платеж по кредиту составит: "
    << AnnuityPayment(procent, amount, year) << " рублей \n";
    return 0;
}

double AnnuityPayment(int procent, int amount, int year){
    const double monthly_rate = (procent / 12.0) / 100.0;
    const int month = year * 12;
    const double l = std::pow(1 + monthly_rate, month);
    return amount * monthly_rate * l / (l - 1);
}
