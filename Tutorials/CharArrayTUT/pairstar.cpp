// Change in the given string itself. So no need to return or print the changed string.
int getLength(char input[])
{
    if(input[0]=='\0')
      return 0;

      return 1+getLength(input+1);
}
void pairStar(char input[]) {
    // Write your code here
    if(input[1]=='\0')
      return ;

      pairStar(input+1);
    if(input[0]==input[1])
     {
        int length=getLength(input);
        for(int i=length;i>=1;i--)
          input[i+1]=input[i];
           input[1]='*';
     }
    return;

}
