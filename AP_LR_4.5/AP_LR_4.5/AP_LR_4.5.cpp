#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    double x, y, R;
    cout << "R = "; cin >> R;

    srand((unsigned)time(NULL));

    cout << "\n--- Sposib 1: Vvedennya z klaviatury ---\n";
    for (int i = 0; i < 10; i++) {
        cout << "x = "; cin >> x;
        cout << "y = "; cin >> y;

        // Умова: точка в колі та між двома прямими (сектор зліва)
        bool inCircle = (x * x + y * y <= R * R);
        bool inWedge = (y <= -x && y >= x);

        if (inCircle && inWedge) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }

    cout << "\n--- Sposib 2: Vypadkova heneratsiya ---\n";
    cout << fixed;
    for (int i = 0; i < 10; i++) {
        // Генерація в діапазоні [-R; R]
        x = -R + 2.0 * R * rand() / RAND_MAX;
        y = -R + 2.0 * R * rand() / RAND_MAX;

        bool inCircle = (x * x + y * y <= R * R);
        bool inWedge = (y <= -x && y >= x);

        cout << "x = " << setw(8) << setprecision(4) << x
            << " y = " << setw(8) << setprecision(4) << y << " -> ";

        if (inCircle && inWedge) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }
    return 0;
}