/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector< int > res;
    stack< TreeNode *> S;

    while(A != NULL || S.empty() == false){
        
        while(A != NULL){
            res.push_back(A->val);
            S.push(A);
            A = A->left;
        }

        A = S.top();
        S.pop();
        A = A->right;
    }
    return res;
}

