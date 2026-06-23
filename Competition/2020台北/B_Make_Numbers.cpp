#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int a[N];
set<int>s;

void js() {

   
    for(int i = 1; i <= 4; i ++) {
        for(int j = 1; j <= 4; j ++) {
            for(int k = 1; k <= 4; k ++) {
                if(i == j && j == k && k == 4) continue;

                vector<int>b;
                b.push_back(a[1]);
                vector<int>op;

                if(i == 4) {
                    int t = b.back();
                    b.pop_back();
                    b.push_back(t * 10 + a[2]);
                }
                else {
                    b.push_back(a[2]), op.push_back(i);
                }

                if(j == 4) {
                    int t = b.back();
                    b.pop_back();
                    b.push_back(t * 10 + a[3]);
                }
                else {
                    b.push_back(a[3]), op.push_back(j);
                }

                if(k == 4) {
                    int t = b.back();
                    b.pop_back();
                    b.push_back(t * 10 + a[4]);
                }
                else {
                    b.push_back(a[4]), op.push_back(k);
                }

                // for(auto t : b) cout << t << " "; cout << endl;



                stack<int>A;
                stack<int>OP;

                A.push(b[0]);
                for(int i = 1; i < b.size(); i ++) {
                    while(OP.size() && op[i - 1]/3 <= OP.top()/3) {
                        int b = A.top();A.pop();
                        int aa = A.top();A.pop();
                        if(OP.top() == 3) {
                            A.push(aa * b);
                        }
                        else if(OP.top() == 2) {
                            A.push(aa - b);
                        }
                        else A.push(aa + b);
                        OP.pop();
                    }

                    OP.push(op[i - 1]);
                    A.push(b[i]);
                }

                while(OP.size()) {
                    int b = A.top();A.pop();
                    int aa = A.top();A.pop();
                    if(OP.top() == 3) {
                        A.push(aa * b);
                    }
                    else if(OP.top() == 2) {
                        A.push(aa - b);
                    }
                    else A.push(aa + b);
                    OP.pop();
                }

                int ans = A.top();

                if(ans >= 0) s.insert(ans);

            }
        }
    }



}

void solve()
{
    for(int i = 1; i <= 4; i ++) cin >> a[i];
    sort(a + 1, a + 5);
    
    do{
        js();
    }while(next_permutation(a + 1, a + 5));



    cout << s.size() << endl;






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