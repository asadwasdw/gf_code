#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

unordered_map<int,vector<int>>c;

bool cmp(int a,int b)
{
    return a>b;
}

void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        c[x-i].push_back(x);
    }
    int ans = 0;

    for(auto t:c)
    {
        sort(t.second.begin(),t.second.end(),cmp);
        int res = 0;

        for(auto T:t.second)
        {
            if(res==0)res = T;
            else {
                res +=T;
                if(res>0)ans+=res;
                res=0;
            }
        }

        // cout<<t.first<<"\n";
        // for(auto T:t.second)
        // {
        //     cout<<T<<" ";
        // }cout<<endl;

    }
    cout<<ans<<endl;
    c.clear();




}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
   cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}