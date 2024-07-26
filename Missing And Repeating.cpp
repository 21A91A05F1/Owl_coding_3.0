class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int k) {
        // code here
        /*
            s-sn->x-y sum of array elements - sum of first n natural numbers
            s2-sn2->x+y sum of squares array elements - sum of squares of first n natural numbers ->x+y
        */
        long long n=k;
        long long sn=(n*(n+1))/2;
        long long sn2=((n)*(n+1)*(2*n+1))/6;
        long long s=0,s2=0;
        for(int i=0;i<n;i++)
        {
            s+=arr[i];
            s2+=(long long)arr[i]*(long long)arr[i];
        }
        long long val1=s-sn;
        long long val2=s2-sn2;
        val2=val2/val1;
        long long x=(val1+val2)/2;
        long long y=x-val1;
        return {(int)x,(int)y};
    }
};
