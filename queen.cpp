#include <iostream>
#include <cstring>
using namespace std;
int dx[12] = {-2, -2, -1, 1, 2, 2, 2, 2, 1, -1, -2, -2};
int dy[12] = {-1, -2, -2, -2, -2, -1, 1, 2, 2, 2, 2, 1};
int d[101][101];
int queue[10010][3];
int main()
{
    int f_h = 1;
    int f_t = 1;
    memset(d, -1, sizeof(d));
    queue[1][0] = 1;
    queue[1][1] = 1;
    queue[1][2] = 0;
    int x1, x2, y1, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    while (f_h <= f_t)
    {
        for (int i = 0; i < 12; ++i)
        {
            int x = queue[f_h][0] + dx[i];
            int y = queue[f_h][1] + dy[i];
            if (x > 0 && y > 0)
            {
                if (d[x][y] == -1)
                {
                    d[x][y] = queue[f_h][2] + 1;
                    f_t++;
                    queue[f_t][0] = x;
                    queue[f_t][1] = y;
                    queue[f_t][2] = d[x][y];
                    if (d[x1][y1] > 0 && d[x2][y2] > 0)
                    {
                        cout << d[x1][y1] << endl;
                        cout << d[x2][y2] << endl;
                        return 0;
                    }
                }
            }
        }
        f_h++;
    }
}