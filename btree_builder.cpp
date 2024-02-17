#include <bits/stdc++.h>
using namespace std;
#define space " "
#define nextLine "\n"

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

const int nullIntConst = -1e4-7;

TreeNode* getTreeFromLevelOrder(vector <int> levelOrder) {
    int i = 0;

    TreeNode* root = new TreeNode(levelOrder[i++]);

    queue <TreeNode*> q;
    q.push(root);

    while(!q.empty() and i < levelOrder.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (levelOrder[i] != nullIntConst) {
            TreeNode* new_node = new TreeNode(levelOrder[i++]);
            curr -> left = new_node;
            q.push(curr -> left);
        } else {
            i++;
        }
        if (i < levelOrder.size() and levelOrder[i] != nullIntConst) {
            TreeNode* new_node = new TreeNode(levelOrder[i++]);
            curr -> right = new_node;
            q.push(curr -> right);
        } else {
            i++;
        }
    }
    return root;
}

void printTreeNode(TreeNode* root) {
    if (root == nullptr) {
        cout << "NULL\t";
        return;
    }
    cout << root -> val << "\t";
}

void TreePrinter(TreeNode* root) {
    queue <TreeNode*> q;
    q.push(root);
    cout << "Printing Tree" << endl;
    while(!q.empty()) {

        int n = q.size();

        for (int i = 0; i < n; i++) {
            TreeNode* curr = q.front();
            q.pop();
            
            printTreeNode(curr);

            if (curr == nullptr) continue;

            q.push(curr -> left);
            q.push(curr -> right);

        }
        cout << "\n";
    }
}

int main() {
    
    vector<int> levelOrder = {};
    
    TreeNode* root = getTreeFromLevelOrder(levelOrder);
    TreePrinter(root);

    // solution
    Solution* obj = new Solution();
    TreeNode* res = obj -> leetcodeFuncName(root);

    TreePrinter(res);
    
}

