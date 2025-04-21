bool checkPalindrome(char str[]) {
    // Write your code here
    int i=0,x=0;
    while(str[x]!='\0')   //strlen(str)
        x++;
    x=x-1;

    while(i<x)
    {
        if(str[i]!=str[x])
           return false;
        x--;
        i++;   
    }    
    return true;
}
