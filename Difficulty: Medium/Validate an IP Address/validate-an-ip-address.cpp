//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     int isValid(string s) {
    // code here
    int n=s.size();
    if(n<7) return 0; 
    int cnt=0;
    for(int i=0;i<n;i++){
        if(i>0 && s[i]==s[i-1] && s[i]=='.') return 0; 
        if(s[i]=='.') cnt++;
    }
    if(cnt!=3) return 0; 
    

    
    string temp=""; 
    for(int i=0;i<=n;i++){ 
        if(s[i]=='.'||i==n){
            if(temp.size()==0 || (temp[0]=='0' && temp.size()>1) || temp.size()>3) return 0;
            int val=stoi(temp);
            if(val>255) return 0;
            temp="";
        }
        else temp+=s[i];
    }
    return 1;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends