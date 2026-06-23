#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int>PII;
const int N=5e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

int w[N];
int a[N],b[N],c[N];

bool cmp(int a,int b)
{
    return a<b;
}

unordered_map<int,int>st;

void solve()
{
    int n,C;
    cin>>n>>C;

    vector<int>lsh;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];

        lsh.push_back(a[i]);
        lsh.push_back(b[i]);

        lsh.push_back(a[i]-1);
        lsh.push_back(b[i]-1);

        lsh.push_back(a[i]+1);
        lsh.push_back(b[i]+1);
    }

    //lsh.push_back(0);

    sort(lsh.begin(),lsh.end(),cmp);
    lsh.erase(unique(lsh.begin(),lsh.end()),lsh.end());

    //for(auto t:lsh)cout<<t<<endl;

    int cnt=0;

    for(auto t: lsh){
        st[t]= cnt ++ ;
    }

    for(int i=1;i<=n;i++)
    {
        int l = st[a[i]];
        int r = st[b[i]];

        w[l]+=c[i];
        w[r+1]-=c[i];
    }

    for(int i=1;i<cnt;i++)
    {
        w[i]+=w[i-1];
       // cout<<i<<" "<<w[i]<<endl;
    }
    ll ans=0;


    for(int i=1;i<=cnt;i++)
    {
        int t =min(w[i],C);

        ans+=t*(lsh[i]-lsh[i-1]);
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