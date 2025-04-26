int staircase(int n){
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    if(n<=0)
    {
        if(n==0)
            return 1;
        else
            return 0;
    }
    int a=0,b,c;
   /*& a=staircase(n-1);
    b=staircase(n-2);
    c=staircase(n-3);
    return a+b+c;
    */
    for(int i=1;i<4;i++)
    {
        a=a+staircase(n-i);
    }
    return a;
}