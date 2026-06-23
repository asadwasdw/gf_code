#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

void print(__int128 x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);//注意这里是x>9不是x>10 (2019.10 wa哭了回来标记一下)
    putchar(x%10+'0');
}

__int128_t gfsqrt(__int128_t x) {
    __int128_t l = 0, r = 1e15;
    while(l < r) {
        __int128_t mid = (l + r + 1) >> 1;
        if(mid * mid <= x) l = mid;
        else r = mid - 1;
    }
    return l;
}

vector <int> add(vector<int> A,vector<int> B){
	if (A.size() < B.size()) return add(B,A); // 因为下面for循环用A.size()当条件，所以现在只能让A比B长
	vector<int> C;
	int t = 0;
	for(int i = 0;i < A.size();i++){
		t += A[i];
		if(i < B.size()) t += B[i]; // 判断B是否够长 
		C.push_back(t % 10);
		t /= 10;
	}
	if (t) C.push_back(t);
	return C;
}



vector <int> mul(vector <int> A, vector <int> B) {
    vector <int> C(A.size() + B.size(), 0);
    for (int i = 0; i < A.size(); i ++) {
	    for (int j = 0; j < B.size(); j ++){
		    C[i + j] += A[i] * B[j];
		    C[i + j + 1] += C[i + j] / 10;
		    C[i + j] %= 10;
		}
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}



bool cmp(vector<int> A,vector<int> B){
	if (A.size() != B.size()) return A.size() > B.size();
	for (int i = A.size() - 1;i >= 0;i++){
		if (A[i] != B[i]) return A[i] > B[i];
	}
	return true;
}

vector <int> sub(vector<int> A,vector<int> B){
    vector <int> C;
    int t = 0;
    for(int i = 0; i < A.size(); i++){
        t = A[i] - t;
        if(i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10); // t+10是为了避免t<0 
        if(t < 0) t = 1; // 借位 
        else t = 0; // 不借位 
    }
    while(C.size() > 1 && C.back() == 0) C.pop_back();  //去掉前导0
    return C;
}

vector<int> bh(__int128_t x) {
    vector<int> res;
    while(x) {
        res.push_back (x % 10);
        x /= 10;
    }
    return res;
}


vector<int> js(int n, string x) {
    x = " " + x;
    __int128_t a = 0, b = 0; 
    for(int i = 1; i <= n; i ++) {
        if(i <= n/2) a = a * 10 + x[i] - '0';
        else b = b * 10 + x[i] - '0';
    }
    // print(a); cout << ' ';
    // print(b);
    // cout << endl;

    __int128_t resa = 0, resb = 0;
    __int128_t t = 1; for(int i = 1; i <= n/2; i ++) t *= 10;
    __int128_t l = 0, r = gfsqrt(a + 1);
    
    while(l < r) {
        __int128_t mid = (l + r + 1) >> 1;
        if(mid * mid < t / 10) l = mid;
        else r = mid - 1;
    }
    // cout << l << endl;

    resa = gfsqrt(a) - l;
    // print(resa); cout << endl;
    vector<int> T;
     vector<int> ans;
    if(gfsqrt(a) * gfsqrt(a) == a) {
        if(resa >= 1) {
            resa --;
            ans = bh(resa);
            T = bh(gfsqrt(t - 1) + 1);
            ans = mul(ans, T);
        }
        else {
            ans.push_back(0);
        }


        T = bh(gfsqrt(b) + 1);
        ans = add(ans, T);
        
        return ans;

    }
    // cout << resa << " " << (sqrt(t) + 1) << endl; 

    return mul(bh(resa), bh(gfsqrt(t - 1) + 1));
}

bool check(int n, string x) {
    x = " " + x;
    __int128_t a = 0, b = 0; 
    for(int i = 1; i <= n; i ++) {
        if(i <= n/2) a = a * 10 + x[i] - '0';
        else b = b * 10 + x[i] - '0';
    }
    return (gfsqrt(a) * gfsqrt(a) == a && gfsqrt(b) * gfsqrt(b) == b);
}





void solve()
{
    int n;
    string l, r;
    cin >> n >> l >> r;
    
    vector<int> ansr = js(n, r);
    vector<int> ansl = js(n, l);
    vector<int> ans = sub(ansr, ansl);

    if(check(n, l)) {
        vector<int> T; T.push_back(1);
        ans = add(ans, T);
    }

    auto C = ans;
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    for (int i = C.size() - 1;i >= 0;i--) cout << C[i];
}


signed main()
{
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}