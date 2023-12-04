#include <iostream>
#include <vector>

int kthFactor(int n, int k) {
    std::vector<int> factors;

    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            factors.push_back(i);
            if (factors.size() == k) {
                return i;  // Return the k-th factor
            }
        }
    }

    return -1;  // If there are fewer than k factors
}

int main() {
    int n, k;
    std::cin >> n >> k;

    int result = kthFactor(n, k);
    std::cout << result << std::endl;

    return 0;
}
