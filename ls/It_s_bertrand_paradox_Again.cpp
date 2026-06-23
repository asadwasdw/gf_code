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
    int n;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int z = min({a+100,100-a,b+100,100-b});
       
        if(z<=1)
        {
            cnt++;
        }
    }
    if(cnt>=10) {
        cout<<"bit-noob";
    }
    else  cout<<"buaa-noob";
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