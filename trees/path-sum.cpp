#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
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

 // This is a functional problem. You have to complete this function.
 // It takes as input the root node of the given tree and the given sum.
 // It should return true if the tree has required path, else should return false.
 bool helper(TreeNode* root, int sum , int ssf)
 {
     if(root == NULL)
     {
         return false;
     }
     if(root->left == NULL && root->right == NULL)
     {
         ssf += root->val;
         if(ssf == sum)
         {
             return true;
         }
         else
         {
             return false;
         }
     }
     ssf += root->val;
     bool a = helper(root->left , sum,ssf);
     bool b = helper(root->right , sum ,ssf);
     ssf -= root->val;
     return a||b;
 }
 bool hasPathSum(TreeNode* root, int sum) {
     return helper(root,sum,0);

 }

 //Don't change code of utility function.
 TreeNode* stringToTreeNode(string &input) {
     int first = input.find_first_not_of(' ');
     int last = input.find_last_not_of(' ');
     input = input.substr(first, (last - first + 1));
     if (!input.size()) {
         return nullptr;
     }

     string item;
     stringstream ss;
     ss.str(input);

     getline(ss, item, ' ');
     TreeNode* root = new TreeNode(stoi(item));
     queue<TreeNode*> nodeQueue;
     nodeQueue.push(root);

     while (true) {
         TreeNode* node = nodeQueue.front();
         nodeQueue.pop();
         if (!getline(ss, item, ' ')) {
             break;
         }

         if (item != "null") {
             int leftNumber = stoi(item);
             node->left = new TreeNode(leftNumber);
             nodeQueue.push(node->left);
         }

         if (!getline(ss, item, ' ')) {
             break;
         }

         if (item != "null") {
             int rightNumber = stoi(item);
             node->right = new TreeNode(rightNumber);
             nodeQueue.push(node->right);

         }
     }
     return root;
 }

 int main(int argc, char** argv){
     string line;
     getline(cin, line);
     int sum;
     cin>>sum;
     TreeNode* root = stringToTreeNode(line);
     if(hasPathSum(root, sum)){
         cout<<"Yes"<<endl;
     }else{
         cout<<"No"<<endl;
     }
 }
