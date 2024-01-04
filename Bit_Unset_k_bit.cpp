//un_set kth bit
/*
Approach: 
 

Since bitwise AND of any bit with a reset bit results in a reset bit, i.e.
Any bit <bitwise AND> Reset bit = Reset bit

which means,
0 & 0 = 0
1 & 0 = 0
So for clearing a bit, performing a bitwise AND of the number with a reset bit is the best idea.
n = n & ~(1 << k)
OR
n &= ~(1 << k)

where k is the bit that is to be cleared
Input :
5 3
101 
we will change the bit at 3rd position.
*/
#include<bits/stdc++.h>
using namespace std;
int unset_k_bit(int n,int k)
{
    n&=~(1<<(k-1));
    return n;
}
int main()
{
    int n,k;
    cin>>n>>k;
    cout<<unset_k_bit(n,k);
}
