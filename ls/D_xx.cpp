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

string calc(string s) {
    vector<char> v;
    for(auto t : s) {
        v.push_back(t);

        if(v.size() >= 4) {
            int n = v.size() - 1;
            if(v[n - 3] == '(' && v[n - 2] == 'x' && v[n - 1] == 'x' && v[n] == ')') {
                for(int i = 1; i <= 4; i ++) v.pop_back();
                v.push_back('x');
                v.push_back('x');
            }
        }
    }
    string res;
    for(auto t : v) res += t;
    return res;
}

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    s1 = calc(s1);
    s2 = calc(s2);

    if(s1 == s2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
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