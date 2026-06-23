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
    vector<int>sa,sb;
    int n,k;
    cin>>n>>k;
    sb.push_back(0);
    sa.push_back(0);

    for(int i=1;i<=n;i++){
        char t;cin>>t;
        if(t == 'A'){
            sa.push_back(i);
        }
        else sb.push_back(i);
    }
    if(k==sb.size()-1){
        cout<<"0\n";
    }
    else if(k>sb.size()-1){
         cout<<"1\n";
        cout<<sa[k-sb.size()+1]<<" B\n";
    }
    else cout<<"1\n"<<sb[sb.size()-1-k]<<" A\n";







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