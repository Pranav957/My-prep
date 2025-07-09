//to have larger Number -> power of 2s from left

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
                maxNum=maxNum |(1<<i);
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
    int findMaximumXOR(vector<int>& nums) {
       Trie trie;
       for(auto& it:nums)
       {
        trie.insert(it);
       }

       int maxNum=0;

       for(int i=0;i<nums.size();i++)
       {
          maxNum=max(maxNum,trie.getMax(nums[i]));
       }
       return maxNum;
    }
};
