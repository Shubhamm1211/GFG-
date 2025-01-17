//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    vector <string> ans;
    void solve(int n, string s, int cnt1, int cnt0){
        if(n == 0){
            ans.push_back(s);
            return;
        }
        if(cnt1 >= cnt0){
            solve(n - 1, s + '1', cnt1 + 1, cnt0);
        }
        if(cnt1 > cnt0){
            solve(n - 1,s + '0' ,cnt1, cnt0 + 1);
        }
    }
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    int cnt1 = 0, cnt0 = 0;
	    string s = "";
	    solve(n,"",cnt1,cnt0);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends