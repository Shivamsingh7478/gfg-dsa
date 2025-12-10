/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 0));
        unordered_map<int, Node*> map;
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        
        while(!q.empty())
        {
            pair<Node*, int> frontElement = q.front();
            
            q.pop();
            
            Node* frontNode = frontElement.first;
            int hd = frontElement.second;
            minimum = min(minimum, hd);
            maximum = max(maximum, hd);
            
            if(map.find(hd) == map.end())
            {
                map[hd] = frontNode;
            }
            
            if(frontNode->left != NULL)
            {
                q.push(make_pair(frontNode->left, hd-1));
            }
            
            if(frontNode->right != NULL)
            {
                q.push(make_pair(frontNode->right, hd+1));
            }
        }
        
        vector<int> ans;
        for(int i=minimum;i<=maximum;i++)
        {
            Node* temp = map[i];
            ans.push_back(temp->data);
        }
        return ans;
    }
};