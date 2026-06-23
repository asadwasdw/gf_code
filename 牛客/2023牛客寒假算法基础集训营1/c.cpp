#include<iostream>
#include<algorithm>

using namespace std;

void solve()
{
    int n;
    cin>>n;
    int t=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x)t++;
    }
    cout<<t<<endl;
}

int main()
{
    int t;cin>>t;while(t--)
    solve();
}