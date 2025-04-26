// Change in the given string itself. So no need to return or print the changed string.
int len(char input[])
{
    int count=0;
    for(int i=0;input[i]!='\0';i++)
    {
        count++;
    } 
    return count;
}
void pairStar(char input[]) {
    // Write your code here
    if(input[0]=='\0')
        return;
    pairStar(input+1);
    if(input[0]==input[1])
    {
        for(int i=len(input);i>=1;i--)
        {
            input[i+1]=input[i];
        }
        input[1]='*';
    }    
}
