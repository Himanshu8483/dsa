LeetCode 169: Majority Element (C++ Solutions)
Problem Statement:
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.

1. Brute Force Approach (Nested Loops)
Approach:
Iterate through each element and count its occurrences.
If an element occurs more than n/2 times, return it.
Code (C++):
cpp
Copy
Edit
#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == nums[i])
                count++;
        }
        if (count > n / 2)
            return nums[i];
    }
    return -1; // This line should never be reached as per problem statement
}

int main() {
    vector<int> nums = {3, 2, 3};
    cout << "Majority Element: " << majorityElement(nums) << endl;
    return 0;
}
Complexity Analysis:
Time Complexity: O(n^2) (Two nested loops)
Space Complexity: O(1) (No extra space)
2. Using HashMap (Counting Frequency)
Approach:
Use unordered_map to store the frequency of each element.
Return the element with count greater than n/2.
Code (C++):
cpp
Copy
Edit
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> count;
    int n = nums.size();
    
    for (int num : nums) {
        count[num]++;
        if (count[num] > n / 2)
            return num;
    }
    return -1;
}

int main() {
    vector<int> nums = {3, 2, 3};
    cout << "Majority Element: " << majorityElement(nums) << endl;
    return 0;
}
Complexity Analysis:
Time Complexity: O(n) (Single pass)
Space Complexity: O(n) (Extra space for hash map)
3. Sorting Approach
Approach:
Sort the array.
The element at index n//2 is guaranteed to be the majority element.
Code (C++):
cpp
Copy
Edit
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}

int main() {
    vector<int> nums = {3, 2, 3};
    cout << "Majority Element: " << majorityElement(nums) << endl;
    return 0;
}
Complexity Analysis:
Time Complexity: O(n log n) (Sorting)
Space Complexity: O(1) (If sorting is done in place)
4. Boyer-Moore Voting Algorithm (Optimal)
Approach:
Maintain a candidate and a count variable.
Traverse the array:
If count is 0, set candidate = num.
If num == candidate, increase count.
Otherwise, decrease count.
The candidate will be the majority element.
Code (C++):
cpp
Copy
Edit
#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) {
    int count = 0, candidate = 0;

    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }
    
    return candidate;
}

int main() {
    vector<int> nums = {3, 2, 3};
    cout << "Majority Element: " << majorityElement(nums) << endl;
    return 0;
}
Complexity Analysis:
Time Complexity: O(n) (Single pass)
Space Complexity: O(1) (No extra space)
5. Using Divide and Conquer
Approach:
Recursively divide the array into halves.
Find the majority element in both halves.
If both halves agree, return that element.
Otherwise, count both elements and return the one that occurs more.
Code (C++):
cpp
Copy
Edit
#include <iostream>
#include <vector>

using namespace std;

int countFrequency(vector<int>& nums, int left, int right, int target) {
    int count = 0;
    for (int i = left; i <= right; i++)
        if (nums[i] == target)
            count++;
    return count;
}

int majorityHelper(vector<int>& nums, int left, int right) {
    if (left == right)
        return nums[left];

    int mid = left + (right - left) / 2;
    int leftMajor = majorityHelper(nums, left, mid);
    int rightMajor = majorityHelper(nums, mid + 1, right);

    if (leftMajor == rightMajor)
        return leftMajor;

    int leftCount = countFrequency(nums, left, right, leftMajor);
    int rightCount = countFrequency(nums, left, right, rightMajor);

    return (leftCount > rightCount) ? leftMajor : rightMajor;
}

int majorityElement(vector<int>& nums) {
    return majorityHelper(nums, 0, nums.size() - 1);
}

int main() {
    vector<int> nums = {3, 2, 3};
    cout << "Majority Element: " << majorityElement(nums) << endl;
    return 0;
}
Complexity Analysis:
Time Complexity: O(n log n) (Recursion depth log n, counting takes O(n))
Space Complexity: O(log n) (Recursive call stack)
6. Using Bit Manipulation
Approach:
Count how many times each bit (0-31) appears in all numbers.
Construct the majority element using the most frequent bits.
Code (C++):
cpp
Copy
Edit
#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) {
    int majority = 0, n = nums.size();

    for (int i = 0; i < 32; i++) {  // 32-bit integer
        int bitCount = 0;
        for (int num : nums) {
            if ((num >> i) & 1)
                bitCount++;
        }
        if (bitCount > n / 2)
            majority |= (1 << i);
    }

    return majority;
}

int main() {
    vector<int> nums = {3, 2, 3};
    cout << "Majority Element: " << majorityElement(nums) << endl;
    return 0;
}
Complexity Analysis:
Time Complexity: O(n)
Space Complexity: O(1)
Comparison of Approaches
Approach	Time Complexity	Space Complexity	Notes
Brute Force	O(n^2)	O(1)	Inefficient for large n
HashMap Counting	O(n)	O(n)	Extra space required
Sorting	O(n log n)	O(1)	Needs sorting
Boyer-Moore Voting (Best)	O(n)	O(1)	Best for single majority
Divide & Conquer	O(n log n)	O(log n)	Uses recursion
Bit Manipulation	O(n)	O(1)	Works with integer constraints
Best Approach?

Boyer-Moore Voting Algorithm is the most efficient (O(n) time, O(1) space).
If extra space is allowed, hash map (unordered_map) is an easy solution.
Sorting works but is slower (O(n log n)).
Brute force is the least efficient (O(n^2)).


LeetCode 167: Two Sum II - Input Array Is Sorted
Problem Statement
Given a 1-indexed sorted array of integers numbers (sorted in non-decreasing order) and a target number target, find two numbers such that they add up to target.
Return the indices of the two numbers as an array [index1, index2], where 1 <= index1 < index2 <= numbers.length.

📌 You must use an algorithm with O(n) runtime complexity.

1. Brute Force Approach (Nested Loop)
Approach
Use two loops to check every pair in the array.
If numbers[i] + numbers[j] == target, return {i + 1, j + 1}.
Since the array is sorted, we can break early when numbers[i] + numbers[j] > target.
Code (C++)
cpp
Copy
Edit
#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int n = numbers.size();
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (numbers[i] + numbers[j] == target) {
                return {i + 1, j + 1}; // 1-based index
            }
            if (numbers[i] + numbers[j] > target) break; // Optimization
        }
    }
    return {}; // Should never be reached
}

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(numbers, target);
    
    cout << "Indexes: " << result[0] << ", " << result[1] << endl;
    return 0;
}
Complexity Analysis
Time Complexity: O(n^2) (Two nested loops)
Space Complexity: O(1) (No extra space used)
2. Using HashMap (Unordered Map)
Approach
Traverse through the array and store each element's index in a unordered_map.
For each number numbers[i], check if (target - numbers[i]) exists in the map.
If found, return {previous_index + 1, i + 1}.
Code (C++)
cpp
Copy
Edit
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    unordered_map<int, int> num_map;
    
    for (int i = 0; i < numbers.size(); i++) {
        int complement = target - numbers[i];
        if (num_map.find(complement) != num_map.end()) {
            return {num_map[complement] + 1, i + 1}; // 1-based index
        }
        num_map[numbers[i]] = i;
    }
    
    return {};
}

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(numbers, target);
    
    cout << "Indexes: " << result[0] << ", " << result[1] << endl;
    return 0;
}
Complexity Analysis
Time Complexity: O(n)
Space Complexity: O(n) (Due to hash map storage)
3. Two-Pointer Approach (Best Approach)
Approach
Since the array is sorted, use two pointers:
left pointer at the beginning (0).
right pointer at the end (n-1).
Compute the sum numbers[left] + numbers[right].
If sum == target, return {left + 1, right + 1}.
If sum < target, move left pointer forward.
If sum > target, move right pointer backward.
Code (C++)
cpp
Copy
Edit
#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;

    while (left < right) {
        int sum = numbers[left] + numbers[right];

        if (sum == target) {
            return {left + 1, right + 1}; // 1-based index
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    
    return {};
}

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(numbers, target);
    
    cout << "Indexes: " << result[0] << ", " << result[1] << endl;
    return 0;
}
Complexity Analysis
Time Complexity: O(n) (Single pass)
Space Complexity: O(1) (No extra space)
4. Binary Search Approach
Approach
For each number numbers[i], use binary search to find target - numbers[i] in the remaining part of the array.
If found, return {i + 1, found_index + 1}.
Code (C++)
cpp
Copy
Edit
#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& numbers, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (numbers[mid] == target) return mid;
        else if (numbers[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

vector<int> twoSum(vector<int>& numbers, int target) {
    for (int i = 0; i < numbers.size(); i++) {
        int complement = target - numbers[i];
        int index = binarySearch(numbers, i + 1, numbers.size() - 1, complement);
        if (index != -1) {
            return {i + 1, index + 1};
        }
    }
    return {};
}

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(numbers, target);
    
    cout << "Indexes: " << result[0] << ", " << result[1] << endl;
    return 0;
}
Complexity Analysis
Time Complexity: O(n log n) (Each number performs a O(log n) binary search)
Space Complexity: O(1)
Comparison of All Approaches
Approach	Time Complexity	Space Complexity	Notes
Brute Force (Nested Loops)	O(n^2)	O(1)	Slow for large n
HashMap (Unordered Map)	O(n)	O(n)	Uses extra space
Two-Pointer (Best Approach)	O(n)	O(1)	Optimal for sorted arrays
Binary Search	O(n log n)	O(1)	Slightly slower than two-pointer
Best Approach?
✅ Two-Pointer method is the best (O(n) time, O(1) space) because the array is sorted.

🚀 Use HashMap if the array were unsorted.

💡 Binary Search is an alternative but slightly slower than two-pointer.


LeetCode 1: Two Sum
Problem Statement
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

1. Brute Force Approach (Nested Loops)
Approach
Use two nested loops to check all possible pairs.
If nums[i] + nums[j] == target, return {i, j}.
Since we are checking every pair, this approach is inefficient for large inputs.
Code (C++)
cpp
Copy
Edit
#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    
    return {}; // Should never be reached
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    
    cout << "Indexes: " << result[0] << ", " << result[1] << endl;
    return 0;
}
Complexity Analysis
Time Complexity: O(n^2) (Two nested loops)
Space Complexity: O(1) (No extra space used)
2. Using HashMap (Unordered Map)
Approach
Traverse through the array and store each element's index in a unordered_map.
For each number nums[i], check if (target - nums[i]) exists in the map.
If found, return {previous_index, i}.
Code (C++)
cpp
Copy
Edit
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> num_map;
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (num_map.find(complement) != num_map.end()) {
            return {num_map[complement], i};
        }
        num_map[nums[i]] = i;
    }
    
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    
    cout << "Indexes: " << result[0] << ", " << result[1] << endl;
    return 0;
}
Complexity Analysis
Time Complexity: O(n) (Single pass)
Space Complexity: O(n) (Due to hash map storage)
3. Two-Pointer Approach (Only if Sorted)
Approach
Sort the array first.
Use two pointers:
left pointer at the beginning (0).
right pointer at the end (n-1).
Compute the sum nums[left] + nums[right].
If sum == target, return {left, right}.
If sum < target, move left pointer forward.
If sum > target, move right pointer backward.
⚠ Problem: This approach only works if the array is sorted, but sorting changes original indices, making it invalid unless you store the original indices.

Code (C++)
cpp
Copy
Edit
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<pair<int, int>> indexedNums;
    for (int i = 0; i < nums.size(); i++) {
        indexedNums.push_back({nums[i], i});
    }

    sort(indexedNums.begin(), indexedNums.end());

    int left = 0, right = nums.size() - 1;
    
    while (left < right) {
        int sum = indexedNums[left].first + indexedNums[right].first;
        
        if (sum == target) {
            return {indexedNums[left].second, indexedNums[right].second}; // Return original indices
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    
    cout << "Indexes: " << result[0] << ", " << result[1] << endl;
    return 0;
}
Complexity Analysis
Sorting Complexity: O(n log n)
Two-pointer Complexity: O(n)
Overall Time Complexity: O(n log n)
Space Complexity: O(n)
⚠ Not Recommended for this problem since it modifies the array.

4. Binary Search Approach (Only if Sorted)
Approach
For each number nums[i], use binary search to find target - nums[i] in the remaining part of the array.
If found, return {i, found_index}.
⚠ This approach requires sorting, which changes indices, making it problematic.

Code (C++)
cpp
Copy
Edit
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<pair<int, int>>& nums, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid].first == target) return nums[mid].second;
        else if (nums[mid].first < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

vector<int> twoSum(vector<int>& nums, int target) {
    vector<pair<int, int>> indexedNums;
    for (int i = 0; i < nums.size(); i++) {
        indexedNums.push_back({nums[i], i});
    }
    
    sort(indexedNums.begin(), indexedNums.end());

    for (int i = 0; i < indexedNums.size(); i++) {
        int complement = target - indexedNums[i].first;
        int index = binarySearch(indexedNums, i + 1, indexedNums.size() - 1, complement);
        if (index != -1) {
            return {indexedNums[i].second, index};
        }
    }
    
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    
    cout << "Indexes: " << result[0] << ", " << result[1] << endl;
    return 0;
}
Complexity Analysis
Sorting Complexity: O(n log n)
Binary Search Complexity: O(log n) for each element (O(n log n) total)
Overall Time Complexity: O(n log n)
Space Complexity: O(n)
⚠ Not recommended since the hash map approach is faster.

Comparison of All Approaches
Approach	Time Complexity	Space Complexity	Notes
Brute Force (Nested Loops)	O(n^2)	O(1)	Slow for large n
HashMap (Best Approach)	O(n)	O(n)	Fastest for unsorted arrays
Two-Pointer (If Sorted)	O(n log n)	O(n)	Sorting changes indices
Binary Search (If Sorted)	O(n log n)	O(n)	Sorting issue, slower than hash map
Best Approach?
✅ Use HashMap (Unordered Map) as it runs in O(n) and works without sorting.
🚀 Use Two-Pointer only if sorting is allowed and indices don't matter.

LeetCode 26: Remove Duplicates from Sorted Array
Problem Statement
Given a sorted array nums, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be preserved.

Since the array is modified in-place, return the new length of the modified array.
⚠ Do not use extra space for another array; modify nums in-place.

Example
Input:
cpp
Copy
Edit
nums = [1, 1, 2]
Output:
cpp
Copy
Edit
2, nums = [1, 2, _]
(Where _ represents unused elements)

1. Brute Force Approach (Shifting Elements)
Approach
Start from index 0 and compare each element with the next element.
If nums[i] == nums[i+1], shift all elements to the left to remove the duplicate.
Continue until all duplicates are removed.
Code (C++)
cpp
Copy
Edit
#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    int i = 0;  // Pointer for unique elements

    for (int j = 1; j < n; j++) {
        if (nums[j] != nums[i]) {
            i++;  
            nums[i] = nums[j];  // Move the unique element forward
        }
    }

    return i + 1;  // Length of unique elements
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3};
    int newLength = removeDuplicates(nums);

    cout << "New length: " << newLength << endl;
    cout << "Modified array: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
Complexity Analysis
Time Complexity: O(n^2) (Shifting elements takes extra time)
Space Complexity: O(1) (No extra space used)
⚠ Inefficient for large inputs due to shifting elements.
2. Two-Pointer Approach (Optimal)
Approach
Use two pointers:
i (slow pointer) → Position for unique elements.
j (fast pointer) → Scans the array.
If nums[j] is different from nums[i], move i forward and store nums[j].
The first i+1 elements will contain unique values.
Code (C++)
cpp
Copy
Edit
#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) return 0;

    int i = 0; // Slow pointer for unique elements

    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;  
            nums[i] = nums[j]; // Place the unique element
        }
    }

    return i + 1;  // New length of unique elements
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3};
    int newLength = removeDuplicates(nums);

    cout << "New length: " << newLength << endl;
    cout << "Modified array: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
Complexity Analysis
Time Complexity: O(n) (Each element is processed once)
Space Complexity: O(1) (No extra space used)
✅ Best solution: Efficient and modifies the array in place.
3. Using set (Extra Space, Not In-Place)
Approach
Use a set to store unique elements.
Copy unique elements back to nums[].
⚠ Not in-place, since we use extra space.
Code (C++)
cpp
Copy
Edit
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    set<int> uniqueSet(nums.begin(), nums.end()); // Store unique elements

    int i = 0;
    for (int num : uniqueSet) {
        nums[i++] = num;  // Copy back unique elements
    }

    return i;  // New length
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3};
    int newLength = removeDuplicates(nums);

    cout << "New length: " << newLength << endl;
    cout << "Modified array: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
Complexity Analysis
Time Complexity: O(n log n) (Due to set insertion)
Space Complexity: O(n) (Extra space used for set)
🚫 Not an in-place solution.
4. Counting Unique Elements (Alternative)
Approach
Count unique elements and place them in the first part of nums[].
Code (C++)
cpp
Copy
Edit
#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) return 0;

    int count = 1;  // At least one unique element

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) {
            nums[count] = nums[i]; // Store unique value
            count++;
        }
    }

    return count;  // New length
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3};
    int newLength = removeDuplicates(nums);

    cout << "New length: " << newLength << endl;
    cout << "Modified array: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
Complexity Analysis
Time Complexity: O(n)
Space Complexity: O(1)
Comparison of All Approaches
Approach	Time Complexity	Space Complexity	In-Place?	Notes
Brute Force (Shifting)	O(n^2)	O(1)	✅	Shifting elements is slow
Two Pointers (Optimal)	O(n)	O(1)	✅	Best approach
Using set (Extra Space)	O(n log n)	O(n)	❌	Not in-place, extra memory used
Counting Unique Elements	O(n)	O(1)	✅	Alternative optimal approach
✅ Best Approach: Two Pointers (O(n)) since it efficiently modifies nums in-place.
🚀 Avoid brute force and set methods due to inefficiency.