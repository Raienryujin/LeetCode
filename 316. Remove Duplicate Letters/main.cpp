#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string removeDuplicateLetters(string s) {
    vector<int> lastOccurrence(26, -1);
    vector<bool> visited(26, false);
    stack<char> charStack;

    for (int i = 0; i < s.length(); i++) {
        lastOccurrence[s[i] - 'a'] = i;
    }

    for (int i = 0; i < s.length(); i++) {
        char currentChar = s[i];

        if (visited[currentChar - 'a']) {
            continue;
        }

        while (!charStack.empty() && currentChar < charStack.top() && lastOccurrence[charStack.top() - 'a'] > i) {
            visited[charStack.top() - 'a'] = false;
            charStack.pop();
        }

        charStack.push(currentChar);
        visited[currentChar - 'a'] = true;
    }

    string result = "";
    while (!charStack.empty()) {
        result = charStack.top() + result;
        charStack.pop();
    }

    return result;
}

int main() {
    string s = "cbacdcbc";
    string result = removeDuplicateLetters(s);
    cout << "Result: " << result << endl;
    return 0;
}
