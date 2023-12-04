#include <iostream>
#include <vector>

std::vector<int> searchInsertPosition(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return {1, mid};  // Target is found
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Target is not found, return -1 and the index where it would be inserted
    return {-1, left};
}

int main() {
    int n, target;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    std::cin >> target;

    std::vector<int> result = searchInsertPosition(nums, target);

    // Output the result
    for (int value : result) {
        std::cout << value << " ";
    }

    return 0;
}
