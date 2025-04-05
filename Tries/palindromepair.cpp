class TrieNode {
    public:
     char data;
     TrieNode **children;
     bool isTerminal;
     int childCount;
 
     TrieNode(char data) {
         this->data = data;
         children = new TrieNode *[26];
         for (int i = 0; i < 26; i++) {
             children[i] = NULL;
         }
         isTerminal = false;
         childCount = 0;
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
 
     bool add(TrieNode *root, string word) {
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
             root->childCount++;
         }
 
         // Recursive call
         return add(child, word.substr(1));
     }
 
     void add(string word) {
         if (add(root, word)) {
             this->count++;
         }
     }
 
     /*..................... Palindrome Pair................... */
     bool Checkpalindrome(string str)
     {
         int i=0,j=str.length()-1;
         while(i<=j)
         {
             if(str[i]!=str[j])
                  return false;
                  i++;
                  j--;
         }
         return true;
     }
  bool isPalindromePair(vector<string> words) {
       // Write your code here
       for (int i = 0; i < words.size(); i++) {
         this->add(words[i]);
       }
       for (int i = 0; i < words.size(); i++) {
         string entry = words[i];
         bool check = Checkpalindrome(entry);
         if (check)
           return true;
           for(int j=i+1;j<words.size();j++)
           {
               bool maketry=Checkpalindrome(words[i]+words[j]);
               if(maketry)
                 return true;
           }
         /*string str = "";
         for (int j = entry.length() - 1; j >= 0; j--)
           str += entry[j];
         int j;
         for (j = 0; j < entry.length(); j++) {
           if (entry[j] != str[j])
             break;
         }
         if (j == entry.size())
           return true;*/
       }
       return false;
     }
 };