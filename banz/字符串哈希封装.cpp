int a[N];
struct hx{
    int n;
    ll h[N],p[N],P,mod;
    void init(int _n,ll _p, ll _mod) {
        n = _n, P = _p, mod = _mod;
        p[0] = 1;
        for(int i = 1; i <= n; i ++) {
            (h[i] = h[i - 1] * P + a[i])%=mod;
            (p[i] = p[i - 1] * P)%=mod;
            h[i]%=mod;
            p[i]%=mod;
        }
    }

    ll get(int l, int r) {
        if(l > r) return 0; 
        return (h[r] - (h[l - 1] * p[r - l + 1] %mod) + mod)%mod;
    }
}hx1, hx2;