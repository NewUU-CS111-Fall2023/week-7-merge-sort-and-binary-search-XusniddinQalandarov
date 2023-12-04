#include <iostream>
#include <vector>

int findMissingNumber(const std::vector<int>& nums, int n) {
    // Calculate the expected sum of the first n natural numbers
    int expectedSum = n * (n + 1) / 2;

    // Calculate the actual sum of the given array
    int actualSum = 0;
    for (int num : nums) {
        actualSum += num;
    }

    // The missing number is the difference between the expected and actual sums
    return expectedSum - actualSum;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> nums(n - 1);  // The array size is n-1
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> nums[i];
    }

    // Find and output the missing number
    int missingNumber = findMissingNumber(nums, n);
    std::cout << missingNumber << std::endl;

    return 0;
}
