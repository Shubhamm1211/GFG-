//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int calc(int n, int k){
        int pf = n - n % k ;
        int ans = pf / k ;
        if(n%k!=0)ans++;
        return ans;
    }
    int totalCount(int k, vector<int>& arr) {
        // code here
        int ans = 0; 
        for(int i = 0; i < arr.size(); i++){
            ans += calc(arr[i],k) ; 
        }
        return ans ; 
        
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.totalCount(k, arr);
        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends