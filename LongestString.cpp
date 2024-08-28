// write a code in cpp to find the longest common sub string 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonSubstring(const string& str1, const string& str2) {
    int len1 = str1.length();
    int len2 = str2.length();

    if (len1 == 0 || len2 == 0) return ""; // If any of the strings is empty, return empty string

    // Initialize a 2D vector to store the lengths of common substrings
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    int maxLength = 0; // Length of longest common substring
    int endIndex = 0;  // Ending index of longest common substring

    // Fill up the dp matrix
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; // If characters match, increment the length
                if (dp[i][j] > maxLength) { // If new longest common substring found
                    maxLength = dp[i][j];
                    endIndex = i - 1; // Update the ending index
                }
            } else {
                dp[i][j] = 0; // Reset the length if characters don't match
            }
        }
    }

    // Extract the longest common substring
    string longestCommonSubstr = str1.substr(endIndex - maxLength + 1, maxLength);
    return longestCommonSubstr;
}

int main() {
    string str1 = "abcdef";
    string str2 = "xbcdyz";

    cout << "Longest Common Substring: " << longestCommonSubstring(str1, str2) << endl;

    return 0;
}
