//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    unordered_map<Node*,Node*>mp;
    void find_parent(Node* root,Node* parent){
        if(!root) return;
        if(!parent)parent=root;
        else mp[root]=parent;
        find_parent(root->left,root);
        find_parent(root->right,root);
    }
    
    Node* find_target(Node* root,int target){
        if(!root) return NULL;
        if(root->data == target){
            return root;
        }
        Node* lft = find_target(root->left,target);
        Node* rht = find_target(root->right,target);
        if(lft){
            return lft;
        }else if(rht){
            return rht;
        }
        return NULL;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        Node* t = find_target(root,target);
        if(t==NULL)return 0;
        find_parent(root,NULL);
        set<Node*>st;
        int ans=0;
        
        queue<Node*>q;
        q.push(t);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                Node* temp = q.front();
                q.pop();
                
                st.insert(temp);
                if(temp->left && !st.count(temp->left)){
                    q.push(temp->left);
                }
                if(temp->right && !st.count(temp->right)){
                    q.push(temp->right);
                }
                if(mp.find(temp)!=mp.end() && !st.count(mp[temp])){
                    q.push(mp[temp]);
                }
            }
            ans++;
        }
        return ans-1;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends