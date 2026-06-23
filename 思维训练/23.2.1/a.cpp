#include<iostream>
#include<algorithm>

using namespace std;

void solve()
{
    int n;
    cin>>n;
    long long sum=0;
    long long mx=0;
    for(int i=1;i<=n;i++){
        long long x;
        cin>>x;
        sum+=x;
        mx=max(mx,x);
    }
    if(mx*(n-1)>sum)cout<<mx*(n-1)-sum<<endl;
    else 
    {
        if(sum%(n-1)==0)cout<<"0"<<endl;
        else cout<<n-1-sum%(n-1)<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    solve();

}