#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using i64 = long long;
#define endl "\n"

const int N = 2e5 + 10;

struct node
{
    int val;
    node *nx[2];
}*head[N], *ed[N];

void solve() {
    int n,m;
    while(cin >> n >> m){
        for(int i=1; i<=n; ++i)head[i] = new node(), ed[i] = new node();
        for(int i=1; i<=n; ++i){
            head[i]->val = 0;
            head[i]->nx[0] = NULL;
            head[i]->nx[1] = NULL;
            ed[i]->val = 0, ed[i]->nx[0] = ed[i]->nx[1] = NULL;
            node* temp = new node();
            temp->val = i;
            temp->nx[1] = ed[i];ed[i]->nx[0] = temp;
            temp->nx[0] = head[i];head[i]->nx[1] = temp;
        }
        auto get = [&](node *p){//得到非空的一边
            if(p->nx[0] == NULL)return 1;
            return 0;
        };
        auto get2 = [&](node *p, int a){//p->nx[a]那边指向的p
            if(p->nx[a]->nx[0] == p)return 0;
            return 1;
        };
        auto merge = [&](int i, int j){
            int x = get(head[j]);
            if(head[j]->nx[x] == ed[j]){
                int a = get(head[i]), b = get(ed[i]);
                if(head[i]->nx[a] == ed[i])return;
                int c = get2(ed[i], b);
                head[i]->nx[a^1] = ed[i]->nx[b];
                ed[i]->nx[b]->nx[c] = head[i];
                ed[i]->nx[b^1] = head[i]->nx[a];
                c = get2(head[i], a);
                head[i]->nx[a]->nx[c] = ed[i];
                head[i]->nx[a] = NULL;
                ed[i]->nx[b] = NULL;
                return;
            }
            x = get(head[i]);
            if(head[i]->nx[x] == ed[i]){
                int a = get(head[j]), b = get(ed[j]);
                head[i]->nx[0] = NULL;
                head[i]->nx[1] = ed[j]->nx[b];
                int c = get2(ed[j], b);
                ed[j]->nx[b]->nx[c] = head[i];
                ed[i]->nx[1] = NULL;
                ed[i]->nx[0] = head[j]->nx[a];
                c = get2(head[j], a);
                head[j]->nx[a]->nx[c] = ed[i];
                head[j]->nx[0] = head[j]->nx[1] = ed[j]->nx[0] = ed[j]->nx[1] = NULL;
                head[j]->val = ed[j]->val = 0;
                head[j]->nx[1] = ed[j];ed[j]->nx[0] = head[j];
                return;
            }
            int a = get(ed[i]), b = get(head[j]);
            int c = get2(ed[i], a);
            //ping jie
            ed[i]->nx[a]->nx[c] = head[j]->nx[b];
            c = get2(head[j], b);
            head[j]->nx[b]->nx[c] = ed[i]->nx[a];

            int pre = get(head[i]) ^ 1, pre2 = get(ed[j]);

            head[i]->nx[pre] = ed[j]->nx[pre2];
            ed[i]->nx[0] = ed[i]->nx[1] = NULL;
            ed[i]->nx[0] = head[i]->nx[pre^1];
            c = get2(head[i], pre^1);
            head[i]->nx[pre^1]->nx[c] = ed[i];
            head[i]->nx[pre^1] = NULL;
            c = get2(ed[j], pre2);
            ed[j]->nx[pre2]->nx[c] = head[i];

            head[j]->nx[0] = head[j]->nx[1] = ed[j]->nx[0] = ed[j]->nx[1] = NULL;
            head[j]->val = ed[j]->val = 0;
            head[j]->nx[1] = ed[j];ed[j]->nx[0] = head[j];
        };

        while(m--){
            int l,r;
            cin >> l >> r;
            merge(l, r);
        }
        vector<int> res;
        int a = get(head[1]);
        int b = get2(head[1], a);
        node *p = head[1]->nx[a];
        while(p -> val != 0){
            res.push_back(p->val);
            int c = b;
            b = get2(p, b ^ 1);
            p = p->nx[c ^ 1];
            
        }
        cout << res.size();
        for(int i=0; i<res.size(); ++i)cout << ' ' << res[i];cout << endl;
        // cout << "SSS" << endl;
        for(int i=1; i<=n; ++i){
            delete head[i];
            delete ed[i];
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t = 1; 
    // cin >> t;
    while (t--) {
        solve();
    }
}