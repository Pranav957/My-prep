<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<SWAP ALTERNATE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  void swapAlternate (int *arr, int size)
{
  //Write your code here
  int i = 0, j = 1;
  while (j<size)
    {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i = i + 2;
      j = j + 2;
      
    }
  
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<UNIQUE IN ARRAY<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  int findUnique(int *arr, int size)
{
    //Write your code here
     for(int i=0;i<size;i++)
     {
         bool a=false;
         for(int j=0;j<size;j++)
         {
             if(i==j)
                 continue;
             else if(arr[i]==arr[j])
                  a=true;
         } 
         if(a==false)
             return arr[i];
     } 
} 
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<DUPLICATES INARRAY<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
int duplicateNumber(int *arr, int size)
{
    //Write your code here
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(i==j)
                continue;
            if(arr[i]==arr[j])
                 return arr[i];
        }   
    }   
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ARRAY INTERSECTION<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  void intersection(int *input1, int *input2, int size1, int size2)
{
    //Write your code here
    for(int i=0;i<size1;i++)
    {
        for(int j=0;j<size2;j++)
        {
            if(input1[i]==input2[j])
            {
                cout<<input1[i]<<" ";
                input2[j]=0;
                break;
            }    
        }   
    }   
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<PAIR SUM<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  int pairSum(int *input, int size, int x)
{
	//Write your code here
    int count=0;
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            
            if(input[i]+input[j]==x)
            {
               // cout<<input[i]<<"  "<<input[j]<<endl;
                count++;
            }    
        }  
    }
    return count;
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<TRIPLET SUM<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  int tripletSum(int *input, int size, int x)
{
	//Write your code here
    int count=0;
    for(int i=0;i<size;i++)    //<=size-3
    {
        for(int j=i+1;j<size;j++)   //<=size-2
        {
            for(int k=j+1;k<size;k++)   //<=size-1
            {
                if(input[i]+input[j]+input[k]==x)
               {
               // cout<<input[i]<<"  "<<input[j]<<endl;
                count++;
              } 
          }
        }  
    }
    return count;
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<SORT ALL ZEROS AND ONCE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  void sortZeroesAndOne(int input[], int size)
{
    //Write your code here
    int placeZeoroHere=0;
    for(int i=0;i<size;i++)
    {
        if(input[i]==0)
        {
            int temp=input[i];
            input[i]=input[placeZeoroHere];
            input[placeZeoroHere]=temp;
            placeZeoroHere++;
        }
    }
}  Approach2: keep count of zeros and then fill those many zeros and rest 1
  void sortZeroesAndOne(int *input, int size)
{
    //Write your code here
    int i=0,k=0;
    while(i<size)
    {
        if(input[i]==0 && k<i)
        {
            int temp=input[i];
            input[i]=input[k];
            input[k]=temp;
            i++;
            k++;
        }
        else if(input[i]!=0)
            i++;
        else
        {
            i++;
            k++;
        }
    }
}
