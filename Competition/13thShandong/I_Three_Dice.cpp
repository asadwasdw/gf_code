#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

map<PII,bool>st;

void dfs(int x,int a,int b)
{

    if(x==3)
    {
        st[{a,b}]=true;
        return;
    }

    for(int i=1;i<=6;i++)
    {
        if(i==1||i==4){
             dfs(x+1,a+i,b);
        }
        else{
            dfs(x+1,a,b+i);
        }
    }


}


void solve()
{

    dfs(0,0,0);
    int a,b;
    cin>>a>>b;
    if(st[{a,b}])cout<<"Yes";
    else cout<<"No";







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