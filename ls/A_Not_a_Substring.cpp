#include<bits/stdc++.h>
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
    string s;cin>>s;
    int n = s.size();
    if(s=="()"||n==1){
        cout<<"NO\n";
        return;
    }
    s=" "+s;
    int st = 1;
    bool z = true;
    for(int i=1;i<=n;i++)
    {
        if(s[i]==')'){
            z=false;
        }
        if(s[i]=='('&&!z){
            st=2;
        }
        


    }
    cout<<"YES"<<endl;
    if(st==1){
        for(int i=1;i<=n;i++)cout<<"()";
        cout<<endl;
    }
    else {
        for(int i=1;i<=n;i++)cout<<"(";
        for(int i=1;i<=n;i++)cout<<")";
        cout<<endl;
    }
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