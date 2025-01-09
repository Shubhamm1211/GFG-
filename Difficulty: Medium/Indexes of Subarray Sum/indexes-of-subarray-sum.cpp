//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        map <int,int> mp;
        int n = arr.size();
        int sum = 0;
        vector <int> ans;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if (sum == target) {
            ans.push_back(1); 
            ans.push_back(i + 1);
            return ans;
        }
            int rem = sum - target;
            if(mp.find(rem) != mp.end()){
                ans.push_back(mp[rem] + 1);
                ans.push_back(i);
                
                break;
            }
            if(mp.find(sum) == mp.end()) mp[sum] = i;
        }
        if(ans.size() > 0){
            ans[0]++;
            ans[1]++;
            return ans;
        }
        return {-1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends