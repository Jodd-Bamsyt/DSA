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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        queue<TreeNode*> cue ; 
        if(root == NULL) return ans;

        cue.push(root) ; 
        bool flag = true;

        


        while(!cue.empty()){
            int size = cue.size();
            vector<int>level(size) ; 

            for(int  i = 0 ; i < size ; i++){
                TreeNode* node = cue.front() ; 
                cue.pop() ;
                int index = flag ? i : (size-i-1);
                if(node->left != NULL) cue.push(node->left);
                if(node->right != NULL) cue.push(node->right);
                level[index] = node->val;

            }
            flag = !flag ; 
            ans.push_back(level);
        }
        return ans;
        
    }
};


