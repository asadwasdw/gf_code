#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

int c[2010][2010];


void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    string str;
    int a,s,d,w;
    cin>>str;
    {
        int mx = 0,num=0;
        for(auto t:str){
            if(t=='U')num++;
            if(t=='D')num--;
            mx=max(num,mx);
        }
        s = mx;//下边界
    }
    {
        int mx = 0,num=0;
        for(auto t:str){
            if(t=='R')num++;
            if(t=='L')num--;
            mx=max(num,mx);
        }
        a = mx;//左边界
    }
    cout<<a<<" "<<s<<endl;










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