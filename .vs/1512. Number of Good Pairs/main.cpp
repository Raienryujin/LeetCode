#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        std::unordered_map<int, int> count;
        int goodPairs = 0;

        for (int num : nums) {
            count[num]++;
        }

        for (auto& pair : count) {
            int n = pair.second;
            
            goodPairs += (n * (n - 1)) / 2;
        }

        return goodPairs;
    }
};

int main()
{

    return 0;
}