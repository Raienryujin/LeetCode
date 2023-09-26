#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.length();
    int maxLength = 0;
    int start = 0;
    int end = 0;

    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // Initialize the base cases.
    for (int i = 0; i < n; i++) {
      dp[i][i] = true;
    }

    // Iterate over the string, starting from the smallest substrings.
    for (int l = 2; l <= n; l++) {
      for (int i = 0; i <= n - l; i++) {
        int j = i + l - 1;
        if (s[i] == s[j] && (l == 2 || dp[i + 1][j - 1])) {
          dp[i][j] = true;
          if (l > maxLength) {
            maxLength = l;
            start = i;
            end = j;
          }
        }
      }
    }

    return s.substr(start, maxLength);
  }
};


int main()
{
    return 0;
}