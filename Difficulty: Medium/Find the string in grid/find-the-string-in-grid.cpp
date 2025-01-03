//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool check(int row, int col, vector<vector<char>>grid, string word,int ind,int dir){
        int n = grid.size();
	    int m = grid[0].size();
	    int dr[8] = {0,1,1,1,0,-1,-1,-1};
	    int dc[8] = {1,1,0,-1,-1,-1,0,1};
	    if(ind == word.size() - 1) return true;
        int nr = row + dr[dir];
        int nc = col + dc[dir];
        if(nr >= 0 and nr < n and nc >= 0 and nc < m and grid[nr][nc] == word[ind + 1]){
            return check(nr,nc,grid,word, ind + 1,dir);
        }
	    
	    return false;
	    
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int n = grid.size();
	    int m = grid[0].size();
	    vector <vector<int>> ans;
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < m; j++){
	            for(int dir = 0; dir < 8; dir++){
    	            if(grid[i][j] == word[0] and check(i,j,grid,word,0,dir)){
    	                ans.push_back({i,j});
    	                break;
    	            }
	            }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends