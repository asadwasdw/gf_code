#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);


int n;
int pos[N];
int a[N];
int k[N];
int b[N];
void add(int l,int r,int kk,int bb)
{
    if(l>r)return ;
    k[l]+=kk;
    b[l]+=bb;
    k[r+1]-=kk;
    b[r+1]-=bb;
}

void add(int v)
{
    if(v<n/2)
    {
        add(0,v-1,-1,v);
        add(v,v+n/2,1,-v);
        add(v+n/2+1,n-1,-1,n+v);
    }
    else 
    {
        add(0,v- n/2 -1,1,n-v);
        add(v-n/2,v-1,-1,v);
        add(v,n-1,1,-v);
    }

}

void solve()
{

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        pos[a[i]]=i;
    }

    for(int i=0;i<n;i++)
    {
        int v = (i - pos[i] + n)%n;//转v步到面前
        add(v);
    }

    for(int i = 1 ; i < n ; i ++ ) k[i] += k[i - 1], b[i] += b[i - 1];
    int ans =1e18;

    for(int i=0;i<n;i++){
        ans=min(ans,k[i]*i+b[i]);
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