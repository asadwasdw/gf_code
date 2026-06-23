#include<iostream>
#include<algorithm>

using namespace std;

const int M = 1e5 + 10;
char a[4][M];
bool st[4][M];
int m, X, Y;
bool ky = false;

void dfs(int tx, int ty, int fx, int fy)
{
    if (ky)return;
    if (a[tx][ty] == 'L')
    {

        if (tx == fx)
        {
            for (int i = -1; i <= 1; i++)
            {
                if (i == 0)continue;
                int x = tx + i;
                int y = ty ;
                if (x == 3 && y == Y)ky = true;
                if (x < 1 || x >= 3 || y<1 || y>m)continue;
                if (st[x][y])continue;
                st[x][y] = true;
                dfs(x, y, tx, ty);
                st[x][y] = false;
            }
        }
        else {

            for (int i = -1; i <= 1; i++)
            {
                if (i == 0)continue;
                int x = tx ;
                int y = ty + i;
                if (x == 3 && y == Y)ky = true;
                if (x < 1 || x >= 3 || y<1 || y>m)continue;
                if (st[x][y])continue;
                st[x][y] = true;
                dfs(x, y, tx, ty);
                st[x][y] = false;
            }
        }
    }
    else {

        if (tx == fx)
        {
            for (int i = 1; i <= 1; i++)
            {
                int x = tx;
                int y = 2 * ty - fy;
                if (x == 3 && y == Y)ky = true;
                if (x < 1 || x >= 3 || y<1 || y>m)continue;
                if (st[x][y])continue;
                st[x][y] = true;
                dfs(x, y, tx, ty);
                st[x][y] = false;
            }
        }
        else {
            for (int i = 1; i <= 1; i++)
            {
                int x = 2 * tx - fx;
                int y = ty;
                if (x == 3 && y == Y)
                {
                    ky = true;
                }
                if (x < 1 || x >= 3 || y<1 || y>m)continue;
                if (st[x][y])continue;
                st[x][y] = true;
                dfs(x, y, tx, ty);
                st[x][y] = false;
            }
        }

    }
}

void solve()
{

    cin >> m >> X >> Y;

    for (int i = 1; i <= m; i++)cin >> a[1][i];
    for (int j = 1; j <= m; j++)cin >> a[2][j];
    ky = false;
    st[1][X] = true;
    dfs(1, X, 0, X);
    st[1][X]=false;
    if (ky)cout << "YES";
    else cout << "NO";
    cout<<endl;

}

int main()
{
    int t; cin >> t; while (t--)
        solve();
}