#include<bits/stdc++.h>
using namespace std;
int count_set_bits(int n)
{
    int c=0,mask=1;
    while(c<=mask)
    {
        if((n&mask)>0) c++;
        mask<<=1;
    }
    return c;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<count_set_bits(n)<<endl;
    }
}
