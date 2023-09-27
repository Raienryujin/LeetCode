#include <string>

using namespace std;

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long decodedLength = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                decodedLength *= (c - '0');
            } else {
                decodedLength++;
            }
        }
        
        for (int i = s.size() - 1; i >= 0; i--) {
            k %= decodedLength;
            
            if (k == 0 && isalpha(s[i])) {
                return string(1, s[i]);
            }
            
            if (isdigit(s[i])) {
                int digit = s[i] - '0';
                decodedLength /= digit;
            } else {
                decodedLength--;
            }
        }
        
        return "";
    }
};

int main()
{
    return 0;
}