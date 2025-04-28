int getNext(int n)
    {
        int sum=0;
        while(n>0)
        {
            int digit=n%10;
            sum+=digit* digit;
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> set1;
        while(n!=1)
        {
             n= getNext(n);
          if(set1.find(n)!=set1.end())
            return false;  
         
          set1.insert(n);
        } 
        return true; 
    }
