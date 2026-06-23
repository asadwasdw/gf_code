#include<algorithm>
#include<cstring>
#include<iostream>

using namespace std;
const int N = 3010;
void solve()
{
    int n;
    cin >> n;
    int a[N];
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];

    }


    for (int i = 1; i <= n; i++)
    {
        int cnt = i - 1;
        int t = a[i];
        int last = i;
        bool ky = true;
      

        for (int j = i + 1; j <= n && ky; j++)
        {

            if (j == n && a[j] - a[last] < t) 
            ky = false;

            if (a[j] - a[last] == t)
            {
                cnt += j - last - 1;
                last = j;
            }
            else if (a[j] - a[last] > t) {
                ky = false;
            }

          

           
        }


        if (ky) {
            cout << cnt << endl;
            break;
        }

    }
}


int main()
{
    int n;cin>>n;while(n--)

    solve();


}