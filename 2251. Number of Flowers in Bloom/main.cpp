#include <iostream>
#include <vector>

class Solution {
public:
    int minDays(std::vector<int>& bloomDay, int k) {
        int n = bloomDay.size();
        if (n < k)
            return -1;

        int left = 1, right = 1e9; 
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (countBouquets(bloomDay, mid) < k) 
            {
                left = mid + 1;
            } else 
            {
                right = mid;
            }
        }
        return left;
    }

private:
    int countBouquets(const std::vector<int>& bloomDay, int day) {
        int bouquets = 0;
        int flowers = 0;

        for (int i = 0; i < bloomDay.size(); ++i) {
            if (bloomDay[i] <= day) 
            {
                flowers++;
                if (flowers == 3) 
                { 
                    bouquets++;
                    flowers = 0;
                }
            } else 
            {
                flowers = 0; 
            }
        }

        return bouquets;
    }
};


int main()
{

    return 0;
}