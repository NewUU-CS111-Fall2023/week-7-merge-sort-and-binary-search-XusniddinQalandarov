#include <iostream>
#include <vector>
#include <algorithm>

int countLessEqual(const std::vector<std::vector<int>>& matrix, int target) {
    int count = 0;
    int n = matrix.size();
    int i = n - 1; // Start from the bottom-left corner

    for (int j = 0; j < n; ++j) {
        while (i >= 0 && matrix[i][j] > target) {
            --i;
        }
        count += (i + 1);
    }

    return count;
}

int kthSmallest(const std::vector<std::vector<int>>& matrix, int k) {
    int n = matrix.size();
    int low = matrix[0][0];
    int high = matrix[n - 1][n - 1];

    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = countLessEqual(matrix, mid);

        if (count < k) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    int result = kthSmallest(matrix, k);
    std::cout << result << std::endl;

    return 0;
}
