//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int n = s.size();
        map <char,int> mp;
        int i = 0, j = 0;
        int maxi = 0;
        while(i <= j and j < n){
            mp[s[j]]++;
            while(mp.size() < j - i + 1){
                mp[s[i]]--;
                if(mp[s[i]] == 0)mp.erase(s[i]);
                i++;
            }
            if(mp.size() == j - i + 1){
                maxi = max(maxi,j - i + 1);
            }
            j++;
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends