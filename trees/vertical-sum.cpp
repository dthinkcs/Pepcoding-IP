#include<iostream>
 #include<vector>
 #include<queue>
 #include<bits/stdc++.h>
 using namespace std;

 // TreeNode class for a node of a Binary Search Tree
 class TreeNode {
     public:
 	 int data;
 	 TreeNode* left;
 	 TreeNode* right;

 	 TreeNode(int x) {
 	 	 data = x;
         left = NULL;
         right = NULL;
 	 }
 };


 class BinaryTree {

     public:
     void helper(TreeNode * root , int level , unordered_map<int ,int> &m)
     {
         if(root == NULL)
         {
             return ;
         }

         helper(root->left , level - 1, m);
         helper(root->right , level + 1 , m);
         if(m.count(level))
         {
             m[level] += root->data;
         }
         else
         {
             m[level ] = root->data;
         }

     }

     void printVertical(TreeNode* root) {
         unordered_map<int , int> m;
 	     helper(root , 0 , m);
 	      vector<pair<int,int> > v;
 	      unordered_map<int ,int> :: iterator it;
 	      for(it = m.begin() ; it != m.end() ; it++)
          {
              v.push_back({it->first,it->second});
          }
          sort(v.begin() , v.end());
          for(int i = 0; i < v.size() ; i++)
          {
              cout<< v[i].second<< " ";
          }
 	 }



 };

 void insert(TreeNode* root, int a, int a1, char lr) {
     if (root == NULL) {
         return;
     }
     if (root->data == a) {
         switch (lr) {
         case 'L':
             root->left = new TreeNode(a1);
             break;
         case 'R':
             root->right = new TreeNode(a1);
             break;
         }
         return;
     }
     insert(root->left, a, a1, lr);
     insert(root->right, a, a1, lr);
 }

 // utility function to display a binary tree
 void display(TreeNode* node) {
     if (node == NULL) {
         return;
     }
     string str = "";

     str += node->left == NULL ? "." : to_string(node->left->data);
     str += " <= " + to_string(node->data) + " => ";
     str += node->right == NULL ? "." : to_string(node->right->data);

     cout<<str<<endl;

     display(node->left);
     display(node->right);
 }

 int main(int argc,char** argv) {
     int n ;
     cin>>n;
     TreeNode* root = NULL;

     if (n == 0) {
         cout<<0<<endl;

     }
          for (int i = 0; i < n; i++) {
             int a ;
             cin>>a;
             int a1;
             cin>>a1;

             char lr ;
             cin>>lr;
             if (i == 0) {

                 root = new TreeNode(a);

                 switch (lr) {
                 case 'L':
                     root->left = new TreeNode(a1);
                     break;
                 case 'R':
                     root->right = new TreeNode(a1);
                     break;
                 }
             } else {
                 insert(root, a, a1, lr);
             }
         }
     BinaryTree tree ;

     tree.printVertical(root);

 }
