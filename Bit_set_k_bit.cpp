/*
To set any bit we use bitwise OR | operator. As we already know bitwise OR | operator 
evaluates each bit of the result to 1 if any of the operand’s corresponding bit is set (1). 
In-order to set kth bit of a number we need to shift 1 k times to its left 
and then perform bitwise OR operation with the number and result of left shift performed just before. 
*/
#include<bits/stdc++.h>
using namespace std;
int set_k_bit(int n,int k)
{
    return (1<<k)| n;
}
int main()
{
    int n,k;
    cin>>n>>k;
    cout<<set_k_bit(n,k)<<endl;
}
