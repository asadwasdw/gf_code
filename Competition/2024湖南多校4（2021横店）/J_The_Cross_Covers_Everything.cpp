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

//vector<vector<int>>edg(N);
#define x first
#define y second
PII a[N];

bool cmp(PII a, PII b) {
    return a.x < b.x;
}
int mx[N],mn[N];
vector<int>s1,s2;

void print(PII a)  {
    cout << a.x << " " << a.y << endl;
}

void solve()
{ 
    
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i].x >> a[i].y;
    sort(a + 1, a + n + 1, cmp);
   
    for(int i = 1; i <= n; i ++ ) {
        mx[i] = max(a[i].y, mx[i - 1]);
        while(s1.size() && a[s1.back()].y < a[i].y)s1.pop_back();
        s1.push_back(i);
    }
    
    mn[n + 1] = INF;
    for(int i = n; i ; i --) {
        mn[i] = min(a[i].y, mn[i + 1]);
        while(s2.size() && ((a[s2.back()].y) > (a[i].y)))s2.pop_back();
        
        s2.push_back(i);
    }

    reverse(s2.begin(), s2.end());

    // for(auto T : s1) print(a[T]);cout << endl;for(auto T : s2) print(a[T]);
    int ans = 0;

    int l = 0, r = 0, i = s2.size(), j = s2.size();
    for(auto t : s1) {
        while(r < s2.size() && a[s2[r]].x < a[t].x) {
            r ++;
        }
        while(l < s2.size() && a[s2[l]].y > a[t].y) {
            l ++;
        } 
        //[0,r) 一共 r 个数

        while(i && mx[s2[i - 1]] > a[t].y ) {
            i -- ;
        }

        while(j && a[s2[j - 1]].y < mn[t]) {
            j --;
        }

        // 1 | 2 | 3
        // 4 | 5 | 6
        // 7 | 8 | 9
    
        // min(r, r1) - std::max(l, l1)
        // 保证了以下几点
        // 3,7无点，预处理好的
        // 1,9, 通过双指针操作
        // 满足左下右上关系, 通过双指针操作
        ans += max(min(r,i) - max(l,j),0ll);
    }
    cout << ans << endl;

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

// #include <bits/stdc++.h>
// using namespace std;


// using PII = std::pair<int, int>;
// using LL = long long;
// const int L = 1e6;
// void print(PII a) {
//     cout << a.first << " " << a.second << endl;
// }

// void solve() {
//   int n;
//   std::cin >> n;
//   std::vector<PII> a(n);

//   for (auto &[x, y] : a) {
//     std::cin >> x >> y;
//   }
//   std::sort(a.begin(), a.end());
    
//   std::vector<int> s1, s2;
//   for (int i = 0; i < n; i++) {
//     while (!s1.empty() && a[s1.back()].second < a[i].second) s1.pop_back();
//     s1.push_back(i);
//   }
//   // 可以做右上角的可行点
//   for (int i = n - 1; i >= 0; i--) {
//     while (!s2.empty() && a[s2.back()].second > a[i].second) s2.pop_back();
//     s2.push_back(i);
//   }
//   // 可以做左下角的可行点

//   std::reverse(s2.begin(), s2.end());
//    cout << endl;for(auto T : s1) print(a[T]);cout << endl;for(auto T : s2) print(a[T]);
//   std::vector<int> suf_min(n), pre_max(n);
//   for (int i = n - 1; i >= 0; i--) {
//     suf_min[i] = a[i].second;
//     if (i + 1 < n - 1) {
//       suf_min[i] = std::min(suf_min[i], suf_min[i + 1]);
//     }
//   }
//   // 从后往前的最低值

//   for (int i = 0; i < n; i++) {
//     pre_max[i] = a[i].second;
//     if (i) {
//       pre_max[i] = std::max(pre_max[i], pre_max[i - 1]);
//     }
//   }
//   // 从前往后的最高值

//   LL ans = 0;
//   int l = 0, r = 0, l1 = s2.size(), r1 = s2.size();
//   for (int i : s1) { // 枚举每个右上角

//     // 那么每个左下点要满足2个条件
//     while (r < s2.size() && a[s2[r]].first < a[i].first) {
//       r++;
//     }
//     //(0,r)是目前可以的，保证了这些点x小于右上

//     while (l < s2.size() && a[s2[l]].second > a[i].second) {
//       l++;
//     }
//     // (0,l]是不可行的，因为l.y > 右上
     

//     // cout << i << " " << r  << " " << r << endl;
    
//     while (r1 && pre_max[s2[r1 - 1]] > a[i].second) { 
//       r1--;
//     }
//     //(0,r1)是目前可以的, 1区间没有点
    


//     while (l1 && a[s2[l1 - 1]].second < suf_min[i]) {
//       l1--;
//     }
//     //(0,l)是不可行的，9区域或存在点



 
//     ans += std::max(0, std::min(r, r1) - std::max(l, l1));
//     cout << r << " " << r1 << " " << l << " " << l1 << endl;
//   }
//   std::cout << ans << "\n";
// }

// int main() {
//   std::ios::sync_with_stdio(0);
//   std::cin.tie(0);

//   int t = 1;
//   // std::cin >> t;

//   while (t--) {
//     solve();
//   }
//   return 0;
// }
