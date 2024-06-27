//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool solve(vector<int>&s,int k,int d){
        int cnt=1;
        int last=s[0];
        for(int i=1;i<s.size();i++){
            if(s[i]-last>=d){
                cnt++;
                last=s[i];
            }
        }
        if(cnt>=k)return true;
        else return false;
    }
    int solve(int n, int k, vector<int>&s) {
        sort(s.begin(),s.end());
        int mini=*min_element(s.begin(),s.end());
        int maxi=*max_element(s.begin(),s.end());
        int low=1,high=maxi-mini;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(s,k,mid)){
                low=mid+1;
            }
            else high=mid-1;
        }
        return high;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends