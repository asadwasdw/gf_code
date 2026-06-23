#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>adj(N);

int ask(int a, int b) {
    int ans;
    cout << "? " << a << " " << b << endl;
    cin >> ans;
    return ans;
}


void solve()
{
    int n;
    cin >> n;
    vector<int>p(n, 0);
    vector<int>fa,fa2;
    p[1] = 0;
    int i;
    for(i = 2; i < n; i ++) {
        if(ask(1, i) == 0) {
            p[i] = 1;
            fa.push_back(i);
            i ++;
            break;
        } 
        p[i] = 0;
        fa.push_back(i);
    }
    int j = 0;
    for(; i < n ; i ++) {
        while(j < (int)fa.size() && ask(fa[j], i) == 1) {
            j ++;
        }
        if(j >= (int)fa.size()) {
            swap(fa, fa2);
            fa2.clear();
            i --;
            j = 0;
        } else {
            p[i] = fa[j]; 
            fa2.push_back(i);
            j ++;
        }
    }

    cout << "! ";
    for(int i = 1; i < n; i ++) cout << p[i] << " "; cout << endl; 
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
}