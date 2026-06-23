#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 5000050;

int mob[N], vis[N], prime[N], sum[N];
int tot;//用来记录prime的个数

void Mobius(int n) {   //求得莫比乌斯函数值

    memset(prime, 0, sizeof(prime));
    memset(mob, 0, sizeof(mob));
    memset(vis, 0, sizeof(vis));
    tot = 0, mob[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            prime[tot++] = i;
            mob[i] = -1;
        }
        for (int j = 0; j < tot && i * prime[j] <= n; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j]) mob[i * prime[j]] = -mob[i];
            else {
                mob[i * prime[j]] = 0;
                break;
            }
        }
    }
}

int main() {
    Mobius(N - 1);
     long long n, m;
    scanf("%d%d", &n, &m);
    if (n == 1 && m == 1) puts("0");
    else if (n == 1 || m == 1) puts("1");
    else {
        --n;
        --m;
        long long ans=2;
        for(int i=1;i<=min(n,m);i++){
            ans+=(n/i)*(m/i)*mob[i];
        }

        cout<<ans<<endl;
    
    }
    return 0;
}
