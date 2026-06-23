#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);


void solve1() {
    int n, w; cin >> n >> w;
    vector<int> a;
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        a.push_back(x);
        sort(a.begin(), a.end(),[&](int a, int b) {
            return a > b;
        });
        int cnt = max(1, i * w/100);
        cout << a[cnt - 1] << " ";
        // for(auto t : a) cout << t << " "; cout << endl; 
    }
    // 2000*2000*11 = 4e7
    // 预期50， 实际70 分
}

void solve2() {
    int n, w; cin >> n >> w;
    vector<int> a;
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        a.push_back(x);

        for(int j = i - 1; j > 0; j --) {
            if(a[j] > a[j - 1]) swap(a[j], a[j - 1]);
        }
   
        int cnt = max(1, i * w/100);
        cout << a[cnt - 1] << " ";
        // for(auto t : a) cout << t << " "; cout << endl; 
    }

    // 85 分
}

void solve3() {
    int n, w; cin >> n >> w;
    vector<int> a(610, 0);
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        a[x] ++;
        int cnt = max(1, i * w / 100), sum = 0;
        for(int j = 600; j >= 0; j --) {
            sum += a[j];
            if(sum >= cnt) {
                cout << j << " ";
                break;
            }
        }
    }
}

void solve4()
{
    int n, w;
    cin >> n >> w;
    priority_queue<int,vector<int>,greater<int>> q1; // 小根队
    priority_queue<int> q2; // 大根堆
    int cnt = 0;
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        
        cnt = max(1, i * w / 100);
        // cout << cnt << endl;
        q1.push(x);

        while(q1.size() && q2.size() && q1.top() < q2.top()) {
            int u = q1.top(), v = q2.top();
            q1.pop(), q2.pop();
            q2.push(u),q1.push(v);
        }

        while(q1.size() > cnt) {
            int u = q1.top(); q1.pop();
            q2.push(u);
        }

        while(q1.size() < cnt) {
            int u = q2.top(); q2.pop();
            q1.push(u);
        }

        cout << q1.top() << " ";
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
        solve4();
    }
}