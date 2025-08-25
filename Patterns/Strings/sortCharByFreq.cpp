
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;

        for(int i=0;i<s.length();i++)
            mp[s[i]]++;

        priority_queue<pair<int,char>> pq;    

          for(auto [x,y]:mp)
          {
              pq.push({y,x});
          }

          string str=""; 

          while(!pq.empty())
          {
             auto [x,y]=pq.top();
             pq.pop();
             for(int i=0;i<x;i++)
              str+=y;
          } 
          return str;
    }
};
********************************************************************************************************************************************
class Solution {
public:
    typedef pair<char, int> P;
    struct comp {
        bool operator()(P &p1, P &p2) {
            return p1.second<p2.second; //max-heap
        }
    };
    
    string frequencySort(string s) {
        priority_queue<P, vector<P>, comp> pq;
        
        unordered_map<char, int> mp;
        for(char &ch : s) {
            mp[ch]++;
        }
        
        for(auto &it : mp) {
            pq.push({it.first, it.second});
        }
        
        string result = "";
        
        while(!pq.empty()) {
            P temp = pq.top();
            pq.pop();
            
            result += string(temp.second, temp.first);
        }
        return result;
    }
};
***************************************using vector***************************************************************************
  //Approach-1 (Using Simple vector of pair and sorting it -  O(nlogn)
class Solution {
public:
    typedef pair<char, int> P;
    
    string frequencySort(string s) {
        vector<P> vec(123);
        
        for(char &ch : s) {
            int freq = vec[ch].second;
            vec[ch] = {ch, freq+1};
        }
        
        auto comp = [&](P &p1, P &p2) {
            return p1.second > p2.second;
        };
        
        sort(begin(vec), end(vec), comp);
        
        string result = "";
        
        for(int i = 0; i <= 122; i++) {
            result += string(vec[i].second, vec[i].first);
        }
        return result;
    }
};
**********************************************************************************************************
int threshold = 2;
sort(v.begin(), v.end(), [threshold](int a, int b){
    return (a % threshold) < (b % threshold);
});

[] → capture nothing.

[=] → capture all outer variables by value (copies).

[&] → capture all outer variables by reference.

[x] → capture variable x by value.

[&x] → capture variable x by reference.

[=, &y] → capture all by value, but y by reference.
