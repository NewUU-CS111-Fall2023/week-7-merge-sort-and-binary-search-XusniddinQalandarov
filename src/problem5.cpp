#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>  // Include the algorithm header for std::reverse

// Structure to store element-frequency pairs in the priority queue
struct ElementFrequency {
    int element;
    int frequency;

    bool operator>(const ElementFrequency& other) const {
        return frequency > other.frequency;
    }
};

std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    // Count the frequency of each element using a hash map
    std::unordered_map<int, int> frequencyMap;
    for (int num : nums) {
        frequencyMap[num]++;
    }

    // Create a priority queue (min heap) to store element-frequency pairs
    std::priority_queue<ElementFrequency, std::vector<ElementFrequency>, std::greater<ElementFrequency>> minHeap;

    // Insert elements into the priority queue
    for (auto it = frequencyMap.begin(); it != frequencyMap.end(); ++it) {
        minHeap.push({it->first, it->second});

        // Keep the size of the priority queue at most k
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    // Extract the k most frequent elements from the priority queue
    std::vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().element);
        minHeap.pop();
    }

    // Reverse the result vector to have elements in descending order of frequency
    std::reverse(result.begin(), result.end());

    return result;
}

int main() {
    int n, k;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    std::cin >> k;

    std::vector<int> result = topKFrequent(nums, k);

    // Output the result
    for (int num : result) {
        std::cout << num << " ";
    }

    return 0;
}
