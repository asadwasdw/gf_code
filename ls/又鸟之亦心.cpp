#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int a[N];

void solve()
{
    int n;cin>>n;
    int x,y;
    cin>>x>>y;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }

    auto check = [&](int d) {
        int last = y;
        set<int>s;
        if(abs(x-y)<=d) {
            s.insert(x);
        }

        for(int i=1;i<=n;i++) {
            // cout<<i<<" ----"<<a[i] << " " <<last<<endl;

            if (!s.empty() && std::abs(a[i] - last) <= d) {
                s.insert(last);
            }
            while (!s.empty() && *s.begin() < a[i] - d) {
                s.erase(*s.begin());
            }

            while (!s.empty() && *s.rbegin() > a[i] + d) {
                s.erase(*s.rbegin());
            }
            last = a[i];
        }
        // cout<<d<<" "<<s.size()<<endl;
        
        return s.size();
    };


    int l = 0,r=1e9;
    while(l<r) {
        int mid = l+r>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;






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