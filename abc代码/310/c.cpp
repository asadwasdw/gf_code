#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

set<string>st;


void solve()
{
    int ans =0;
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {

        string s;
        cin>>s;
        st.insert(s);
        reverse(s.begin(),s.end());
        st.insert(s);
    }

    for(auto t:st)
    {
        string s=t;
        reverse(s.begin(),s.end());
        if(s==t)ans++;
    }

    cout<<(st.size()+ans)/2<<endl;


    

    


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