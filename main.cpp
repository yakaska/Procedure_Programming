#include <iostream>
#include <algorithm>
#include <random>
#include <string>

using namespace std;

int *generateNumber(int number[]);

string checkNumber(int number, const int *generatedNumber);

bool isRightNumber(const string &str);

// БЫКИ и КОРОВЫ
// ЯКУШЕВ В.П. ИВБО-04-21
int main() {

    setlocale(LC_ALL, "ru_RU.UTF-8");

    int generatedNumber[4];

    int *pointerToNumber = generateNumber(generatedNumber);

    cout << pointerToNumber[0] << pointerToNumber[1] << pointerToNumber[2] << pointerToNumber[3] << endl;

    printf("Игра Быки и Коровы!");
    printf("\nПравила: '+' это бык, '-' это корова. \nКомпьютер придумывает 4-значное число. \nПлюс ставится, когда угадано число и его место, минус если не угадано");
    printf("\nЗадача: угадать число, загаданное компьютером, т.е получить все плюсы.");

    bool win = false;

    string userNumber;

    while (!win) {
        printf("\nВведите число:");
        cin >> userNumber;
        if (isRightNumber(userNumber)) {
            string result = checkNumber(stoi(userNumber), pointerToNumber);
            if (result == "++++") {
                printf("Победа! Все числа угаданы!");
                printf(" Загаданное число: %s", userNumber.c_str());
                win = true;
            } else {
                printf("Продолжаем... ");
                printf("Ваш результат: минусов: %d, плюсов: %d",
                       count(result.begin(), result.end(), '-'),
                       count(result.begin(), result.end(), '+')
                       );
            }
        } else {
            printf("Введите ВЕРНОЕ число!");
            continue;
        }

    }

}

bool isRightNumber(const string &str) {
    for (char const &c: str) {
        if (std::isdigit(c) == 0) return false;
    }
    int number = atoi(str.c_str());
    if (number > 999 && number < 10000) {
        return true;
    } else return false;
}

string checkNumber(int userNumber, const int *generatedNumber) {
    string result;
    int userNumberArray[4];
    userNumberArray[0] = userNumber / 1000;
    userNumberArray[1] = userNumber / 100 % 10;
    userNumberArray[2] = userNumber / 10 % 10;
    userNumberArray[3] = userNumber % 10;
    int temp[] = {generatedNumber[0], generatedNumber[1], generatedNumber[2], generatedNumber[3]};
    for (int i = 0; i < 4; i++) {
        if (userNumberArray[i] == temp[i]) result.append("+");
        else if (find(begin(temp), end(temp), userNumberArray[i]) != end(temp))result.append("-");
    }
    return result;
}

int *generateNumber(int *number) {
    const int SIZE = 10;

    int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    shuffle(digits, digits + SIZE, mt19937(random_device()()));

    if (digits[0] == 0) {
        digits[0] = digits[1];
        digits[1] = 0;
    }

    number[0] = digits[0];
    number[1] = digits[1];
    number[2] = digits[2];
    number[3] = digits[3];

    return number;
}