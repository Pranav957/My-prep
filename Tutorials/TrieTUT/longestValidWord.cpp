class Node{
    
    Node* childrens[26];
    bool isTerminal=false;
    
    public:
     Node()
    {
        isTerminal=false;
        for(int i=0;i<26;i++)
            childrens[i]=NULL;
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
                 node->put(word[i],new Node());
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

};
class Solution {
    bool checkIfPrefixExists(string word,Trie tri)
    {
        string str="";
        for(int i=0;i<word.length();i++)
        {
           str+=word[i];
           if(tri.search(str)==false)
            return false;
        }
        return true;
    }
    public:
    string longestValidWord(vector<string>& words) {
        // code here
        Trie tri;
        
        for(auto & it:words)
        {
            tri.insert(it);
        }
        
        string longest="";
        
       for(auto & it:words)
       {
           if(checkIfPrefixExists(it,tri))
           {
               if(it.length()>longest.length())
                 longest=it;
                else if(it.length()==longest.length() && it<longest)
                 longest=it;
                
           }
       }
       return longest;
        
    }
};
