//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    return new Node(val);
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after splitting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

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

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void inorder(Node *root, vector <int> &ans){
        if(!root) return;
        
        if(root -> left){
            inorder(root -> left, ans);
        }
        if(!(root -> left) and !(root -> right)){
            ans.push_back(root -> data);
            return;
        }
        if(root -> right){
            inorder(root -> right, ans);
        }
    }
    void solveright(Node *root, vector <int> &ans){
    if(!root) return;
    
    // If there is a right child, process that;
    // otherwise, if there is a left child, process that.
    if(root->right)
        solveright(root->right, ans);
    else if(root->left)
        solveright(root->left, ans);
        
    // To avoid duplicates, add the node after recursive calls (bottom-up)
    if(root->left || root->right)
        ans.push_back(root->data);
}

    void solveleaf(Node *root, vector <int> &ans){
        inorder(root,ans);
    }
    void solveleft(Node *root, vector<int> &ans) {
    if (!root) return;
    // Do not add leaf nodes in the left boundary to avoid duplicates later.
    if (root->left == NULL && root->right == NULL)
        return;
    
    ans.push_back(root->data);
    
    // Prefer left child; if not available, use right child.
    if (root->left)
        solveleft(root->left, ans);
    else if (root->right)
        solveleft(root->right, ans);
}

    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector <int> ans;
        if(!root) return ans;
        if(root -> left == NULL and root -> right == NULL) return {root -> data};
        ans.push_back(root -> data);
        if(root -> left) solveleft(root -> left,ans);
        solveleaf(root,ans);
        if(root -> right) solveright(root -> right,ans);
        return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function */
int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s, ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int> res = ob.boundaryTraversal(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends