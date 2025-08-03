/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */
void sortStack(stack<int>& s, int x)
{
    if(s.empty()|| x>s.top())
     {
         s.push(x);return; 
     }
     
     int temp=s.top();
     s.pop();
     sortStack(s,x);
     s.push(temp);
}
void sorting(stack<int>& s)
{
    if(s.empty())
     return;
    
    int x=s.top();
    s.pop();
    sorting(s);
    sortStack(s,x);
}
void SortedStack ::sort() {
    // Your code here
    return sorting(s);
}
