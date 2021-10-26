#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    setlocale(LC_ALL, "ru_RU.UTF-8");

    cout << "Протабулировать функцию от x = -4 до x = 4 c шагом 0.5";

    cout << right << "\n\n";

    cout << left << setw(5) << "|X";

    cout << left << setw(7) << "|Y";

    cout << right << "|\n";

    cout << right << "|----|------|\n";

    cout.fill(' ');

    for (double x = -4; x <= 4; x = x + 0.5) {
        if ((x - 1) != 0) {
            cout.precision(1);
            cout << right << fixed << '|' << setw(4) << x;
            cout.precision(3);
            cout << right << fixed << '|' << setw(6) << (x * x - 2 * x + 2) / (x - 1);
            cout << right << "|\n";
        } else {
            cout.precision(1);
            cout << right << fixed << '|' << setw(4) << x;
            cout << right << fixed << '|' << setw(6) << "   н/р";
            cout << right << "|\n";
        }

    }

}