// Change in the given string itself. So no need to return or print anything
int len(char input[])
{
    int count=0;
    for(int i=0;input[i]!='\0';i++)
    {
        count++;
    } 
    return count;
}
void removeX(char input[]) {
    // Write your code here
   if(input[0]=='\0')
       return;
    removeX(input+1);
    if(input[0]=='x')
    {
        for(int i=0;i<len(input);i++)
            input[i]=input[i+1];
    }  
}
