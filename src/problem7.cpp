#include <iostream>

double recursivePow(double x, int n) {
    // Base case: x^0 = 1
    if (n == 0) {
        return 1;
    }

    // Recursive case: x^n = x * x^(n-1)
    return x * recursivePow(x, n - 1);
}

int main() {
    double x;
    int n;

    // Input
    std::cout << "Enter the base (x): ";
    std::cin >> x;

    std::cout << "Enter the exponent (n): ";
    std::cin >> n;

    // Output
    double result = recursivePow(x, n);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
