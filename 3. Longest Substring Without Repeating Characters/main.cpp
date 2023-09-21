#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;
  int start = 0;
  int max_len = 0;

  for (int i = 0; i < s.length(); i++) {
    if (seen.count(s[i])) {
      start = max(start, seen[s[i]] + 1);
    }

    max_len = max(max_len, i - start + 1);
    seen[s[i]] = i;
  }

  return max_len;
    }
};

int main()
{
    return 0;
}