#include<bits/stdc++.h>
using namespace std;
int count_set_bits(int n)
{
    int c=0,mask=1;
    while(c<=mask)
    {
      //if n&mask is >0 then it indicates , that particular contains a set bit , in a particular position.
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
        int n,res=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            res+=count_set_bits(i);
        }
        cout<<res<<endl;
    }
}
