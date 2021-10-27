#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

char valueFromDecimal(int num) {
    if (num >= 0 && num <= 9)
        return (char) (num + '0');
    else
        return (char) (num - 10 + 'A');
}

void reverseString(char *str) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

char *fromDecimal(char res[], int base, int inputNum) {
    int index = 0;

    while (inputNum > 0) {
        res[index++] = valueFromDecimal(inputNum % base);
        inputNum /= base;
    }
    res[index] = '\0';

    reverseString(res);

    return res;
}

int valueToDecimal(char c) {
    if (c >= '0' && c <= '9')
        return (int) c - '0';
    else
        return (int) c - 'A' + 10;
}


int toDecimal(char *str, int base) {
    int len = strlen(str);
    int power = 1;
    int num = 0;
    int i;

    for (i = len - 1; i >= 0; i--) {
        if (valueToDecimal(str[i]) >= base) {
            printf("Неверное число или система счисления не совпадает с числом");
            return -1;
        }

        num += valueToDecimal(str[i]) * power;
        power = power * base;
    }

    return num;
}


int main() {
    char str[] = "FFFFFFFFFFFFFFFF";
    char res[100];
    int base = 16;
    int toBase = 8;
    int decimal;

    setlocale(LC_ALL, "ru_RU.UTF-8");
    cout << "Введите число для перевода в другую СС: ";
    cin >> str;
    cout << endl;
    cout << "Введите основание СС введенного числа: ";
    cin >> base;
    cout << endl;
    cout << "Введите конечное основание СС: ";
    cin >> toBase;
    cout << endl;

    decimal = toDecimal(str, base);
    printf("Из числа %s в %.i - ичной системе счисления получено число %s в %.i - ичной системе счисления",
           str,
           base,
           fromDecimal(res, toBase, decimal),
           toBase
    );
    return 0;
}
