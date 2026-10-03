#include <iostream>

/**
 * Высчитывает и возвращает платеж в месяц при дифферинцированном кредите.
 *
 *          Параметры:
 *                    procent (double): кредитная годовая ставка в процентах.
 *                    amount (double): сумма, которую планируются взять в кредит.
 *                    year (int): количество лет, на которые взяли кредит.
 *
 *          Возвращаемое значение:
 *                    Функция ничего не возвращает. Выводит в консоль
 *                    платеж за каждый месяц в формате: "В i-й месяц платеж составит: платеж".
 *
 *          Пример вызова:
 *                    DifferentiatedPayment(10,100000,1);
 *                    Возврат:
 *                    В 1-й месяц платеж составит: 834.167
 *                    В 2-й месяц платеж составит: 764.722
 *                    ...
 *                    В 12-й месяц платеж составит: 70.2778
 */
void DifferentiatedPayment(double procent, double amount, int year);

int main() {
    double amount, procent;
    int year;
    std::cout << "Программа вычисляет ежемесячные дифференцированные платежи\n";
    std::cout << "Введите сумму, которую планируется взять в кредит (в рублях):\n";
    std::cin >> amount;
    if (amount <= 0) {
        std::cerr << "Некорректная сумма\n";
        return 1;
    }
    std::cout << "Введите ежегодный процент по кредиту: \n";
    std::cin >> procent;
    if (procent <= 0) {
        std::cerr << "Некорректный процент\n";
        return 1;
    }
    std::cout << "Введите срок на который планируется взять кредит (целое количество лет): \n";
    std::cin >> year;
    if (year <= 0) {
        std::cerr << "Неккоректное количество лет\n";
        return 1;
    }
    DifferentiatedPayment(procent, amount, year);

    return 0;
}

/**
 * Описание функции выше.
 */
void DifferentiatedPayment(double procent, double amount, int year) {
    double monthly_rate = (procent / 12.0) / 100.0;
    int mounth = year * 12;
    double OstatDolg = amount;
    double plan = amount / mounth;
    for (int i = 1; i <= mounth; i++) {
        double payment = plan + OstatDolg * monthly_rate;
        std::cout << "В " << i << "-й месяц платеж составит: " << payment << "\n";
        OstatDolg = OstatDolg - plan;
    }
}

