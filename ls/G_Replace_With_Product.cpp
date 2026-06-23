#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int a[N];
int n;
int pre[N];
void solve() {
 
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

 
	int sum = 1;
	bool success = true;
	for (int i = 1; i <= n; ++i) {
		sum *= a[i];
		if (sum > 2*n) {
			success = false;
			break;
		}
	}
 
	if (!success) {
		int i = 1, j = n;
		while (a[i] == 1 && i <= n) {
			i++;
		}
		while (a[j] == 1 && j >= 1) {
			j--;
		}
 
		cout << i << ' ' << j << '\n';
	} else {
		vector<int> pos;
		for (int i = 1; i <= n; ++i) {
			if (a[i] != 1) {
				pos.push_back(i);
			}
		}
 
		for (int i = 1; i <= n; ++i) {
			pre[i] = pre[i - 1] + a[i];
			a[i] = a[i - 1] * a[i];
		}
 
		int ansl = -1, ansr = -1;
		int maxx = -1;
		for (int i = 0; i < pos.size(); ++i) {
			for (int j = i + 1; j < pos.size(); ++j) {
				if (pre[pos[j]] - pre[pos[i] - 1] <= a[pos[j]] / a[pos[i] - 1]) {
					if (maxx < pre[n] - pre[pos[j]] + pre[pos[i] - 1] + a[pos[j]] / a[pos[i] - 1]) {
						maxx = pre[n] - pre[pos[j]] + pre[pos[i] - 1] + a[pos[j]] / a[pos[i] - 1];
						ansl = pos[i], ansr = pos[j];
					}
				}
			}
		}
 
		if (ansl == -1 && ansr == -1) {
                        //需要特判只有一个元素，并且这个元素是非1元素的情况.
			ansl = 1, ansr = 1;
		}
		cout << ansl << ' ' << ansr << '\n';
	}
    for(int i=1;i<=n;i++)a[i]=pre[i]=0;
 
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}