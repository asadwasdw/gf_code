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

    string s;
    cin>>s;
    stack<char>st;

    for(auto t:s){
        if(t=='C' && st.size()>=2) {
            char t1 = st.top();st.pop();
            if(t1 =='B' && st.top()=='A'){
                st.pop();
            }
            else 
            {
                st.push(t1);
                st.push(t);
            }
        }
        else st.push(t);
    }

    string ans;
    while(st.size()){
        ans+=st.top();st.pop();
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;









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