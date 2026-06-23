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
    string s;ll pos;
    cin>>s>>pos;

    list<char>l(s.begin(),s.end());
    auto it = l.begin();
    int n = s.size();

    for(int i = n;i >= 1; i--) {
        if(pos <= i) {
            auto it = l.begin();
            for(int j = 1;j < pos; j++)it++;
            cout<<*it;
            return;
        }
        bool flag = true;
         while(it != (--l.end())) {
            auto nxt = it;nxt++;
            if(*it > *nxt) {

                l.erase(it);
				if(nxt == l.begin()) it = nxt;
				else it = --nxt;
                flag = false;
                break;
            }
            it++;
        }

        if(flag)l.erase(it--);
        pos -= i;
    }
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        solve();
    }
}