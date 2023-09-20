#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int i = 0;
    int j = 0;

    vector<int> mergedArray;

    while (i < nums1.size() && j < nums2.size()) 
    {
      if (nums1[i] <= nums2[j]) 
      {
        mergedArray.push_back(nums1[i]);
        i++;
      } else 
      {
        mergedArray.push_back(nums2[j]);
        j++;
      }
    }

    if (i < nums1.size()) 
    {
      copy(nums1.begin() + i, nums1.end(), back_inserter(mergedArray));
    } else 
    {
      copy(nums2.begin() + j, nums2.end(), back_inserter(mergedArray));
    }

    if (mergedArray.size() % 2 == 1) 
    {
      return mergedArray[mergedArray.size() / 2];
    } else 
    {
      return (mergedArray[mergedArray.size() / 2 - 1] + mergedArray[mergedArray.size() / 2]) / 2.0;
    }
  }
};

int main()
{
    return 0;
}
