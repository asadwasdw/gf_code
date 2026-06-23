#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


int a[N];
int st[N];


void solve()
{
    int ans =0;

    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        a[i]=x;
    }

    for(int i=1;i<=n;i++)
    {
        if(!st[i]){
            int cnt =0;
            int x=i;
            while(!st[x]){
                st[x]=1;
                x=a[x];
                cnt++;
            }

            ans+=cnt-1;
        }
    }

    cout<<ans<<endl;

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}