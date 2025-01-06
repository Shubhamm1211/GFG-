//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        sort(begin(arr), end(arr));
        int n = arr.size();
        int i = 0, j = n - 1;
        int diff = INT_MAX;
        vector <pair<int,int>> ans;
        while(i < j){
            if(abs(target - (arr[i] + arr[j])) < diff){
                diff = abs(target - (arr[i] + arr[j]));
                ans.push_back({arr[i],arr[j]});
            }
            if(arr[i] + arr[j] == target){
                return {arr[i],arr[j]};
            }
            else if(arr[i] + arr[j] < target){
                i++;
            }
            else{
                j--;
            }
        }
        if(ans.size() == 0) return {};
        return {ans.back().first,ans.back().second};
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
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends