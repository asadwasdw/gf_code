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


bool cmp(int a,int b)
{
    return a>b;
}

void solve()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        edg[a].push_back(b);
    }

    int ans = 0;
    int mx1=0;
    int mx2=0;
    for(int i=1;i<=n;i++){
        sort(edg[i].begin(),edg[i].end(),cmp);
        if(edg[i].size()>=2){
            ans=max(ans,edg[i][0]+edg[i][1]/2);
        }
        if(edg[i].size()){
            int t = edg[i][0];
            if(t>=mx1){
                mx2=mx1;
                mx1=t;
            }
            else if(t>=mx2){
                mx2=t;
            }
        }
    }

    ans=max(ans,mx1+mx2);
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