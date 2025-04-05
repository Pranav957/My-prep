#include <vector>

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        // Write your code here
        int ans=pq[0];
        int latindx=pq.size()-1;
        pq[0]=pq[latindx];
        pq.pop_back();
        int parentIndex=0;
        int LCHILDINDX=2*parentIndex+1;
        int RCHILDINDx=2*parentIndex+2;
        int MinIndex;
        while(LCHILDINDX<pq.size())
        {
           if(RCHILDINDx<pq.size())
           {
              if (pq[LCHILDINDX] < pq[RCHILDINDx])
                MinIndex = LCHILDINDX;
              else
                MinIndex = RCHILDINDx;
           }
           else
            MinIndex=LCHILDINDX;
              if(pq[parentIndex]>pq[MinIndex])  
              {
                  int temp=pq[parentIndex];
                  pq[parentIndex]=pq[MinIndex];
                  pq[MinIndex]=temp;
              }    
              else
                break;
              parentIndex=MinIndex;
              LCHILDINDX=2*parentIndex+1;
              RCHILDINDx=2*parentIndex+2;
              
        }
        return ans;
        /*while(parentIndex<pq.size())
        {
           int lcindex=2*parentIndex+1;
           int rcindex=2*parentIndex+2;
           int minindex=0;
           if(lcindex<pq.size() && rcindex<pq.size())
           {
               if(pq[lcindex]<pq[rcindex])
                   minindex=lcindex;
               else
                   minindex=rcindex;    
           }
           else if(lcindex<pq.size())
               minindex=lcindex;
           else if(rcindex<pq.size())
               minindex=rcindex;
            else
               break;
             if(pq[parentIndex]>pq[minindex])
                {
                    int temp=pq[minindex];
                    pq[minindex]=pq[parentIndex];
                    pq[parentIndex]=temp;
                } 
                else
                   break;
               parentIndex=minindex;            
             
        }
        return ans;*/
    }
};