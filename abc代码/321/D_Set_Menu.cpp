#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=4e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int a[N];
int b[N];

int tr[N][3];
int tr2[N];

void add(int x,int k)
{
    for(int i=x;i<N;i+=i&-i)tr[i][1]+=1,tr[i][2]+=k;
}

PII sum(int x)
{
    int res = 0;
    int res2 = 0;
    for(int i = x;i;i-= i&-i)res+=tr[i][1],res2+=tr[i][2];
    return {res,res2};
}

vector<int>lsh;
int find(int x)
{
    return lower_bound(lsh.begin(),lsh.end(),x)-lsh.begin();
}

void solve()
{

    int n,m,p;
    cin>>n>>m>>p;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        int t = max(p - a[i],0ll);
        lsh.push_back(t);
        lsh.push_back(a[i]);
        lsh.push_back(a[i]-1);
    }
    lsh.push_back(0);
    lsh.push_back(-1);


    for(int i=1;i<=m;i++){
        cin>>b[i];
        lsh.push_back(b[i]);
        lsh.push_back(b[i]-1);
    }


    sort(lsh.begin(),lsh.end());
    lsh.erase(unique(lsh.begin(),lsh.end()),lsh.end());

    int ans = 0;
    
    for(int i=1;i<=n;i++)
    {
        add(find(a[i]),a[i]);
        //cout<<find(a[i])<<endl;
    }


    for(int i=1;i<=m;i++){
        int t= b[i];
        int x = t;
        t = max(0ll,p - t);
        PII T1 = sum(N-1);
        PII T2 = sum(find(t));
        int num = (T1.first - T2.first);
        ans += num*p+(n-num)*x+T2.second;
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