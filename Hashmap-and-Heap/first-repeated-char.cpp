#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;

 // This is a functional problem. You have to complete this function.
 // It takes as input the String s. It should return the first repeated
 // character if present, else should return $.
 char solve(string& s) {
     // write your code here.
    unordered_set<char> set1;
  for(int i = 0 ; i < s.length() ; i++)
  {
      if(set1.count(s[i]))
        return s[i];
    set1.insert(s[i]);
  }
  return '$';
 }

 int main(int argc,char** argv) {

     string str;
     cin>>str;
     cout<<solve(str)<<endl;

 }
