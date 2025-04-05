int firstIndex(int input[], int size, int x) {
    /* Don't write main().
       Don't read input, it is passed as function argument.
       Return output and don't print it.
       Taking input and printing output is handled automatically.
    *///static int i=0;
      if(size==0)
          return -1;
      if(input[0]==x)
          return 0;
      int indx=firstIndex(input+1,size-1,x);
      if(indx>=0)
          return 1+indx;
      else 
          return indx;
  
  }
  /*int firstIndex(int input[], int size, int x) {
    
    static int i=0;
      if(size==0)
          return -1;
      if(input[i]==x)
          return i;
          i++;
      return firstIndex(input,size-1,x);
  
  }
  int firstIndex(int input[], int size, int x) {
    
    static int i=0;
      if(i==size)
          return -1;
      if(input[i]==x)
          return i;
          i++;
         
      return firstIndex(input,size,x);
  }*/