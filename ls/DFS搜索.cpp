#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

map<char,int>st;


void solve()
{
    int a[10]={0};

    int n;cin>>n;
    for(int i=1;i<=n;i++){
        char t;
        cin>>t;
        if(st[t]) {
            if(st[t]%3==1) {
                a[st[t]]=1;
            }
            else if(a[st[t]-1]) {
                a[st[t]]=1;
            }
        }
    }
    cout<<a[3]<<" "<<a[6]<<endl;


}


signed main()
{
    st['D']=1;
    st['F']=2;
    st['S']=3;
    st['d']=4;
    st['f']=5;
    st['s']=6;

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}