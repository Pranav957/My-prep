/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    
    public:
     char data;
     TrieNode** children;
     bool isTerminal;
     
     TrieNode(char data)
     {
         this->data=data;
         children=new TrieNode*[26];
         isTerminal=false;
         for(int i=0;i<26;i++)
           children[i]=NULL;
     }
};

class Trie{
    TrieNode* root;
    public:
      Trie()
      {
         root=new TrieNode('\0');
      }
      
      void insert(TrieNode* root, string word)
      {
          if(word.length()==0)
          {
              root->isTerminal=true;
              return;
          }
          
          int index=word[0]-'a';
          TrieNode* child;
          
          if(root->children[index]!=NULL)
          {
              child=root->children[index];
          }
          else{
              child=new TrieNode(word[0]);
              root->children[index]=child;
          }
          insert(child,word.substr(1));
      }
      
      void insert(string word)
      {
          insert(root,word);
      }
      
      bool search(TrieNode* root, string word)
      {
          if(word.length()==0)
          {
              if(root->isTerminal)
                return true;
              return false;        
          }
          
          int index=word[0]-'a';
          if(root->children[index]!=NULL)
          {
             return  search(root->children[index],word.substr(1));
          }
          return false;
      }
      
      bool search(string word)
      {
          return search(root,word);
      }
      
      void removeWord(TrieNode* root, string word)
      {
          if(word.length()==0)
          {
              root->isTerminal=false;
              return;
          }
          
          TrieNode* child;
          int index=word[0]-'a';
          if(root->children[index]!=NULL)
          {
              child=root->children[index];
          }
          else
           return ;
          
          removeWord(child,word.substr(1));
          
          if(child->isTerminal==false)
          {
              for(int i=0;i<26;i++)
              {
                  if(child->children[i]!=NULL)
                   return;
              }
              delete child;
              root->children[index]=NULL;
          }
      }
      
      void removeWord(string word)
      {
          removeWord(root,word);
      }
};

int main()
{
    Trie a;
    a.insert("Hello");
    a.insert("BYE");
    cout<<a.search("Hello")<<endl;
    a.removeWord("Hello");
    cout<<a.search("Hello")<<endl;

    return 0;
}
