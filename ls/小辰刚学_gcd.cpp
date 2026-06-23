#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int n,m;
int a[N],ans[N];
int len;

struct q{
    int id,l,r;
}query[N];

int get(int x)
{
    return x/len;
}

bool cmp(q a,q b)
{
    if(get(a.r)==get(b.r))return a.l<b.l;
    return get(a.l)<get(b.l);
}


int a[N];
void solve()
{
    
    int n,m;
    cin>>n>>m;
    len = max((int)sqrt(n),1);

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }


    for(int i=1;i<=m;i++){
        int l,r;cin>>l>>r;
        query[i] = {i,l,r};
    }

    sort(query+1,query+1+m,cmp);







    // while(m--){
    //     int l,r;cin>>l>>r;
    //     int t = 0;
    //     set<int>s;
    //     while(r>=l){
    //         if(!t)t=a[r];
    //         else t=__gcd(t,a[r]);
    //         r--;
    //         s.insert(t);
    //     }
    //     cout<<s.size()<<endl;
    // }
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