//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string& s) {
    stack<int> st;
    int max_len = 0;
    int last_invalid = -1; // Position before the start of the string

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } 
        else if (s[i] == ')') {
            if (!st.empty()) {
                st.pop();
                int len;
                if (st.empty()) {
                    len = i - last_invalid;
                } else {
                    len = i - st.top();
                }
                max_len = max(max_len, len);
            } 
            else {
                last_invalid = i;
            }
        }
    }
    return max_len;
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends