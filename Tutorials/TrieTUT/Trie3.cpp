#include <bits/stdc++.h> 
 class TrieNode{
    TrieNode* childrens[26];
    int countEnd;
    int countprefix;

    public:
     TrieNode()
     {
        countEnd=0;
        countprefix=0;
        for(int i=0;i<26;i++)
          childrens[i]=NULL;
     }

     bool containsKey(char ch)
     {
        return childrens[ch-'a']!=NULL;
     }

     TrieNode* get(char ch)
     {
        return childrens[ch-'a'];
     }

     void put(char ch,TrieNode* node)
     {
        childrens[ch-'a']=node;
     }

     void increaseEnd()
     {
         countEnd++;
     }

     void increasePrefix()
     {
         countprefix++;
     }
     void reduceEnd()
     {
         countEnd--;
     }
     void reducePrefix()
     {
         countprefix--;
     }

     int getEnd(){
         return countEnd;
     }

     int getPrefix(){
         return countprefix;
     }
     
};
class Trie{
     TrieNode* root;
    public:

    Trie(){
        // Write your code here.
        root=new TrieNode();
    }

    void insert(string &word){
        // Write your code here
        TrieNode* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new TrieNode());
            }
            node=node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        TrieNode* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
              return 0;
            node=node->get(word[i]);  
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        TrieNode* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
              return 0;
            node=node->get(word[i]);  
        }
        return node->getPrefix();
    }

    void erase(string &word){   //giving prefix to erase will result in cntEnt in negative as no word exists so first check if it is >=1
        // Write your code here.  // giving wrong word will resukt in deleteing prefixes count of available chars
        TrieNode* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(node->containsKey(word[i]))
            {
                node=node->get(word[i]);
                node->reducePrefix();
            }else
             return;
        }
        node->reduceEnd();
    }
};
