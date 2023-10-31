//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      unordered_set<int>s;
      int maxi=1;
      for(int i=0;i<N;i++){
          s.insert(arr[i]);
      }
      for(auto it:s){
          if(s.find(it-1)==s.end()){
              int cnt=1;
              int x=it;
              while(s.find(x+1)!=s.end()){
                  x++;
                  cnt++;
              }
              maxi=max(cnt,maxi);
          }
      }
      return maxi;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends