#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  unordered_map<int, int> hash_table;
  for (int i = 0; i < nums.size(); i++) {
    hash_table[nums[i]] = i;
  }

  for (int i = 0; i < nums.size(); i++) {
    int complement = target - nums[i];
    if (hash_table.find(complement) != hash_table.end() && hash_table[complement] != i) {
      return vector<int>{i, hash_table[complement]};
    }
  }

  return vector<int>();
}
