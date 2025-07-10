class Node{
    Node* links[2];

    public:

    bool containsKey(int bit)
    {
        return links[bit]!=NULL;
    }

    Node* get(int bit)
    {
        return links[bit];
    }

    void put(int bit,Node* node)
    {
        links[bit]=node;
    }
};
class Trie{
     Node* root;
     public:
     Trie()
     {
        root=new Node();
     }
     
     void insert(int num)
     {
        Node* node=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;  //is ith bit set or not for num
            if(!node->containsKey(bit))
            { 
                node->put(bit,new Node());
                node=node->get(bit);
            }
            else
             node=node->get(bit);
        }
     }
     int getMax(int num)
     {
        Node* node=root;
        int maxNum=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(node->containsKey(1-bit))
            {
                maxNum=maxNum |(1<<i); //turned ith bit of maxNum
                node=node->get(1-bit);
            }
            else
            node=node->get(bit);
        }
        return  maxNum;
     }

};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
       int n=nums.size();
       int m=queries.size();
       vector<int> ans(m);

       sort(nums.begin(),nums.end());

       vector<pair<int,pair<int,int>>> oQ;
       
       for(int i=0;i<m;i++)
       {
        oQ.push_back({queries[i][1],{queries[i][0],i}});
       }
       sort(oQ.begin(),oQ.end());

       Trie trie;
       int ind=0;
       for(int i=0;i<m;i++)
       {
          int xi=oQ[i].second.first;
          int  mi=oQ[i].first;
          int qInd=oQ[i].second.second;
          while(ind<n && nums[ind]<=mi)
          {
             trie.insert(nums[ind]);
             ind++;
          }
          if(ind==0) ans[qInd]=-1;
          else
           ans[qInd]=trie.getMax(xi);
       }
       return ans;
    }
};
