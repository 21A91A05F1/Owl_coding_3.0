#include <bits/stdc++.h> 
int flipBits(int* arr, int n) 
{
    /*
        for a given binary format , 
        we should flip the bits in any range , such that there should be
        maximum number of ones in the bit format.
        we use kadane's algorithm.
        we will count the consecutive 0's in an array, to replace
        that bits to 1 .

    */
    int c=0,max_s=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1) 
        {
            arr[i]=-1;
            c++;
        }
        else
        {
            arr[i]=1;
        }

    }
    int s=0;
    for(int i=0;i<n;i++)
    {
        if(s<0) s=0;
        s+=arr[i];
        max_s=max(max_s,s);
    }
    return max_s+c;
}
