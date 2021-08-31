/**
 * Definition for a binary tree node.
 */
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        vector<int> nums;
        vector<vector<int>> rs;
        dfs(root,nums,rs);
        int sum=0;
        for(vector<int> path:rs){
            int s=0;
            for(int node:path){
                cout<<node;
                s=s*10+node;
            }
            sum+=s;
            cout<<endl;
        }
        return sum;
    }
    void dfs(TreeNode* root,vector<int> nums,vector<vector<int>>& rs){
        if(root == nullptr){
            return;
        }
        if(root->left==nullptr&&root->right==nullptr){
            nums.push_back(root->val);
            rs.push_back(nums);
            return;
        }
        nums.push_back(root->val);
        dfs(root->left,nums,rs);
        dfs(root->right,nums,rs);
    }
};
int main(){
    Solution solution;
    TreeNode* root=new TreeNode(1);
    TreeNode* leftNode=new TreeNode(2);
    leftNode->left= nullptr;
    leftNode->right= nullptr;
    TreeNode* rightNode=new TreeNode(3);
    rightNode->left= nullptr;
    rightNode->right= nullptr;
    root->left=leftNode;
    root->right=rightNode;
    int rs=solution.sumNumbers(root);
    cout<<rs<<endl;
}