#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;
#define int long long 
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
unordered_map<int,int>st;


void solve()
{
    int n,b;
    cin>>n>>b;
    bool ky=false;

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(st[x-b]||st[x+b])ky=true;
        st[x]++;
    }

    if(ky||(b==0&&n>=1))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;



}


signed main()
{
    ios::sync_with_stdio(false);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}