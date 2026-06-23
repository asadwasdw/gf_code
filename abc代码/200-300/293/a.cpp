#include <stdio.h>

int arr[1000100];
char s[1000100];
int q[1000100];
int p[1000100];
int main()
{
    int n;

    scanf("%d", &n);
    // for(int i=1;i<=n;i++)
    // {
    //     arr[i]=s[i]=q[i]=p[i]=0;
    // }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    getchar();
    for (int i = 1; i <= n; i++)
    {
        char c = getchar();
        if (c == 'R')
        {
            q[arr[i]]++;
        }
        else
            p[arr[i]]++;
        s[i] = c;
    }
    int flag = 1;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += p[i];
        if (cnt > i)
        {
            flag = 0;
        }
    }
    cnt = 0;
    for (int i = n; i >= 1; i--)
    {
        cnt += q[i];
        if (cnt > n - i + 1)
        {
            flag = 0;
        }
    }
    if (flag)
    {
        printf("YES");
    }
    else
        printf("NO");
}
#include <stdio.h>

int arr[1000100];
char s[1000100];
int q[1000100];
int p[1000100];
int main()
{
    int n;

    scanf("%d", &n);
    // for(int i=1;i<=n;i++)
    // {
    //     arr[i]=s[i]=q[i]=p[i]=0;
    // }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    getchar();
    for (int i = 1; i <= n; i++)
    {
        char c = getchar();
        if (c == 'R')
        {
            q[arr[i]]++;
        }
        else
            p[arr[i]]++;
        s[i] = c;
    }
    int flag = 1;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += p[i];
        if (cnt > i)
        {
            flag = 0;
        }
    }
    cnt = 0;
    for (int i = n; i >= 1; i--)
    {
        cnt += q[i];
        if (cnt > n - i + 1)
        {
            flag = 0;
        }
    }
    if (flag)
    {
        printf("YES");
    }
    else
        printf("NO");
}
