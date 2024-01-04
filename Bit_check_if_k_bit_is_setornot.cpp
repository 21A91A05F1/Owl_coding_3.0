//check if ith bit is set or not.
#include<iostream>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int mask=1<<(k-1);
	if((n&mask)>0) cout<<"yes kth bit is set.";
	else cout<<"no kth bit is not set";
}
