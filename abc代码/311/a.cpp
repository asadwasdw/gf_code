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
    int n;cin>>n;
    string s;
    cin>>s;
    set<char>st;

    for(int i=0;i<s.size();i++)
    {
        st.insert(s[i]);
        //cout<<s[i]<<endl;
        if(st.size()==3){
            cout<<i+1;
            break;
        }
    }








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