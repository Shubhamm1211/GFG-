//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

bool cmp(pair<int,int> &a, pair<int,int> &b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second < b.second;
    }
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
       vector<pair<int,int>> v;
       int n = start.size();
        for(int i = 0; i < n; i++){
            v.push_back({start[i],end[i]});
        }
        sort(v.begin(),v.end(),cmp);
        int ans = 1;
        int ends = v[0].second;
        for(int i = 1; i < n; i++){
            if(v[i].first > ends){
                ans++;
                ends = v[i].second;
            }
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
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends