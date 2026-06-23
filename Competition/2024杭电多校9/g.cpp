#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N = 2e6 + 10;
typedef pair<int, int> PII;

int n;

void solve(){
    cin >> n;
    vector<int> cnt(n+1);
    int c1 = 0, c2 = 0;
    for(int i=1; i<=n; ++i){
        int x;cin >> x;
        if(++cnt[x] >= 2)++c1;
    }
    fill(cnt.begin(), cnt.end(), 0);
    for(int i=1; i<=n; ++i){
        int x;cin >> x;
        if(++cnt[x] >= 2)++c2;
    }
    if(c1 == 0){
        cout << "sha7dow" << endl;
    }
    else {
        cout << "shuishui" << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}