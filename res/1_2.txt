#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8"); // установка русского

    double a, b;

    cout << "Введите число а:" << endl;
    cin >> a;

    cout << "Введите число b:" << endl;
    cin >> b;

    printf("Сумма: %.3f \n", a + b);
    printf("Разность: %.3f \n", a - b);
    printf("Произведение: %.3f \n", a * b);
    if (b == 0) {
        cout << "Частное: делить на ноль нельзя!" << endl;
    }
    else {
        printf("Частное: %.3f \n", a / b);
    }

    return 0;
}
