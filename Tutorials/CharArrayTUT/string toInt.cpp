// int stringToNumber(char input[],int length) {
//     // Write your code here
//     if(length==1)
//     {
//         return input[0]-'0';
//     }
     
//      int res=stringToNumber(input+1,length-1);
//      int curr=input[0]-'0';
//     return curr * pow(10, length - 1) + res;
// }

int stringToNumber(char input[],int length) {
    // Write your code here
    if(length==1)
    {
        return input[length-1]-'0';
    }
     
     int res=stringToNumber(input,length-1);
     int curr=input[length-1]-'0';
    return res*10+curr;
}


int stringToNumber(char input[]) {
    int length = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        length++;
    }
    return stringToNumber(input, length); 
}
