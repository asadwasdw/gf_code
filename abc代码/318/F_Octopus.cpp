#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int x[N];
int l[N];


PII check(PII a,PII b)
{
    PII t = {max(a.first,b.first),min(a.second,b.second)};
    return t;
}

bool cmp(int a,int b)
{
    return a>b;
}

void cs(PII a)
{
    cout<<a.first<<" "<<a.second<<endl;
}


void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }

    for(int i=1;i<=n;i++)cin>>l[i];

    PII t = {-INF,INF};

    for(int i=1;i<=n;i++)
    {
        PII t1 = {x[i]-l[i],x[i]+l[i]};
        cs(t1);
        t=check(t,t1);
        cs(t);
    }

    sort(x+1,x+n+1,cmp);
    int ans =  (t.second-t.first+1);
    t= {-INF,INF};
    for(int i=1;i<=n;i++)
    {
        PII t1 = {x[i]-l[i],x[i]+l[i]};
        cs(t1);
        t=check(t,t1);
        cs(t);
    }
    ans +=  (t.second-t.first+1);
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