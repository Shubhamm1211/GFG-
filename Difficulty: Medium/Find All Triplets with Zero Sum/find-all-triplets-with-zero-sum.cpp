//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        // int n = arr.size();
        // vector <vector <int>> ans;
        // map <int,int> mp;
        // for(int i = 0; i < n; i++){
        //     for(int j = i + 1; j < n; j++){
        //         int tar = -1 *(arr[i] + arr[j]);
        //         if(mp.find(tar) != mp.end() and mp[tar] < i){
        //             ans.push_back({mp[tar],i,j});
        //         }
        //     }
        //     mp[arr[i]] = i;
        // }

        // set < vector <int> > st(begin(ans), end(ans));
        // vector <vector <int>> res (begin(st), end(st));
        // return res;
        // map<int,int> mp;
        // for(int i = 0; i < n; i++) mp[arr[i]] = i
        // sort(begin(arr), end(arr));
        // for(int i = 0; i < n; i++){
        //     if(i > 0 and arr[i - 1] == arr[i]) continue;
        //     int j = i + 1; 
        //     int k = n - 1;
        //     while(j < k){
        //         int sum = arr[i] + arr[j] + arr[k];
        //         if(sum > 0){
        //             k--;
        //         }
        //         else if(sum < 0){
        //             j++;
        //         }
        //         else{
        //             vector <int> temp = {i,j,k};
        //             ans.push_back(temp);
        //             j++;
        //             k--;
        //             while(j < k and arr[j] == arr[j - 1])j++;
        //             while(j < k and arr[k] == arr[k + 1])k--;
        //         }
        //     }
        // }
        // return ans;
        int n=arr.size();
        unordered_map<int,int>mapp;
        set<vector<int>>st;
        
        for(int i=0;i<n;i++){
            mapp[arr[i]]=i;
        }
        
        for(int j=0;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                int sum=arr[j]+arr[k];
                int rem=0-sum;
                
                if(mapp.find(rem)!=mapp.end()){
                    int i=mapp[rem];
                    if(i!=j && i!=k){
                        vector<int>temp{i,j,k}; 
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>>res(st.begin(),st.end());
        return res;
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends