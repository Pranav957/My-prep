#include<bits/stdc++.h>
using namespace std;

int countBracketReversals(string input) {
    int n = input.length();
    
    // If length is odd, impossible to balance
    if (n % 2 != 0) {
        return -1;
    }

    stack<char> s;
    
    for (int i = 0; i < n; i++) {    //remove all balanced pairs and keep only unbalanced in stack
        if (input[i] == '{') {
            s.push('{');
        } else { // input[i] == '}'
            if (!s.empty() && s.top() == '{') {
                s.pop();
            } else {
                s.push('}');
            }
        }
    }

    int count = 0;
    while (!s.empty()) {                       //pop two unbalanced each time and do the calculations
        char c1 = s.top(); s.pop();
        char c2 = s.top(); s.pop();
        
        if (c1 == c2) {
            count += 1;
        } else {
            count += 2;
        }
    }

    return count;
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ANOTHER APPROCH<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    #include<stack>
int countBracketReversals(string input) {
	// Write your code here
	stack<int> st;
	if(input.length()%2==0)
	{
		int x=0;
       for(int i=0;i<input.length();i++)
	   {
		   if(input[i]=='{')
		   {
                st.push(input[i]);
           }  
		   else
		      {
				  if(st.empty())
				   {
                     st.push(input[i]);
					 ++x;
                   } 
				 else	 
                     st.pop();	
              }
	   }
	   int ans=st.size();
	   return (ans/2)+x;
	}
	else
	 return -1;
}
