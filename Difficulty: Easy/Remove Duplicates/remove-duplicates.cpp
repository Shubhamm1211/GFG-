//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string removeDups(string str) {
        // Your code goes here
        // for(int i=0;i<str.size();i++){
        //     for(int j=i+1;j<str.size();j++){
        //         if(str[i]==str[j]){
        //             str[j]='#';
        //         }
        //     }
        // }
        // string ans="";
        // for(int i=0;i<str.size();i++){
        //     if(str[i]!='#'){
        //         ans=ans+str[i];
        //     }
        // }
        // return ans;
        vector<int>seen(26,0);
        int n=str.size();
        string ans="";
        for(int i=0;i<n;i++){
            if(seen[str[i]-'a']!=0)continue;
            else if (seen[str[i]-'a']==0){
                seen[str[i]-'a']=1;
                ans.push_back(str[i]);
            }
            
        }
        return ans;
        
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
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends