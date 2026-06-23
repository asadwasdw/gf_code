#include<iostream>
#include<algorithm>

using namespace std;

const int N=1e5+10;
int a[N];



int solve()
{
    int n;cin>>n;
    long long sum=0;
    int mx=0;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        mx=max(a[i],mx);
    }

    if(mx==0)return 0;
    if(mx<=sum-mx)return 1;
    
    return mx-(sum-mx);


}

int main()
{
    int t;cin>>t;while(t--)
    cout<<solve()<<endl;
}