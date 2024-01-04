#include<iostream>
using namespace std;
int main()
{
	int x,y;
	cin>>x>>y;
	//swapping of two numbers.
	x^=y;
	y=x^y;
	x^=y;
	cout<<x<<" "<<y<<endl;
}
