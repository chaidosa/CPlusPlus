/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> res;
    stack<TreeNode *> S;
    TreeNode *current = A;

    while(current != NULL || S.empty() == false){
        
        while(current != NULL){
            S.push(current);
            current = current->left;
        }

        current = S.top();
        res.push_back(current->val);
        S.pop();
        current = current->right;

    }
    
  return res;
}

