//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        vector<string>v;
        int j=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='.'){
                v.push_back(str.substr(j,i-j));
                j=i+1;
            }
        }
        v.push_back(str.substr(j,str.size()-j));
        string ans="";
        for(auto x:v){
            ans=x+"."+ans;
        }
        ans.back()=' ';
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends