/*
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
    void leftSubtree(Node *root, vector<int>& ans)
    {
        if(root == NULL)
        {
            return;
        }
        if(root->left == NULL && root->right == NULL)
        {
            return;
        }
        
        ans.push_back(root->data);
        if(root->left != NULL)
        {
            leftSubtree(root->left, ans);
        }
        else
        {
            leftSubtree(root->right, ans);
        }
    }
    void leafNode(Node *root, vector<int> &ans)
    {
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right ==NULL)
        {
            ans.push_back(root->data);
        }
        
        leafNode(root->left, ans);
        leafNode(root->right, ans);
    }
    void rightSubtree(Node *root, vector<int> &ans)
    {
        if(root == NULL)
        {
            return;
        }
        if(root->left == NULL && root->right == NULL)
        {
            return;
        }
        
        if(root->right != NULL)
        {
            rightSubtree(root->right, ans);
        }
        else{
            rightSubtree(root->left, ans);
        }
        
        ans.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        
        
        if(root == NULL)
        {
            return ans;
        }
        
        ans.push_back(root->data);
        
        
        leftSubtree(root->left, ans);
        leafNode(root->left, ans);
        leafNode(root->right, ans);
        rightSubtree(root->right, ans);
        
        
        return ans;
        /*1. root node
        
          2. root left subtree
          3. root left leaf
          4. root right leaf
          5. root right subtree
        */
    
    }
};