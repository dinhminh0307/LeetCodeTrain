#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        int total_count = 0;

        // Iterate through all possible starting points
        for (int i = 0; i < n; ++i) {
            unordered_map<char, int> freq_map;
            
            // Expand the window by moving 'j' (right pointer)
            for (int j = i; j < n; ++j) {
                freq_map[s[j]]++;  // Add character to frequency map
                
                // Check if any character has at least 'k' occurrences
                bool has_k_char = false;
                for (const auto& pair : freq_map) {
                    if (pair.second >= k) {
                        has_k_char = true;
                        break;
                    }
                }
                
                // If the substring is valid, increment the count
                if (has_k_char) {
                    total_count++;
                }
            }
        }

        return total_count;
    }
};

int main() {
    Solution solution;
    string s = "abacb";
    int k = 2;
    
    int result = solution.numberOfSubstrings(s, k);
    
    cout << "Number of substrings with at least one character appearing " << k << " times: " << result << endl;
    
    return 0;
}
