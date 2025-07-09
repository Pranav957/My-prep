/*You are required to complete this method */

class Node{
    
    Node* childrens[26];
    
    public:
     Node()
    {
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
};   


int countDistinctSubstring(string s) {
    // Your code here
    Node* root=new Node();
        int cnt=0;
        
        for(int i=0;i<s.length();i++)
        {
            Node* node=root;
            for(int j=i;j<s.length();j++)
            {
                if(!node->containsKey(s[j]))
                {
                   cnt++;
                   node->put(s[j],new Node());
                }
                node=node->get(s[j]);
            }
        }
        return cnt+1;
}
