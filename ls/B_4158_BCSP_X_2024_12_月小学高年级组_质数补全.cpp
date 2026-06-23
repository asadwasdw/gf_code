#include <bits/stdc++.h>
using namespace std;

int t;
string s;
int len, mn;
int num[10];

bool isp(int x)
{
if (x < 2) return 0;
for (int i = 2;i * i <= x;i++)
{
if (x % i == 0) return 0;
}
return 1;
}

void dfs(int now)
{
    if (mn) return; // 你这得剪枝， 不然会tle

    for (int i = 0;i <= 9;i++) {
        num[now] = i;
        int j = now + 1;
        for (;j <= len;j++) {
            if (num[j] == -1) break;
        }
        if (j <= len) {
            dfs(j);
        }
        else {
            int ans = 0;
            for (int i = 1;i <= len;i++)  ans = ans * 10 + num[i];
            if (isp(ans) && !mn) mn = ans;
        }
    }
    num[now] = -1; // 回溯
}

int main()
{
cin >> t;
while (t--)
{
mn = 0;
cin >> s;
len = s.size();
for (int i = 0;i < len;i++)
{
if (s[i] == '*') num[i + 1] = -1;
else num[i + 1] = s[i] - '0';
}
dfs(0);
cout << (mn?mn:-1) << "\n";
}
return 0;
}