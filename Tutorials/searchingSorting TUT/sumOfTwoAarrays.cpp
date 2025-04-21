void sumOfTwoArrays(int *input1, int size1, int *input2, int size2, int *output)
{
    //Write your code here
    int idx1=size1-1,idx2=size2-1,carry=0;
    int idx3=max(size1,size2);

    while(idx1>=0 && idx2>=0)
    {
        int sum=input1[idx1]+input2[idx2]+carry;
        int unit=sum%10 ,ten=sum/10;

        output[idx3]=unit;
        carry=ten;
        idx1--;idx2--;idx3--;
    }
    while(idx1>=0)
    {
        int sum=input1[idx1]+carry;
        int unit=sum%10,ten=sum/10;

        output[idx3]=unit;
        carry=ten;
        idx1--;
        idx3--;
    }
     while(idx2>=0)
    {
        int sum=input2[idx2]+carry;
        int unit=sum%10,ten=sum/10;

        output[idx3]=unit;
        carry=ten;
        idx2--;
        idx3--;
    }
    output[0]=carry;
}
