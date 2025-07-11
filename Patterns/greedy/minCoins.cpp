vector<int> minPartition(int N) {
        // code here
        vector<int> coins;
        
        vector<int> currency={1,2,5,10,20,50,100,200,500,2000};  //fails for( 1,5,6,9) if addition of two grater than third
        
        for(int i=currency.size()-1;i>=0;i--)
        {
            while(currency[i]<=N)
            {
                N-=currency[i];
                coins.push_back(currency[i]);
            }
        }
        return coins;
    }
