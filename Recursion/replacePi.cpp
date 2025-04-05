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
void solution(char input[],int length)
{
    if(length<=1)
        return;
      solution(input+1,length-1);
    if(input[0]=='p' && input[1]=='i')
    {
        length=len(input);
        int i;
        for( i=length;i>=2;i--)
        {
           input[i+2]= input[i];
        }
     
       input[0]='3';
        input[1]='.';
        input[2]='1';
        input[3]='4';
       // length+=2;
    }
    
}
void replacePi(char input[]) {
	// Write your code here
    int count=0;
    for(int i=0;input[i]!='\0';i++)
    {
        count++;
    } 
    solution(input,count);

}


