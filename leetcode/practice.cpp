#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> umap; // Store value and index

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        
        // Check if complement exists in map
        if (umap.find(complement) != umap.end()) {
            return {umap[complement], i};
        }
        umap[nums[i]] = i;
    }
    return {}; // Return empty if no solution
}

int main() {
    vector<int> a = {1, 0, 5, 2, 4};
    int target = 6;

    vector<int> result = twoSum(a, target);
    if (!result.empty()) {
        cout << "Indices: (" << result[0] << ", " << result[1] << ")\n";
    } else {
        cout << "No valid pair found\n";
    }
}