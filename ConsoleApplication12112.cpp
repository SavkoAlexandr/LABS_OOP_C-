
#include <iostream>
#include <cmath>
#include <exception>
#include <string>

using namespace std; 

// Класс для обработки исключений
class CustomException : public exception {
private:
    string message;
    double errorValue;
    int errorCode;

public:
    CustomException(const string& msg, double value, int code)
        : message(msg), errorValue(value), errorCode(code) {}

    const char* what() const noexcept override {
        return message.c_str();
    }

    double getErrorValue() const { return errorValue; }
    int getErrorCode() const { return errorCode; }
};

// Функция для вычисления Z1
double computeZ1(const double& a, const double& b) {
    if (a <= 0 || b <= 0) {
        throw CustomException("Недопустимые значения корня", a <= 0 ? a : b, 1);
    }

    double numerator = (a - 1) * sqrt(a) - (b - 1) * sqrt(b);
    double denominator = sqrt(pow(a, 3) * b) + b * a + pow(a, 2) - a;

    if (denominator == 0) {
        throw CustomException("Деление на ноль в Z1", denominator, 2);
    }

    return numerator / denominator;
}

// Функция для вычисления Z2
double computeZ2(const double& a, const double& b) {
    if (a <= 0 || b <= 0) {
        throw CustomException("Недопустимые значения корня", a <= 0 ? a : b, 1);
    }

    double numerator = sqrt(a) - sqrt(b);
    double denominator = a;

    if (denominator == 0) {
        throw CustomException("Деление на ноль в Z2", denominator, 2);
    }

    return numerator / denominator;
}

int main() {
    setlocale(LC_ALL, "RU");
    double a, b;
    cout << "Введите значения a и b: ";
    cin >> a >> b;

    try {
        double z1 = computeZ1(a, b);
        double z2 = computeZ2(a, b);

        cout << "Z1 = " << z1 << endl;
        cout << "Z2 = " << z2 << endl;

        if (fabs(z1 - z2) < 1e-6) {
            cout << "Значения Z1 и Z2 приблизительно равны." << endl;
        }
        else {
            cout << "Значения Z1 и Z2 различаются." << endl;
        }

    }
    catch (const CustomException& ex) {
        cerr << "Произошла ошибка: " << ex.what() << endl;
        cerr << "Значение: " << ex.getErrorValue() << ", Код ошибки: " << ex.getErrorCode() << endl;
    }
    catch (const exception& ex) {
        cerr << "Произошла стандартная ошибка: " << ex.what() << endl;
    }

    return 0;
}


