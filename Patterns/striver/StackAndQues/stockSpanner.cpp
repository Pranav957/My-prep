class StockSpanner {
    vector<int> v;
    int n;
public:
    StockSpanner() {
        n=0; 
    }
    
    int next(int price) {
        v.push_back(price);
        n++;
        int cnt=0;
        for(int i=n-1;i>=0;i--)
        {
            if(v[i]<=price)
             cnt++;
            else
             break;  
        }
        return cnt;
    }
};
************************************************************************
class StockSpanner {
    stack<pair<int,int>> st;
    int ind=-1;
public:
    StockSpanner() {
        ind=-1;
        // st.clear();
    }
    
    int next(int price) {
        ind+=1;
       while(!st.empty() && st.top().first<=price)
        st.pop();
        int ans;

       if(st.empty())
         ans= ind-(-1);
       else
        ans= ind-st.top().second;

       st.push(make_pair(price,ind));   
       return ans;
    }
};
