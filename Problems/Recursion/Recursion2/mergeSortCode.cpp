/*void merge(int array[], int const left, int const mid,
           int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
 
    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne
        = 0, // Initial index of first sub-array
        indexOfSubArrayTwo
        = 0; // Initial index of second sub-array
    int indexOfMergedArray
        = left; // Initial index of merged array
 
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
 
// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
/*void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively
 
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
void mergeSort(int input[], int size){
	// Write your code here
    mergeSort(input,0,size-1);
}
*/
#incude<iostream>
void merge(int input[],int si,int ei,int mid)
{
    //Write your code here
    //int sum=size1+size2;
    int size1=mid-si+1;
    int size2=ei-mid;
    int i,j,x;
    int *ans=new int[(ei-si)+1];
    int *input2=input+mid;
    //input2=input2+(mid+1)
    i=x=j=0;
    while(i<size1 && j<size2)
    {
        if(input[i]<input2[j])
        {
            ans[x]=input[i];
            i++;x++; 
        }
        else
        {
           ans[x]=input2[j];
            j++;x++; 
        }
    } 
    while(i<size1)
    {
       ans[x]=input[i];
            i++;x++;  
    }   
    while(j<size2)
    {
       ans[x]=input2[j];
            j++;x++;  
    }
    int k=0;
    for(int i=0;i<(ei-si)+1;i++)
    {
        cout<<ans[i];
    }
    for(int i=si;i<=ei;i++)
    {
        input[i]=ans[k];
        k++;
    }
}
void mergeSort(int input[],int si,int ei){
	// Write your code here
      if(si>=ei)
        return;
    int mid=(si+ei)/2;
    mergeSort(input,si,mid);
    mergeSort(input,mid+1,ei);
    merge(input,si,ei,mid);
}
void mergeSort(int input[], int size){
	// Write your code here
    mergeSort(input,0,size-1);
}
/*void merge(int input[],int si,int ei,int mid)
{
    //Write your code here
    //int sum=size1+size2;
    int size=ei-si;
    int *ans=new int[size+1];
    if(size%2==0)
       arr=input+size/2;
    else
        arr=input+size/2+1;
    int i,j,x;
    i=j=x=0;
    while(i<mid && j<ei)
    {
        if(input[i]<input[j])
        {
            ans[x]=arr[i];
            i++;x++; 
        }
        else
        {
           ans[x]=arr[j];
            j++;x++; 
        }
    } 
    while(i<mid)
    {
       ans[x]=input[i];
            i++;x++;  
    }   
    while(j<ei)
    {
       ans[x]=arr[j];
            j++;x++;  
    }
    for(int i=0;i<)
    
}*/