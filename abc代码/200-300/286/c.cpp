#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<cstring>
using namespace std;
int N, A, B;
map<string, long long>st;
long long ans = -1;

bool pd(string s)
{
    for (int i = 0; i < N; i++)
    {
        if (s[i] != s[N - i - 1])return false;
    }
    return true;
}


void bfs()
{
    string S;
    cin >> S;
    st[S] = 0;
    queue<string>d;
    d.push(S);
    // cout<<d.size();
    while (d.size())
    {
        string T = d.front();
        d.pop();
       // cout << T << " " << st[T] << endl;
        if (ans != -1 && st[T] >= ans)continue;
        string t;
        t = T.substr(1) + T[0];
        // cout<<t<<endl;
        if ((st[t] == 0 || (st[t] > st[T] + A)) && t != S) {

            d.push(t);
            st[t] = st[T] + A;
            if (pd(t)) {
                if (ans == -1)ans = st[t];
                else ans = min(ans, st[t]);
            }
        }

        for (int i = 0; i < N; i++)
        {
            t = T.substr(0, i) + T.substr(N-i-1, 1) + T.substr(i + 1);

            if ((st[t] == 0 || (st[t] > st[T] + B)) && t != S) {
              //  cout << T << " " << i << " " << t << endl;
                d.push(t);
                st[t] = st[T] + B;
                if (pd(t)) {
                    if (ans == -1)ans = st[t];
                    else ans = min(ans, st[t]);
                }
            }

        }

    }


}


int main()
{
    cin >> N >> A >> B;

    bfs();
    cout << ans << endl;



}