#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);


void solve()
{
    int M,D,y,m,d;
    cin>>M>>D>>y>>m>>d;
    d++;
    if(d==D+1){
        d=1;
        m++;
    }
    if(m==M+1){
        m=1;
        y++;
    }
    cout<<y<<" "<<m<<" "<<d<<endl;
    






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