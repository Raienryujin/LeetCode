#include <iostream>
#include <vector> 

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0;
    int j = nums.size() - 1;

    while (i < j) {
      if (nums[i] % 2 != 0 && nums[j] % 2 == 0) {
        swap(nums[i], nums[j]);
      } else if (nums[i] % 2 == 0) {
        i++;
      } else if (nums[j] % 2 != 0) {
        j--;
      }
    }

    return nums;
    }
};

int main()
{
    return 0;
}
//test for merge