#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

unordered_map<int,int>st;
PII a[N];
void solve()
{
    st.clear();
    int l =2, r= 2;
    int n;
    cin>>n;
    int t = 3;

    for(int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v;
        st[v]|=u;
        a[i]={u,v};
    }

    for(int i=1;i<=n;i++) {
        int u = a[i].first;
        int v = a[i].second;

        if(v==0){
            t--;
        }
        else if(abs(v)==1&&u==1){
            t--;
        }

        if(v<=0){
            l=min(l,1ll);
        }
        if(v>=0)r=min(r,1ll);

        if( (st[v]|st[v+1]|st[v-1]) == 3 ){
            
            if(v<0){
                l=0;
            }
            if(v>0)r=0;
        }
    }
    // cout<<t<<endl;

    cout<<min(l+r,t)<<endl;

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