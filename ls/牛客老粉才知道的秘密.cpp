#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

unordered_map<int,int>st;
vector<int>lsh;

int find(int x)
{
    return lower_bound(lsh.begin(),lsh.end(),x)-lsh.begin()+1;
}

void solve()
{
    st.clear();
    lsh.push_back(0);
    lsh.push_back(1);
    lsh.push_back(-1);
    lsh.push_back(-INF);
    lsh.push_back(INF);

    int n;  
    cin>>n;
    int t = 3;
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v;


        lsh.push_back(v);
        lsh.push_back(v-1);
        lsh.push_back(v+1);

        if(v==0){
            t--;
        }
        else if(abs(v)==1&&u==1){
            t--;
        }
    }
    sort(lsh.begin(),lsh.end());
    lsh.erase(unique(lsh.begin(),lsh.end()),lsh.end());

    for(auto t:lsh)cout<<t<<" ";cout<<endl;
    for(auto t:lsh)cout<<find(t)<<" ";



}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    // cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}