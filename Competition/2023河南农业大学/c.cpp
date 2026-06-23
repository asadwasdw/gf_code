#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


int n,m;

void solve()
{
    cin>>n>>m;

    int cnt1=0,cnt=0,cnt0=0;

    for(int i=1;i<=n;i++){
        char t;
        cin>>t;
        if(t=='0')cnt0++;
        else cnt1++;
    }

    cnt = min(cnt1,cnt0);

    if(cnt==0){
        cout<<"Bob"<<endl;
        return ;
    }

    if(cnt==m)cout<<"Alice"<<endl;
    else if(n==4&&cnt==2&&m==1)cout<<"Bob"<<endl;
    else cout<<":("<<endl;

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