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
int b[N];
const int M=32*N;

int idx;
int son[M][2];


void add(int x)
{
     int p = 0;
    for (int i = 30; i >= 0; i -- )
    {
        int &s = son[p][x >> i & 1];
        if (!s) s = ++ idx;
        p = s;
    }
}


int search(int x)
{
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i -- )
    {
        int s = x >> i & 1;
        if (son[p][!s])
        {
            res += 1 << i;
            p = son[p][!s];
        }
        else p = son[p][s];
    }
    return res;
}


void solve()
{
    int n;
    cin>>n;
    int mx = 0;
    add(0);
    for(int i=2;i<=n;i++){
        cin>>a[i];
        a[i]^=a[i-1];
        mx=max(a[i],mx);
        add(a[i]);
        //cout<<a[i]<<" ";
    }
   // cout<<endl;

    for(int i=0;i<n;i++)
    {
        if(search(i)==n-1){
            b[1]=i;
            break;
        }
    }
    for(int i=2;i<=n;i++){
        b[i]=a[i]^b[1];
    }
    for(int i=1;i<=n;i++)cout<<b[i]<<" ";cout<<endl;
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