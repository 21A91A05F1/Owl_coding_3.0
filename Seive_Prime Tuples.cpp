// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int N=1e6+1;
vector<int>primes(N,1);
void generate_primes()
{
    primes[0]=0;
    primes[1]=0;
    for(int i=2;i*i<=N;i++)
    {
        if(primes[i]==1)
        {
            for(int j=i*i;j<N;j+=i)
            {
                primes[j]=0;
            }
        }
    }
}
int main() {
   int n;
   cin>>n;
   int c=0;
   generate_primes();
   for(int i=n;i>=0;i--)
   {
       if(primes[i]==1)
       {
           if(primes[i-2]==1)
           {
               c+=1;
           }
       }
   }
   cout<<c<<" ";
    return 0;
}
