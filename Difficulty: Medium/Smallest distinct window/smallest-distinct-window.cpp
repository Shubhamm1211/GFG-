//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here  
        unordered_map<char,int>mp;
        unordered_set<char>st(str.begin(),str.end());
        int l=0,r=0,mini=INT_MAX,cnt=0,n=str.size();
        while(r<n){
            mp[str[r]]++;
            if(mp[str[r]]==1)cnt++;
            while(cnt==st.size()){
                mini=min(mini,r-l+1);
                mp[str[l]]--;
                if(mp[str[l]]==0){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        return mini;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends