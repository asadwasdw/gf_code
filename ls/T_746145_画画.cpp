#include<bits/stdc++.h>
#define int long long
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

int n, m, q;
int c[N], p[N];
multiset<int> s[N];
multiset<int> s1, s2; // 最大值集合， 次大值集合
long long sum = 0;

void del(int id) {
    auto it = s[id].rbegin();
    int mx1 = *it;
    it++;
    int mx2 = *(it);
    
    s1.erase(s1.find(mx1));
    s2.erase(s2.find(mx2));
}


void add(int id) {
    auto it = s[id].rbegin();
    int mx1 = *it;
    it++;
    int mx2 = *(it);

    s1.insert(mx1);
    s2.insert(mx2);
}

void print() {
    for(int i = 1; i <= m; i ++) {
        cout << i <<" : ";
        for(auto t : s[i]) cout << t << " ";
        cout << endl;
    }
    cout << "s1 : "; for(auto t : s1) cout << t << " ";cout << endl;
    cout << "s2 : "; for(auto t : s2) cout << t << " ";cout << endl;
}

void solve()
{

    cin >> n >> m >> q;
    for(int i = 1; i <= n; i ++) {
        cin >> c[i] >> p[i];    
        s[c[i]].insert(p[i]);
    }

    for(int i = 1; i <= m; i ++) {
        s[i].insert(0);
    }
    
    for(int i = 1; i <= m; i ++) {
        sum += *s[i].rbegin();
        add(i);
    }

    cout << max(sum + *s2.rbegin() - *s1.begin(), sum) << endl;

    while(q --) {
        int op, i, x;
        cin >> op >> i >> x;
        if(op == 1) {

            del(c[i]);
            sum -= *s[c[i]].rbegin();
            s[c[i]].erase( s[c[i]].find(p[i]) );
            add(c[i]);
            sum += *s[c[i]].rbegin();

            c[i] = x;

            del(c[i]);
            sum -= *s[c[i]].rbegin();
            s[c[i]].insert(p[i]);
            sum += *s[c[i]].rbegin();
            add(c[i]);


        } else {
            del(c[i]);
            sum -= *s[c[i]].rbegin();
            s[c[i]].erase( s[c[i]].find(p[i]) );
            p[i] = x;
            s[c[i]].insert(p[i]);

            sum += *s[c[i]].rbegin();
            add(c[i]);
        }
        // print();
        cout << max(sum + *s2.rbegin() - *s1.begin(), sum) << endl;
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