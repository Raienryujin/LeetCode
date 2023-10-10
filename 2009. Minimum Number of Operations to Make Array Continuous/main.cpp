#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> uniqueNums = nums;
        sort(uniqueNums.begin(), uniqueNums.end());
        uniqueNums.erase(unique(uniqueNums.begin(), uniqueNums.end()), uniqueNums.end());

        int left = 0;
        int minOperations = n;
        
        for (int right = 0; right < uniqueNums.size(); ++right) {
            while (uniqueNums[right] - uniqueNums[left] > n - 1) {
                left++;
            }
            minOperations = min(minOperations, n - (right - left + 1));
        }
        
        return minOperations;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {4, 2, 2, 2, 4, 4, 2, 4};
    int result = solution.minOperations(nums);
    
    cout << "Minimum operations: " << result << endl; // Output: 3
    
    return 0;
}
