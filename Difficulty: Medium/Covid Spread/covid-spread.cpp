//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> h)
    {
        //code here
        int n=h.size();
        int m=h[0].size();
        int maxi=0;
        int dr[4]={0,0,-1,1};
        int dc[4]={1,-1,0,0};
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue< pair<int, pair<int,int>> >q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(h[i][j]==2)q.push({0,{i,j}});
            }
        }
        
        while(!q.empty()){
            int t=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            maxi=max(maxi,t);
            for(int i=0;i<4;i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr>=0 and nr<n and nc>=0 and nc<m and h[nr][nc]==1){
                        h[nr][nc]=2;
                        q.push({t+1,{nr,nc}});
                    }
                
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(h[i][j]==1)return -1;
            }
        }
        return maxi;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends