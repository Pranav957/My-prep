void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    // Write your code here
    if(n==0)
     return;

     towerOfHanoi(n-1,source,destination,auxiliary);
     cout<<source<<" "<<destination<<endl;
     towerOfHanoi(n-1,auxiliary,source,destination);
}

move n-1(2) disks from source to auxillary using Destination
move largest disk from source to destination using auxilry
move (n-1) 2 disks from auxilary to destination using source
