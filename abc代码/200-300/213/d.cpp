#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
using namespace std;
const int N = 2e5 + 10;
map<int, priority_queue<int, vector<int>, greater<int>>>mp;

int last[N];
bool st[N];
int main()
{

    memset(last, -1, sizeof last);
    int n;
    cin >> n;
    int wt = 1;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        mp[a].push(b);
        mp[b].push(a);
    }
    st[1] = true;

    while (1)
    {
        cout << wt << " ";
        if (mp[wt].size()) {
            while (mp[wt].size() && st[mp[wt].top()]) {
                mp[wt].pop();

            }
            if (!mp[wt].size()) {

                if (wt == 1)break;
                wt = last[wt];
                continue;
            }
            int t = mp[wt].top();
            mp[wt].pop();
         
            if (last[t] == -1)last[t] = wt;
            st[t] = true;
            wt = t;
        }
        else {
            if (wt == 1)break;
            wt = last[wt];

        }
    }

    return 0;

}