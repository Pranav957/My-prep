/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<bits/stdc++.h>
using namespace std;

class Node{
    
    Node* childrens[26];
    bool isTerminal=false;
    
    public:
     Node()
    {
        isTerminal=false;
        for(int i=0;i<26;i++)
            children[i]=NULL;
    }

    bool containsKey(char ch)
    {
        return childrens[ch-'a']!=NULL;
    }
    
    Node* get(char ch)
    {
        return childrens[ch-'a'];
    }
    
    void put(char ch, Node* node)
    {
        childrens[ch-'a']=node;
    }
    
    void setEnd()
    {
        isTerminal=true;
    }
    
    bool isEnd()
    {
        return isTerminal;
    }
};


class Trie {
    
    public:
       Node* root;
       
       Trie()
       {
           root=new Node();
       }
       
       void insert(string word)
       {
         Node* node=root;
         for(int i=0;i<word.size();i++)
         {
             if(!node->containsKey(word[i]))
             {
                 node->put(word[i],node);
             }
             node=node->get(word[i]);
         }
         node->setEnd();
       }
       
       
       bool search(string word)  //O(len)
       {
         Node* node=root;
         for(int i=0;i<word.size();i++)
         {
             if(!node->containsKey(word[i]))
              return false;
              node=node->get(word[i]);
         }
         return node->isEnd();
       }
       
       
       bool startsWith(string prefix)
       {
           Node* node=root;
         for(int i=0;i<prefix.size();i++)
         {
             if(!node->containsKey(prefix[i]))
              return false;
              node=node->get(prefix[i]);
         }
         return true;
       }
};


int main()
{
    std::cout<<"Hello World";
    Trie x;
    x.insert("help");
    x.insert("happy");
    cout<<x.search("happy")<<" "<<x.search("hello")<<endl;
    cout<<x.startsWith("hel");

    return 0;
}
