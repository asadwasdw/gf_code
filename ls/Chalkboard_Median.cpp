#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);


void solve()
{
    int x;
    cin >> x;
    int q;
    cin >> q;
    multiset<int> s1, s2;

    s1.insert(x);
    for(int i = 1; i <= q; i ++) {
        int x, y;
        cin >> x >> y;
        s1.insert(x);
        s1.insert(y);

        s2.insert(*s1.rbegin());
        s1.erase(--s1.end());

        while(*s1.rbegin() > *s2.begin()) {
            auto t1 = s1.rbegin();
            auto t2 = s2.begin();

            
            int tt1 = *t1, tt2 = *t2;
            // cout << tt1 << " " << tt2 << endl;

            s1.erase(--s1.end());
            s2.erase(t2);

            s1.insert(tt2);
            s2.insert(tt1);
        } 

        cout << *s1.rbegin() << endl;
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
    return 0;
}