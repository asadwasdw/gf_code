#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

unordered_map<int,int>st;
unordered_map<int,int>ed;

void solve()
{
    int n;
    cin>>n;
    int last = -1;
    int s = -1;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        if(last == -1) {
            s = x;
            last = x;
        }
        else {

            ed[last] = x;
            st[x] = last;
            last = x;

        }
    }



    int q;
    cin>>q;
    while(q--) {
        int op,x,y;
        cin>>op>>x;
        if(op == 1) {
            cin >> y;
            ed[y] = ed[x];
            st[ed[y]] = y;
            ed[x] = y;
            st[y] =x;
        }
        else {
            if(st[x] == 0) {
                s = ed[x];
            }
            y = ed[x];
            ed[st[x]] = y;
            st[y] = st[x];
            st[x] = ed[x] = 0;
        }
    }


    while(1){
        cout<<s<<" ";
        s = ed[s];
        if(s==0)break;
    }

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}