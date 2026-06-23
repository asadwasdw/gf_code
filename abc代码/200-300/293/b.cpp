#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;

int st[N];

void solve()
{
    int n;cin>>n;

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        //cout<<x<<endl;

        if(!st[i])
        st[x]++;
    }
    int ans=0;
    vector<int>a;
    for(int i=1;i<=n;i++)
    {
        if(st[i]==0)
        {
            ans++;
            a.push_back(i);
        }
    }
    cout<<ans<<endl;

    for(auto b:a)
    {
        cout<<b<<" ";
    }




}


signed main()
{
    ios::sync_with_stdio(false);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}