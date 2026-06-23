#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<char,int>PII;
const int N=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N];


stack<PII>sta[N];

void myop1(int x,int y) {
    while(sta[x].size()) {
        sta[y].push(sta[x].top());
        sta[x].pop();
    }
}

void myop2(int x,int y) {
    stack<PII>t;
    while(sta[x].size()) {
        t.push(sta[x].top());
        sta[x].pop();
    }
    while(t.size()) {
        sta[y].push(t.top());
        t.pop();
    }
}

void myop3(int x) {
    char t = '?';
    while(sta[x].size()) {
        if(sta[x].top().second != x)sta[sta[x].top().second].push(sta[x].top());
        else t = sta[x].top().first;
        sta[x].pop();
    }

    if(t != '?'){
        sta[x].push({t, x});
    }
}

void cl(stack<PII> a) {
    int numl = 0;
    vector<char>t;
    while(a.size()) {
        t.push_back(a.top().first);
        a.pop();
    }
    reverse(t.begin(), t.end());
    stack<char>A;

    vector<string>ans;
    for(auto T : t) {
        if(T == '(') {
            numl ++;
            A.push(T);
        }
        else if(T == ')') {
            if(numl == 0) {
                cout << "-1\n";
                return;
            }
            numl --;
            string Ans;
            while(A.top() != '(') {
                Ans += A.top(); 
                A.pop();
            }
            A.pop();
            reverse(Ans.begin(), Ans.end());
            if(Ans.size() != 0)ans.push_back(Ans);
        }
        else A.push(T);
    }
    string Ans;
    while(A.size()) {
                Ans += A.top(); 
                A.pop();
    }
    reverse(Ans.begin(), Ans.end());
    if(Ans.size() != 0)ans.push_back(Ans);

    if(numl) {
        cout << "-1\n";
        return;
    }
    cout << ans.size() << " ";
    for(auto T : ans) cout << T << " ";
    cout << endl;



}

void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        char t;
        cin >> t;
        sta[i].push({t,i});
    }

    while(m -- ) {
        int op,x,y;
        cin >> op >> x;
        if(op == 1) {
            cin >> y;
            myop1(x, y); 
        }
        else if(op == 2) {
            cin >> y;
            myop2(x,y);
        }
        else {
            myop3(x);
        }
    }

    for(int i = 1; i <= n; i ++) {
        // cout << i << " ";
        cl(sta[i]);
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