// #pragma GCC optimize(2)
#include<bits/stdc++.h>
#define init ios::sync_with_stdio(0);cin.tie(0),cout.tie(0)
#define endl '\n'
// #define int long long
using namespace std;
typedef  long long ll;
typedef pair<ll, ll> P;
const int N=5e5+10, M=7e6;


ll n,m,k;
int root[N], cnt;
struct node{
    int l, r;
    int val;
}tr[N*25];

void update(int &k, int l, int r, int x, int d){// 新建棵树
    if(!k)k = ++cnt;
    tr[k].val += d;
    if(l == r)return;
    int mid = l + r >> 1;
    if(mid >= x)update(tr[k].l, l, mid, x, d);
    else update(tr[k].r, mid+1, r, x, d);
}

int merge(int a, int b, int l, int r){//将编号为b线段树合并到编号为a线段树上
    if(!a)return b;
    if(!b)return a;
    if(l == r){
        tr[a].val += tr[b].val;
        return a;
    }
    int mid = l + r >> 1;
    tr[a].l = merge(tr[a].l, tr[b].l, l, mid);
    tr[a].r = merge(tr[a].r, tr[b].r, mid+1, r);
    tr[a].val = tr[tr[a].l].val + tr[tr[a].r].val;
    return a;
}

void split(int k, int &now, int l, int r, int x){//线段树k保留前x个数，剩余的数分裂到线段树now上
    if(!k)return;
    now = ++cnt;
    int mid = l + r >> 1;
    int val = tr[tr[k].l].val;
    if(val < x)split(tr[k].r, tr[now].r, mid+1, r, x - val);
    else swap(tr[k].r, tr[now].r);
    if(val > x)split(tr[k].l, tr[now].l, l, mid, x);
    tr[now].val = tr[k].val - x;
    tr[k].val = x;
}

int query(int k, int l, int r, int x){//查询线段树k的第x大的数
    if(l == r)return l;
    int mid = l + r >> 1;
    if(tr[tr[k].r].val >= x)return query(tr[k].r, mid+1, r, x);
    return query(tr[k].l, l, mid, x - tr[tr[k].r].val);
}

void solve(){
    cin >> n >> m >> k;
    vector<ll> chu(n), yu(n), sum(n), a(n+1);
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        chu[i-1] = a[i] / k;
        yu[i-1] = a[i] % k;
    }

    //将除数和余数离散化
    sort(chu.begin(), chu.end());
    sort(yu.begin(), yu.end());
    chu.erase(unique(chu.begin(), chu.end()), chu.end());
    yu.erase(unique(yu.begin(), yu.end()), yu.end());
    auto get = [&](ll x, vector<ll> &p){
        return lower_bound(p.begin(), p.end(), x) - p.begin();
    };

    int idx = chu.size()-1;

    //记录每个除数的个数
    vector<int> cnt(chu.size());
    for(int i=1; i<=n; ++i){
        int id = get(a[i] / k, chu);
        cnt[id]++;
        update(root[id], 0, 6e5, get(a[i] % k, yu), 1);
    }

    //记录除数个数的前缀和方便后面二分找答案
    sum[0] = cnt[0];
    for(int i=1; i<=idx; ++i){
        sum[i] = sum[i-1] + cnt[i];
    }

    // last: 还剩下多少个最大数没有减k， cha: 只剩最后一个除数时做了多少次整体减k的操作
    ll last = 0, cha = 0;
    while(m--){
        char op;
        ll x;
        cin >> op >> x;
        if(op == 'C'){
            while(x > 0){
                if(idx == 0){//当除数只剩最后一个时，直接算贡献
                    cha += (last + x) / cnt[idx];
                    last = (last + x) % cnt[idx];
                    break;
                }

                if((chu[idx] - chu[idx-1]) * cnt[idx] - last >= x){
                    ll d = (x + last) / cnt[idx], yu = (x + last) % cnt[idx];
                    if(chu[idx] - d == chu[idx-1]){
                        cnt[idx-1] += cnt[idx];
                        root[idx-1] = merge(root[idx-1], root[idx], 0, 6e5);
                        sum[idx-1] += cnt[idx];
                        --idx;
                    }
                    else{
                        chu[idx] -= d;
                    }
                    last = 0, x = 0;
                    last = yu;
                }
                else{
                    x -= (chu[idx] - chu[idx-1]) * cnt[idx] - last;
                    cnt[idx-1] += cnt[idx];
                    sum[idx-1] += cnt[idx];
                    root[idx-1] = merge(root[idx-1], root[idx], 0, 6e5);
                    --idx;
                    last = 0;
                }
            }
        }
        else{
            if(idx == 0){
                if(last){
                    ll res;
                    int p = 0;
                    //把还没减的最后last个数分裂到p线段树上
                    split(root[idx], p, 0, 6e5, cnt[idx] - last);
                    if(x > cnt[idx] - last){
                        res = yu[query(p, 0, 6e5, x - (cnt[idx] - last))] - cha * k - k + chu[idx] * k;
                    }
                    else{
                        res = yu[query(root[idx], 0, 6e5, x)] - cha * k + chu[idx] * k;
                    }
                    root[idx] = merge(root[idx], p, 0, 6e5);
                    cout << res << endl;
                }
                else{
                    cout << yu[query(root[idx], 0, 6e5, x)] - cha * k + chu[idx] * k << endl;
                }
                continue;
            }

            //如果下一个除数与当前除数相邻，直接把欠着的最后last个数合并到下一个除数代表的线段树上
            if(chu[idx] - 1 == chu[idx-1] && last){
                int p = 0;
                split(root[idx], p, 0, 6e5, cnt[idx] - last);
                root[idx-1] = merge(root[idx-1], p, 0, 6e5);
                cnt[idx-1] += last;
                cnt[idx] -= last;
                sum[idx-1] += last;
                last = 0;
            }

            //二分查找答案在哪颗线段树上
            int l = 0, r = idx;
            while(l < r){
                int mid = l + r >> 1;
                if(sum[mid] >= n - x + 1)r = mid;
                else l = mid + 1;
            }

            //直接把后面多的减掉
            x -= sum[idx] - sum[l];

            if(l == idx && last){//如果答案在最后一颗线段树上且有欠费需要特判
                int p = 0;
                split(root[idx], p, 0, 6e5, cnt[idx] - last);
                if(x > cnt[idx] - last){
                    cout << yu[query(p, 0, 6e5, x - (cnt[idx] - last))] + (chu[idx]-1) * k << endl;
                }
                else{
                    cout << yu[query(root[idx], 0, 6e5, x)] + chu[idx] * k << endl;
                }
                root[idx] = merge(root[idx], p, 0, 6e5);
            }
            else{
                cout << yu[query(root[l], 0, 6e5, x)] + chu[l] * k << endl;
            }
        }
        
    }
}


signed main()
{   
    init;
    int t = 1;
    // cout << fixed << setprecision(9)
    // cin >> t;
    while(t--)solve();
    return 0;

}