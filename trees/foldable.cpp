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

 class BinaryTree {
     public:
     bool issimilar(TreeNode* n1,TreeNode* n2)
     {
         if(n1 == NULL && n2 == NULL )
         {
             return true;
         }
         if(n1 == NULL || n2 == NULL)
         {
             return false;
         }
         return issimilar(n1->left , n2->left) && issimilar(n1->right ,n2->right );
     }
 	 bool isFoldable(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL) )
        {
            return true;
        }
        if((root->left == NULL && root->right != NULL) || root->left != NULL && root->right == NULL)
        {
            return false;
        }

        return  issimilar(root->left->left , root->right->right) && issimilar(root->left->right , root->right->left) ;
 	 }

     string levelOrder(TreeNode* root) {
 	 	 if(root == NULL){
             return "[]";
         }
         string output = "";
 	 	 queue<TreeNode*> nodeQueue;
 	 	 nodeQueue.push(root);
 	 	 while (nodeQueue.size() > 0) {
 	 	 	 TreeNode* node = nodeQueue.front();
             nodeQueue.pop();

 	 	 	 if (node == NULL) {
 	 	 	 	 output += "null ";
 	 	 	 	 continue;
 	 	 	 }

 	 	 	 output += to_string(node->val) + " ";
 	 	 	 nodeQueue.push(node->left);
 	 	 	 nodeQueue.push(node->right);
 	 	 }
 	 	 return output;
 	 }

 	 // Don't make any changes here
 	 void inOrder(TreeNode* node) {
 	 	 if (node == NULL) {
 	 	 	 return;
 	 	 }

 	 	 inOrder(node->left);
 	 	 cout<<node->val<<" ";
 	 	 inOrder(node->right);
 	 }

     void printPostorder(TreeNode* node) {
 	 	 if (node == NULL)
 	 	 	 return;

 	 	 printPostorder(node->left);
 	 	 printPostorder(node->right);
 	 	 cout<<node->val<<" ";
 	 }

 	 void printPreorder(TreeNode* node) {
 	 	 if (node == NULL)
 	 	 	 return;

 	 	 cout<<node->val<<" ";
 	 	 printPostorder(node->left);
 	 	 printPostorder(node->right);
 	 }

 };

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
     TreeNode* root = stringToTreeNode(line);
     BinaryTree bt;
     if(bt.isFoldable(root)){
         cout<<"true";
     }
     else{
         cout<<"false";
     }
 }
