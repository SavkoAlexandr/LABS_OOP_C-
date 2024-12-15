#include <iostream>
#include <cmath>
#include <functional>
using namespace std;

class Solver {
protected:
    double a, b, eps; 
    function<double(double)> f; 

    virtual double next(double x) = 0; 

public:
    Solver(double a, double b, double eps, function<double(double)> f)
        : a(a), b(b), eps(eps), f(f) {}

    double solve() {
        double x = (a + b) / 2.0; 
        while (fabs(f(x)) > eps) {
            x = next(x);
        }
        return x;
    }
};

// Метод хорд
class ChordMethod : public Solver {
public:
    ChordMethod(double a, double b, double eps, function<double(double)> f)
        : Solver(a, b, eps, f) {}

protected:
    double next(double x) override {
        return x - f(x) * (b - x) / (f(b) - f(x)); 
    }
};

// Метод Ньютона
class NewtonMethod : public Solver {
    function<double(double)> df;

public:
    NewtonMethod(double a, double b, double eps, function<double(double)> f, function<double(double)> df)
        : Solver(a, b, eps, f), df(df) {}

protected:
    double next(double x) override {
        return x - f(x) / df(x); 
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    
    auto f = [](double x) { return x * x * x - x - 2; };
    auto df = [](double x) { return 3 * x * x - 1; }; 

    double a = 1, b = 2, eps = 1e-6;

    // Решение методом хорд
    ChordMethod chordSolver(a, b, eps, f);
    cout << "Корень (метод хорд): " << chordSolver.solve() << endl;

    // Решение методом Ньютона
    NewtonMethod newtonSolver(a, b, eps, f, df);
    cout << "Корень (метод Ньютона): " << newtonSolver.solve() << endl;

    return 0;
}
