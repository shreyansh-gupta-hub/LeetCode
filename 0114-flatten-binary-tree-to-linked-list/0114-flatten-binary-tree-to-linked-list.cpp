/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* merge(TreeNode* list1,TreeNode* list2){
        TreeNode* DummyTreeNode = new TreeNode(-1);
        TreeNode* res = DummyTreeNode;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<list2->val){
                res->right = list1;
                res = list1;
                list1 = list1->right;
            }else{
                res->right = list2;
                res = list2;
                list2 = list2->right;
            }
            res->left = NULL;
        }
        if(list1) res->right = list1;
        if(list2) res->right = list2;
        TreeNode* temp = DummyTreeNode->right;
        while(temp) {
            temp->left = nullptr;
            temp = temp->right;
        }
        return DummyTreeNode->right;
    }
    TreeNode *flattenx(TreeNode *root) {
        // code here
        if(root == NULL || root->left == NULL) return root;
        TreeNode* merged_root = flattenx(root->left);
        return merge(root,merged_root);
        
    }    
    void flatten(TreeNode* root) {
        if (!root) return;

        flatten(root->left);
        flatten(root->right);

        TreeNode* tmpRight = root->right;
        root->right = root->left;
        root->left = nullptr;

        TreeNode* curr = root;
        while (curr->right) curr = curr->right;
        curr->right = tmpRight;
    }
};