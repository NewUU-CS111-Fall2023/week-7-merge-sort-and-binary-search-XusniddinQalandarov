#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int T;
    std::cin >> T;

    for (int t = 0; t < T; ++t) {
        int N;
        std::cin >> N;

        std::vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> A[i];
        }

        // Store the remaining numbers after each operation
        std::vector<int> remainingNumbers;

        // Perform N-2 operations
        for (int i = 3; i <= N; i += 2) {
            std::vector<int> medians;

            // Find the medians for each contiguous subarray of odd size greater than 2
            for (int j = 0; j <= N - i; ++j) {
                std::vector<int> subarray(A.begin() + j, A.begin() + j + i);
                std::sort(subarray.begin(), subarray.end());
                medians.push_back(subarray[i / 2]);
            }

            // Find and remove the minimum median value
            int minMedian = *std::min_element(medians.begin(), medians.end());
            auto it = std::find(A.begin(), A.end(), minMedian);
            A.erase(it);

            // Store the remaining numbers after each operation
            remainingNumbers.push_back(minMedian);
        }

        // Add the remaining numbers in the array
        for (int num : A) {
            remainingNumbers.push_back(num);
        }

        // Calculate and print the sum of remaining numbers
        long long sum = 0;
        for (int num : remainingNumbers) {
            sum += num;
        }

        std::cout << sum << std::endl;
    }

    return 0;
}
