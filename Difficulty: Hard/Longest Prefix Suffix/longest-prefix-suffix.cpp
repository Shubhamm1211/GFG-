//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
     int lps(string str) {
        // Your code goes here
        vector<int>lps(str.size(),0);
        int pref =0;
        int suff = 1;
        while(suff < str.size()){
            if(str[pref] == str[suff]){
                lps[suff] = pref+1;
                pref++;
                suff++;
            }else{
                 if(pref == 0){
                     lps[suff] =0;
                     suff++;
                 }else{
                     pref = lps[pref-1];
                 }
            }
        }
        return lps[str.size()-1];
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends