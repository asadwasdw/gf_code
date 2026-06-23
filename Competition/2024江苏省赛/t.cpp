#include <bits/stdc++.h>

#define x first
#define y second
#define pb push_back

using namespace std;

const int N = 2e5 + 10;
const int P = 1e9 + 7, INF = 0x3f3f3f3f;

typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef long long LL;


void solve() {
    int n;
    cin >> n;

    auto query = [&](int x) {
        cout << "? " << x + 1 << endl;
    	int d;
    	cin >> d;
    	return d;
    };

    int r1, r2, p, d;
    int d1 = query(0), d2 = query(n / 2);
    if(d1 < d2) p = 0, d = d1;
    else p = n / 2, d = d2; 
    int dl = query((p - 1 + n) % n), dr = query((p + 1) % n);
    
    //p在内部
    if(dl == d && dr == d) {
        //向右侧找到第一个不合法点
        int l = 0, r = n / 2;
        while(l < r) {
            int mid = l + r >> 1;
            if(query((p + mid) % n) != d) r = mid;
            else l = mid + 1;
        }
        r1 = (p + l - 1 + n) % n;
        r2 = (r1 - d + n) % n;
    }
    else if(dl > d) {
        //向右侧找到第一个不合法点
        int l = 0, r = n / 2;
        while(l < r) {
            int mid = l + r >> 1;
            if(query((p + mid) % n) != d - 2 * mid) r = mid;
            else l = mid + 1;
        }
        r1 = (p + l - 1 + n) % n;
        r2 = (r1 + query(r1) + n) % n;
    }
    else {
        //向左侧找到第一个不合法点
        int l = 0, r = n / 2;
        while(l < r) {
            int mid = l + r >> 1;
            if(query((p - mid + n) % n) != d - 2 * mid) r = mid;
            else l = mid + 1;
        }
        // cerr << l - 1 << '\n';
        // cerr << p << '\n';
        r1 = (p - (l - 1) + n) % n;
        r2 = (r1 - query(r1) + n) % n;
    }


    cout << "! " << r1 + 1 << ' ' << r2 + 1 << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T -- ) {
        solve();
    }
    return 0;
}
