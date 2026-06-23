#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=16;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<PII>edg;
vector<bool>st(N);

set<int>S[N];

int sg(vector<bool>st,vector<PII>edg,int n) {
    if(n==1)return 0;
    int num = 0;
    set<int>s;
    for(int i=1;i<=10;i++) {
        if(st[i]==true) {
            vector<bool>st2(N);
            for(int i=1;i<=10;i++) {
                st2[i]=st[i];
            }
            st2[i]=false;
            vector<PII>edg2;
            for(auto t:edg) {
                if(t.first == i || t.second == i) continue;
                edg2.push_back(t);
            }
            int t = sg(st2,edg2,n-1);
            if(!t)num++;
            s.insert(sg(st2,edg2,n-1));
        }
    }


    for(auto t:edg) {

        vector<PII>edg2;
        for(auto T:edg) {
            if(t==T)continue;
            edg2.push_back(T);
        }
        int t1 = sg(st,edg2,n);
        if(!t1)num++;
        s.insert(sg(st,edg2,n));
    }

    int res = 0;
    while(s.count(res))res++;
    return res;
}

void solve()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++) st[i]=true;
    for(int i=1;i<=m;i++) {
        int x,y;
        cin>>x>>y;
        edg.push_back({x,y});
    }

    cout<<sg(st,edg,n)<<endl;



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