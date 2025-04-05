
int lastIndex(int input[], int size, int x) {
    if(size==0)
        return -1;
     if(input[size-1]==x)
         return size-1;
       return lastIndex(input,size-1,x);
   
   }
   /*int lastIndex(int input[], int size, int x) {
     if(size==0)
           return -1;
       
       int indx=lastIndex(input+1,size-1,x);
       if(indx==-1)
       {
       if(input[0]==x)
           return 0;
       }
       if(indx>=0)
           return 1+indx;
       else 
           return indx;
      
   }*/