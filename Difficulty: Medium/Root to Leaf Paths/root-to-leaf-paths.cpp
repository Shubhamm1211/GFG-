//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

Node* inputTree(){
    string treeString;
    getline(cin,treeString);
    Node* root = buildTree(treeString);
    return root;
}
void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void inorder(Node* root, vector<Node*>& leaf) {
    if (!root) return;  // Correct: Base case to handle null node
    if (root->left) {
        inorder(root->left, leaf);  // Correct: Traverse left subtree
    }
    if (root->left == nullptr && root->right == nullptr) {
        leaf.push_back(root);  // Correct: Collecting leaf nodes
    }
    if (root->right) {
        inorder(root->right, leaf);  // Correct: Traverse right subtree
    }
}

bool getpath(Node* root, int x, vector<int>& temp) {
    if (!root) return false;  // Correct: Base case to handle null node

    temp.push_back(root->data);  // Correct: Push the current node's data into path

    if (root->data == x) {
        return true;  // Correct: Return true when target node `x` is found
    }

    // Mistake:
    // You're calling getpath recursively here, but missing the `temp.push_back()` 
    // for each node visited. This is correct now because you added `temp.push_back()`
    // at the start of the function.

    if (getpath(root->left, x, temp) || getpath(root->right, x, temp)) {
        return true;  // Correct: Continue recursion if the path is found
    }

    // Correct: If the path isn't found, we remove the current node's value from `temp`
    temp.pop_back();  // Backtrack

    return false;  // Correct: Return false if no path is found
}

vector<vector<int>> Paths(Node* root) {
    vector<Node*> leaf;
    inorder(root, leaf);  // Correct: Collect all leaf nodes using inorder traversal

    vector<vector<int>> ans;
    for (int i = 0; i < leaf.size(); i++) {
        vector<int> temp;
        
        // Mistake:
        // You are passing `leaf[i]->data` as the target value `x`, which is correct.
        // However, make sure that the `getpath()` correctly tracks the path. 
        // Now this works as you are building the `temp` vector correctly inside `getpath()`.
        
        if (getpath(root, leaf[i]->data, temp)) {
            ans.push_back(temp);  // Correct: Add the path to the answer if valid
        }
    }
    return ans;  // Correct: Return the list of all root-to-leaf paths
}

};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        Node* root = inputTree();
        
        Solution obj;
        vector<vector<int>> res = obj.Paths(root);
        
        Matrix::print(res);
        
    }
}

// } Driver Code Ends