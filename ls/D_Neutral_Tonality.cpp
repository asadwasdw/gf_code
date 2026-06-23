#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int a[N],a2[N];
int b[N];

bool cmp(int a,int b)
{
    return a>b;
}
vector<int>lsh;


void solve()
{
    int n,m;
    cin>>n>>m;
     int mn = INF;
     b[0]=INF;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mn=min(a[i],mn);
        b[i] = mn;
    }
    b[n+1]=0;

 //   for(int i=1;i<=m;i++)cin>>a2[i];
   // for(int i=0;i<=n+1;i++)cout<<b[i]<<" ";cout<<endl;

    for(int i=1;i<=m;i++){
        int x;cin>>x;
        int l =0,r= n+1;
        while(l<r){
            int mid = (l+r+1)>>1;
            if(b[mid]>=x)l=mid;
            else r=mid-1;
        }
        //cout<<l<<endl;

        edg[l].push_back(x);
    }
    sort(edg[0].begin(),edg[0].end(),cmp);for(auto t :edg[0])cout<<t<<" ";
    for(int i=1;i<=n;i++){
          cout<<a[i]<<" ";
        sort(edg[i].begin(),edg[i].end(),cmp);for(auto t :edg[i])cout<<t<<" ";
       
    }
 sort(edg[n+1].begin(),edg[n+1].end(),cmp);for(auto t :edg[n+1])cout<<t<<" ";
    
   cout<<endl;

   for(int i=0;i<n+2;i++)edg[i].clear();








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