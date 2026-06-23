#include<iostream>
#include<algorithm>
#include<map>

using namespace std;
const int N=2e5+10;
int a[N];

bool cmp(int a,int b)
{
    return a>b;
}

void solve()
{
    int n;cin>>n;
    map<int,int>mp;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

        mp[a[i]]++;
        if(mp[a[i]]<=2)ans++;
    }

    cout<<(ans+1)/2<<endl;



}


int main()
{
    int t;cin>>t;while(t--)
    solve();
}