#include <iostream>
using namespace std;
int d[20], visit[20];
int n;
void dfs(int key)
{
    if (key > n)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << d[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            d[key] = i + 1;
            visit[i] = 1;
            dfs(key + 1);
            visit[i] = 0;
        }
    }
}
int main()
{
    while (cin >> n && n)
    {
        dfs(1);
    }
    return 0;
}