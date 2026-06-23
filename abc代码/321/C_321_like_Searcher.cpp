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


void solve()
{
    vector<int>ans;
    for(int i=1;i<=9;i++){
        edg[i].push_back(i);
        ans.push_back(i);
    }
   
    for(int i = 8 ;i>=0;i--){
        for(int k=9;k>i;k--){

            for(auto t:edg[k]){
                int T = t*10+i;
                edg[i].push_back(T);
                ans.push_back(T);
            }
        }
    } 

    sort(ans.begin(),ans.end());
    int k;cin>>k;
    cout<<ans[k-1]<<endl;
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