//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

bool cmp(pair<int,int>&a,pair<int,int>&b){
    if(a.second==b.second)return a.first<b.first;
    return a.second>b.second;
}
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        vector<pair<int,int>>v;
        for(auto x:mp){
            v.push_back({x.first,x.second});
        }
        sort(v.begin(),v.end(),cmp);
        vector<int>ans;
          for(pair<int,int> &p: v){
            
            while(p.second--) ans.push_back(p.first);
        }
        return ans;
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
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends