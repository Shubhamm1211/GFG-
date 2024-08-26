//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findMaxDiff(vector<int> &arr) {
        int n=arr.size();
        vector<int>ls(n,0);
        vector<int>rs(n,0);
        stack<int>st;
        
        
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty())ls[i]=0;
            else ls[i]=arr[st.top()];
            st.push(i);
        }
        while(!st.empty())st.pop();
        
 
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty())rs[i]=0;
            else rs[i]=arr[st.top()];
            st.push(i);
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,abs(rs[i]-ls[i]));
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends