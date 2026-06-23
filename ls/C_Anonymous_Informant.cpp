#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int a[N];
bool st[N];

void solve()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    int t = n;

    bool flag = true;
    while(m){
        
        if(st[t])break;
        st[t]=1;
        //cout<<a[t]<<endl;
        if(a[t]>n){
            flag = false;
            break;
        }
        t-=a[t];
        if(t<=0)t+=n;
        m--;
    }

    if(flag){
        cout<<"Yes\n";
    }
    else cout<<"No\n";
    for(int i=1;i<=n;i++)st[i]=0;

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