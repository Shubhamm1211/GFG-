//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long 
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        ll n = arr.size();
        map <ll,ll> mp;
        int ans = 0;
        mp[0] = 1;
        ll xorr = 0;
        for(ll i = 0; i < n; i++){
            xorr ^= arr[i];
            ll temp = k ^ xorr;
            if(mp.find(temp) != mp.end()){
                ans += mp[temp];
            }
            mp[xorr]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (tc-- > 0) {
        string input;
        getline(cin, input); // Read the whole line for the array

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num); // Push numbers into the vector
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after k

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends