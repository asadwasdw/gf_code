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
    string s;
    cin >> s;
    typedef pair<char,int> pci;
    map<char,int> cnt;
    for(auto t : s) cnt[t] ++;
    vector<pci> v;
    for(char i = 'a'; i <= 'z'; i ++) {
        if(cnt[i] > 0) {
            v.push_back({i, cnt[i]});
        }
    }

    string ans;
    while(ans.size() < s.size()) {
        sort(v.begin(), v.end(),[&](pci a, pci b){
            if(a.second != b.second) return a.second > b.second;
            return a.first < b.first;
        });

        bool ky = false;

        for(int i = 0; i < v.size(); i ++) {
            if(v[i].second && v[i].first != ans[ans.size() - 1]) {
                v[i].second --;
                ans += v[i].first;
                ky = true;
                break;
            }
        }
        if(!ky) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n" << ans << "\n";
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
    return 0;
}