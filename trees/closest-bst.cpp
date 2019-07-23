#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
bool mycomp(const pair<int,float> &p1 , const pair<int,float> &p2)
{
         return (p1.second < p2.second);
}
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

 class BinaryTree {
     public:
         queue<TreeNode*> q;
     void helper(TreeNode* root, double target, int k)
     {
         if( !root )
         {
             return ;
         }
             helper(root->left , target , k);
             if(q.size() < k )
             {
                 q.push(root);
             }
             else if(abs(q.front()->val - target) > abs(root->val - target))
             {
                q.pop();
                q.push(root);

             }
             helper(root->right , target , k);
     }

     vector<int> closestKValues(TreeNode* root, double target, int k) {
 	     	 vector<int> v;
 	     	 helper(root , target , k);
 	     	 while(!q.empty())
             {
                 v.push_back(q.front()->val);
                 q.pop();
             }
             vector<pair<int,float>> p;
            //  for(int i=0;i<v.size();i++)
            //  {
            //      p.push_back(make_pair(v[i], abs((float)target-(float)v[i])));
            //  }
            //  sort(p.begin(), p.end(),mycomp);
            //  for(int i=0;i<p.size();i++)
            //  {
            //      v[i] = p[i].first;
            //  }
            reverse(v.begin() , v.end());
             return v;
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

     string levelOrder(TreeNode* node) {
 	 	 if(node==NULL){
             return "[]";
         }
         string output="";
 	 	 queue<TreeNode*> q;
 	 	 q.push(node);

 	 	 while (q.size() > 0) {
 	 	 	 TreeNode* curr = q.front();
             q.pop();
             if(curr==NULL){
                 output+="null ";
                 continue;
             }
 	 	     output+=to_string(curr->val)+" ";
             q.push(curr->left);
             q.push(curr->right);
 	 	 }
         return output;
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

 //Don't change code of utility function.
 TreeNode* stringToTreeNode(string input) {
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


 void displayList(vector<int>& v){
     cout<<"[";
     for(int i=0;i<v.size();i++){
         cout<<v[i];
         if(i!=v.size()-1){
             cout<<", ";
         }
     }
     cout<<"]"<<endl;
 }
 int main(int argc, char** argv){
     string line;
     getline(cin, line);
     TreeNode* root = stringToTreeNode(line);
     BinaryTree bt;
     double target;
     cin>>target;
     int k;
     cin>>k;
     vector<int> res=bt.closestKValues(root,target,k);
     displayList(res);

 }
