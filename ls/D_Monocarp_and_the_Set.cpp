#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

string s;
ll ans = 1;

ll qmi(ll a,ll b){
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a %mod;
        a =  a * a %mod;
        b >>= 1;
    }
    return res%mod;
}
void print(){
    if(s[0]=='?')cout<<"0";
    else cout<<ans;
    cout<<endl;
}

void solve()
{
    int n,q;cin>>n>>q;
    cin>>s;

    for(int i = 1; i < n; i++) {
        if(s[i] == '?') {
            ans = ans * i %mod; 
        }
    }
    print();

    while(q--) {
        int t1;
        char t2;
        cin>>t1>>t2;
        t1--;
        if(t2 =='?' && s[t1] == '?'){}
        else if(t2 != '?' && s[t1] != '?'){}
        else if(t2 != '?') {
            if(t1)ans*=qmi(t1,mod-2);
        }
        else {
            if(t1)ans*=t1;
        }
        s[t1] = t2;
        ans%=mod;
        print();
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