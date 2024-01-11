#include<bits/stdc++.h>
using namespace std;
void generateseive(vector<int>&seive)
{
    seive[0]=0;
    seive[1]=0;
    for(int i=2;i*i<=1e6+1;i++)
    {
        if(seive[i]==1)
        {
            for(int j=i*i;j<1e6+1;j+=i)
            {
                seive[j]=0;
            }
        }
    }
}
int main()
{
    int l,r;
    cin>>l>>r;
    vector<int>seive(1e6+1,1);
    generateseive(seive);
    int q=(int)sqrt(r);
    vector<int>primes;
    for(int i=2;i<=q;i++)
    {
        if(seive[i]==1)
        {
            primes.push_back(i);
        }
    }
    vector<int>dummyarray(1000,1);
    for(int i=0;i<primes.size();i++)
    {
        int q=l/primes[i];
        int w=q*primes[i];
        if(w<l)
        {
            w=w+primes[i];
        }
        int ind=w-l;
        
        //cout<<ind<<" ";
        int u=primes[i];
        
        for(int i=ind;i<1000;i+=u)
        {
            dummyarray[i]=0;
        }
    }
    for(int i=0;i<r;i++)
    {
        cout<<dummyarray[i]<<" ";
    }
}
