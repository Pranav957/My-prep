#include<vector>
class PriorityQueue {
    // Declare the data members here
    vector<int> v;
   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        v.push_back(element);
     int  childindex=v.size()-1;
      
       while(childindex>0)
       {
          int parentindex=(childindex-1)/2;
           if(v[childindex]>v[parentindex])
            {
                int temp=v[childindex];
                v[childindex]=v[parentindex];
                v[parentindex]=temp;
            } 
           else
              break;
            childindex=parentindex;   
       }

    }

    int getMax() {
        // Implement the getMax() function here
        if(v.empty())
           return 0;
         return v[0];  

    }

    int removeMax() {
        // Implement the removeMax() function here
        int ans=v[0];
        v[0]=v[v.size()-1];
        v.pop_back();
        int parentindex=0;
        int lchildindex=parentindex*2+1;
        int rchildindex=parentindex*2+2;
        int maxindex;
        while(lchildindex<v.size())
        {
            if(rchildindex<v.size())
            {
                 if(v[lchildindex]>v[rchildindex])
                   maxindex=lchildindex;
                 else
                   maxindex=rchildindex;    
            }
            else
              maxindex=lchildindex;
           if(v[parentindex]<v[maxindex])
           {
               int temp=v[parentindex];
               v[parentindex]=v[maxindex];
               v[maxindex]=temp;
           } 
           parentindex=maxindex;
           lchildindex=parentindex*2+1;
         rchildindex=parentindex*2+2;
        }
        return ans;
    }

    int getSize() { 
        // Implement the getSize() function here
        return v.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
       return v.size()==0;
    }
};
/*void insert(int element) {
       // Implement the insert() function here
       v.push_back(element);
       int childindex=v.size()-1;
       while(childindex>0)
       {
           int parentindex=(childindex-1)/2;
           if(v[parentindex]<v[childindex])
              {
                  int temp=v[childindex];
                  v[childindex]=v[parentindex];
                  v[parentindex]=temp;
              }
              else
              break;
              parentindex=childindex;
       }

   }

   int getMax() {
       // Implement the getMax() function here
       if(v.empty())
         return INT_MAX;
       return v[0];

   }

   int removeMax() {
       // Implement the removeMax() function here
       if(v.empty())
          return INT_MAX;
       int ans=v[0];
       v[0]=v[v.size()-1];
       v.pop_back();
       int parentindex=0;
       int lchildindex=2*parentindex+1;
       int rchildindex=2*parentindex+2;
       int maxindex=0;
       while(lchildindex<v.size())
       {
           if(rchildindex<v.size())
              if(v[lchildindex]<v[rchildindex])
                  maxindex=rchildindex;
              else
                 maxindex=lchildindex;
           else
             maxindex=rchildindex;
           if(v[parentindex]<v[maxindex])
           {int temp=v[parentindex];
           v[parentindex]=v[maxindex];
           v[maxindex]=temp;
           }
           parentindex=maxindex;
          int lchildindex=2*parentindex+1;
       int rchildindex=2*parentindex+2;
       }

   }

   int getSize() {
       // Implement the getSize() function here
       return v.size();
   }

   bool isEmpty() {
       // Implement the isEmpty() function here
       return v.size()==0;
   }
};*/