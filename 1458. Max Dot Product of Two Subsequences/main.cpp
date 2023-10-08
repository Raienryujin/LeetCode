#include <iostream>
#include <vector>
#include <algorithm>

int maxDotProduct(std::vector<int>& nums1, std::vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();

    std::vector<std::vector<int>> dp(m, std::vector<int>(n, INT_MIN));

    dp[0][0] = nums1[0] * nums2[0];

    for (int j = 1; j < n; ++j) {
        dp[0][j] = std::max(dp[0][j - 1], nums1[0] * nums2[j]);
    }
    
    for (int i = 1; i < m; ++i) {
        dp[i][0] = std::max(dp[i - 1][0], nums1[i] * nums2[0]);
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            int withoutCurrent = dp[i - 1][j - 1];
            int withCurrent = std::max(nums1[i] * nums2[j], nums1[i] * nums2[j] + withoutCurrent);
            dp[i][j] = std::max({dp[i - 1][j], dp[i][j - 1], withCurrent});
        }
    }

    return dp[m - 1][n - 1];
}

int main() {
    std::vector<int> nums1 = {2, 1, -2, 5};
    std::vector<int> nums2 = {3, 0, -6};
    int result = maxDotProduct(nums1, nums2);
    std::cout << "Output: " << result << std::endl;

    return 0;
}
