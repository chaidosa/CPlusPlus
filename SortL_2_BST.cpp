// The Idea is to spilt the list from middle and recursively pass remaining left half and right half to form the tree

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode* Solution::sortedListToBST(ListNode* A) {
    if(A == NULL)
        return NULL;
    struct TreeNode *T = new TreeNode(0);
    if(A->next == NULL){
        T->val = A->val;      
        return T;
    }
    
    
    ListNode *P = A;
    float count = 0;
    while(P != NULL){
       count++;
       P = P->next;
    }
   
    P = A;
    ListNode *L;
    if(count == 2){
        T->left = new TreeNode(A->val);
        T->val = A->next->val;
        T->right = NULL;
        return T;
    }
    //Traversing to middle element of Linked list;
    for(int i = 1; i < ceil(count/2); i++){
        L = P;
       P = P->next;
    }
    L->next = NULL;
    T->val = P->val;
    L = A;
    ListNode *R = P->next;
    //P->next = NULL;
    T->left = sortedListToBST(L);
    T->right = sortedListToBST(R);
    return T;
}
