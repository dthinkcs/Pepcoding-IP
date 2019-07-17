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

 vector<double> averageOfLevels(TreeNode* root) {

    vector<double> v;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        int c = q.size();
        int tel = c;
        double sum = 0;
        while(c--)
        {
            TreeNode * curr = q.front();
            sum += curr->val;
            q.pop();

            if(curr->left !=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right !=NULL)
            {
                q.push(curr->right);
            }
        }
        cout<<sum<<endl;
        v.push_back(1.0 * sum/tel);
    }
    return v;
}

 int main(int argc, char** argv){
     int x;

 	 string line;
     getline(cin, line);
     TreeNode* root = stringToTreeNode(line);
 	 vector<double> res = averageOfLevels(root);
 	 for(double i: res){
 	 	 cout<<i<<" ";
 	 }
     cout<<endl;
 }
