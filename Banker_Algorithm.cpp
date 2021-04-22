#include <iostream>
#include <queue>
using namespace std;
const int Maxn = 10;
int Need[Maxn][Maxn];
int Allocation[Maxn][Maxn];
int Available[Maxn];
int Max[Maxn][Maxn];
queue<int> out;
bool isGoing(int index, vector<int> work)
{
    int flag = 0;
    int len = work.size();
    for (int i = 0; i < len; i++)
    {
        if (Need[index][i] > work[i])
        {
            flag = 1;
            break;
        }
    }
    if (flag)
        return false;
    return true;
}
bool SafeJudge(int n, int m)
{
    queue<int> q;
    vector<int> work(m);
    for (int i = 0; i < m; i++)
    {
        work[i] = Available[i];
    }
    for (int i = 0; i < n; i++)
    {
        q.push(i);
    }
    vector<bool> finish(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!finish[i] && isGoing(i, work))
        {
            for (int k = 0; k < m; k++)
            {
                work[k] += Allocation[i][k];
            }
            finish[i] = true;
            out.push(i);
            i = -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (finish[i] == false)
            return false;
    }
    return true;
}
int main()
{
    queue<int> q;
    int n, m;
    cout << "请输入进程数:";
    cin >> n;
    cout << "请输入资源种类:";
    cin >> m;
    cout << "请输入各进程最大资源需求:";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> Max[i][j];
        }
    }
    cout << "请输入各进程已分配的资源数:";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> Allocation[i][j];
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }
    cout << "请输入各资源的空闲数:";
    for (int j = 0; j < m; j++)
    {
        cin >> Available[j];
    }
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    while (true)
    {
        int index, s[m];
        cout << "请输入进程号:";
        cin >> index;
        cout << "请输入要请求的资源" << endl;
        ;
        for (int j = 0; j < m; j++)
        {
            cin >> s[j];
        }
        int flag = 0;
        for (int i = 0; i < m; i++)
        {
            if (s[i] > Need[index][i])
            {
                cout << "请求资源大于最大需求,分配失败" << endl;
                flag = 1;
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (s[i] > Available[i])
            {
                cout << "请求资源大于空闲数量,分配失败" << endl;
                flag = 1;
            }
        }
        for (int i = 0; i < m; i++)
        {
            Available[i] -= s[i];
            Allocation[index][i] += s[i];
            Need[index][i] -= s[i];
        }
        if (SafeJudge(n, m))
        {
            while (!out.empty())
            {
                cout << out.front() << " ";
                out.pop();
            }
            cout << endl;
        }
        else
        {
            cout << "分配后处于不安全序列，分配失败" << endl;
            for (int i = 0; i < m; i++)
            {
                Available[i] += s[i];
                Allocation[index][i] -= s[i];
                Need[index][i] += s[i];
            }
        }
        flag = 0;
    }
}