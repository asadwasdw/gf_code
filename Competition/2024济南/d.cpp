#include<bits/stdc++.h>
// #define endl '\n'
using ll = long long;
using i64 = long long;
using namespace std;
constexpr int N = 2e6 + 10;

string s[N];
stack<int> stk;

struct OP{
    bool op1;
    int arr[4];
}op[N];

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) {
        cerr << i << endl;
        string s; 
        scanf("%s ", &s);
        cout << s << endl;
        if(s == "HALT;") {
            op[i].op1 = false;
            cin >> s;
            cin >> op[i].arr[0];
            cin >> s;
            cin >> op[i].arr[1];
            cout << op[i].arr[0] << " " << op[i].arr[1] << endl;
        } else {
            //POP 1 GOTO 2; PUSH 1 GOTO 2
            scanf("%d %s %d; %s %d %s %d\n", &op[i].arr[0], &s, &op[i].arr[1], &s,&op[i].arr[2], &s ,&op[i].arr[3]);
            cout << op[i].arr[0] << " " << op[i].arr[1] << " " << op[i].arr[2] << " " << op[i].arr[3] << endl;
        }
        cerr << i << endl;
    }


}

signed main(){
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}