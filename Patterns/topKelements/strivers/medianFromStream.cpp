class MedianFinder {
    priority_queue<int> left;
        priority_queue<int,vector<int>,greater<int>> right;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(!left.empty() && num>left.top())
          right.push(num);
        else
          left.push(num);

         int diff = abs((int)(left.size() - right.size()));
        if(diff>1)
        {
            if(left.size()>right.size())
            {
                int x=left.top();
                left.pop();
                right.push(x);
            }
            else
              {
                int x=right.top();
                right.pop();
                left.push(x);
              }
        }    
         
    }
    
    double findMedian() {
       if(left.size()>right.size())
         return left.top();
      else if(right.size()>left.size())
        return right.top();
       else
       {
        return (double)(left.top()+right.top())/2;
       } 
     }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
