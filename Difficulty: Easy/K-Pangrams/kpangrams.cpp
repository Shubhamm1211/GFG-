//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        vector<int>check(26,0);
        int len=0;
        for(int i=0;i<str.size();i++){
            if(str[i]==' ')continue;
            check[str[i]-'a']=1;
            len++;
        }
        if(len<26)return false;
        for(int i=0;i<26;i++){
            if(check[i]==0)k--;
        }
        if(k>=0)return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends