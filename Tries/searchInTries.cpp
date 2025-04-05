class TrieNode {
    public:
     char data;
     TrieNode **children;
     bool isTerminal;
 
     TrieNode(char data) {
         this->data = data;
         children = new TrieNode *[26];
         for (int i = 0; i < 26; i++) {
             children[i] = NULL;
         }
         isTerminal = false;
     }
 };
 
 class Trie {
     TrieNode *root;
 
    public:
     int count;
 
     Trie() {
         this->count = 0;
         root = new TrieNode('\0');
     }
 
     bool insertWord(TrieNode *root, string word) {
         // Base case
         if (word.size() == 0) {
             if (!root->isTerminal) {
                 root->isTerminal = true;
                 return true;
             } else {
                 return false;
             }
         }
 
         // Small calculation
         int index = word[0] - 'a';
         TrieNode *child;
 
         if (root->children[index] != NULL) {
             child = root->children[index];
         } else {
             child = new TrieNode(word[0]);
             root->children[index] = child;
         }
 
         // Recursive call
         return insertWord(child, word.substr(1));
     }
 
     void insertWord(string word) {
         if (insertWord(root, word)) {
             this->count++;
         }
     }
    void autoComplete(TrieNode * root, string output)
    {
        if(root->isTerminal)
          cout<<output<<endl;
         for(int i=0;i<26;i++)
         {
             if(root->children[i]!=NULL)
                autoComplete(root->children[i],output+root->children[i]->data);
         } 
    }
     void autoComplete(vector<string> input, string pattern) {
         // Write your code here
         for(int i=0;i<input.size();i++)
         {
             this->insertWord(input[i]);
         }
        TrieNode* node=root;
        for(int i=0;i<pattern.length();i++)
        {
            int index=pattern[i]-'a';
            if(node->children[index]==NULL)
              return;
            node=node->children[index];  
        }
         autoComplete(node,pattern);
     }
 };