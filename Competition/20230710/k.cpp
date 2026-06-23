#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


void solve()
{
    string s;
    int n;
    cin>>n;
    int cnt =0;

    for(int i=1;i<=n+1;i++)
    {
        getline(cin,s);

        for(auto t:s)
        {
            if(t=='-')cnt++;
        }
        //cout<<s<<endl;
      //  cout<<cnt<<endl;
    }

    cout<<cnt<<endl;

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