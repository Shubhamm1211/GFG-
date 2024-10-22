//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
    // Initialize the difference between counts of x and y
    int diff = 0;
    // Initialize the map to store frequency of diff values
    unordered_map<int, int> freq;
    // Initially, diff is 0, and it has occurred once
    freq[0] = 1;
    int ans = 0;

    // Iterate through the array and compute the difference
    for(auto &num : arr){
        if(num == x){
            diff +=1;
        }
        else if(num == y){
            diff -=1;
        }
        // If this diff has been seen before, it means there is a subarray
        // ending here with equal number of x and y
        if(freq.find(diff) != freq.end()){
            ans += freq[diff];
        }
       
        freq[diff]++;
    }

    return ans;
}
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int x = stoi(ks);
        string ks1;
        getline(cin, ks1);
        int y = stoi(ks1);
        Solution ob;
        int ans = ob.sameOccurrence(arr, x, y);
        cout << ans << "\n";
        // cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends