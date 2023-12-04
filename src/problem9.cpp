#include <iostream>
#include <vector>

int findKthMissing(std::vector<int>& arr, int k) {
    int n = arr.size();
    int current = 1;  // Start with the first positive integer

    // Iterate through the array and find missing numbers
    for (int num : arr) {
        while (current < num) {
            // Check if the current number is missing
            if (--k == 0) {
                return current;
            }
            ++current;
        }
        ++current; // Move to the next positive integer after the current number
    }

    // Handle missing numbers after the last element in the array
    while (k > 0) {
        if (--k == 0) {
            return current;
        }
        ++current;
    }

    return -1;  // This line should not be reached
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int result = findKthMissing(arr, k);
    std::cout << result << std::endl;

    return 0;
}
