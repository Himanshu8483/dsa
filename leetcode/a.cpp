// #include<iostream>
// using namespace std;
// #include<vector>
// #include<algorithm>
// class Solution{
//     public:
//     int majorityElement(vector<int>& nums){
//         int n=nums.size();
//         for(int i=0; i<n; i++){
//             int count = 0;
//             for(int j=0; j<n; j++){
//                 if(nums[i]==nums[j]){
//                     count++;
//                 }
//             }
//             if(count>n/2){
//                 return nums[i];
//                 break;
//             }
//             return 0;
//         }
//     }
// };
// int main(){
//     vector<int>& nums{1,2,2,1,4,2,2};
//    majorityElement(nums);
// }

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }
            if (count > n / 2) {
                return nums[i]; // Correct return when majority element is found
            }
        }
        return -1; // If no majority element is found
    }
};

int main() {
    vector<int> nums = {1, 2, 2, 1, 4, 2, 2}; // Correct vector initialization
    Solution sol;
    cout << "Majority Element: " << sol.majorityElement(nums) << endl; // Call through an instance
    return 0;
}

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int candidate = nums[0], count = 0;
            for (int num : nums) {
                if (count == 0) {
                    candidate = num;
                }
                count += (num == candidate) ? 1 : -1;
            }
            return candidate;
        }
    };
    

167 : binary search : o(n square)
    class Solution {
        public:
            vector<int> twoSum(vector<int>& numbers, int target) {
                for(int i=0; i<numbers.size(); i++{
                    for(int j=0; j<numbers.size();j++){
                        if(i!j){
                            if(num[i]+num[i]==target){
                                return {i+1, j+1}
                            }
                        }
                    }
                })
            }
        };

public:
vector<int> twoSum(vector<int> & nums , int target){
for(int i=0; i<nums.size();i++){
    int low=i+1, high=nums.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[i]+nums[mid]==target){
            return {i+1;mid+1};
        }
        else if(nums[i]+nums[mid]>target){
            hgh=mid-1;
        }
        else{
            low=mid+1;
        }
    }
}
}       // order of nlogn
// by map order of n 

