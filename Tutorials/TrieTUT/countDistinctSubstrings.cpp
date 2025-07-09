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

int countDistinctSubstring(string str)
{
    // Put all distinct substring in a HashSet
    set<string> result ;

    // List All Substrings
    for (int i = 0; i <= str.length(); i++)
    {
        for (int j = 1; j <= str.length()-i; j++)
        {

            // Add each substring in Set
            result.insert(str.substr(i, j));
        }
    }

    // Return size of the HashSet
    return result.size()+1;
}
******************************************************************************************************************************************888
    int countDistinctSubstring(string str)
{
    TrieNode* head = new TrieNode();

    // will hold the count of unique substrings
    int count = 0;
    // included count of substr " "

    for (int i = 0; i < str.length(); i++) {
        TrieNode* temp = head;

        for (int j = i; j < str.length(); j++) {
            // when char not present add it to the trie
            if (temp->child[str[j] - 'a'] == NULL) {
                temp->child[str[j] - 'a'] = new TrieNode();
                temp->isWord = 1;
                count++;
            }
            // move on to the next char
            temp = temp->child[str[j] - 'a'];
        }
    }

    return count;
}

