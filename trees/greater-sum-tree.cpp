#include<iostream>
 #include<vector>
 using namespace std;

 // TreeNode class for a node of a Binary Search Tree
 class TreeNode {
     public:
 	 int val;
 	 TreeNode* left;
 	 TreeNode* right;

 	 TreeNode(int x) {
 	 	 val = x;
         left = NULL;
         right = NULL;
 	 }
 };

 // utility function to display a binary tree
 void display(TreeNode* node) {
     if (node == NULL) {
         return;
     }
     string str = "";

     str += node->left == NULL ? "." : to_string(node->left->val);
     str += " <= " + to_string(node->val) + " => ";
     str += node->right == NULL ? "." : to_string(node->right->val);

     cout<<str<<endl;

     display(node->left);
     display(node->right);
 }

 // creation of tree from array by level order, -1 says there is no node
 TreeNode* levelOrder(vector<int> &arr) {

     vector<TreeNode*> nodes(arr.size());
     for (int i = 0; i < nodes.size(); i++) {
         if (arr[i] != -1) {
             TreeNode* t = new TreeNode(arr[i]);
             nodes[i] = t;

             if (i > 0) {
                 int pi = (i - 1) / 2;
                 if (i == 2 * pi + 1) {
                     nodes[pi]->left = nodes[i];
                 } else {
                     nodes[pi]->right = nodes[i];
                 }
             }
         }
     }
     TreeNode* root = nodes[0];
     return root;
 }
 int sum = 0;
 TreeNode* bstToGst(TreeNode* root) {
    if(root == NULL)
        return root;
    //reverse inorder
    root->right = bstToGst(root->right);
    sum = sum + root->val;
    root->val = sum;
    root->left = bstToGst(root->left);
    return root;
 }


 int main(int argc, char** argv){
     int len;
     cin>>len;

     vector<int> arr(len);
     for (int i = 0; i < len; i++) {
         cin>>arr[i];
     }
     TreeNode* root = levelOrder(arr);
     TreeNode* resultRoot = bstToGst(root);

     display(resultRoot);
 }
