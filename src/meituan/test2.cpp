#include "bits/stdc++.h"
using namespace std;

int main(void)
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> room(n, vector<int>(m, 0));
    room[0][0] = 1;

    int num = 0;           // 指令编号
    int done = 1;          // 打扫过的地块
    int all_floor = n * m; // 总的地块数量

    vector<int> point(2, 0);

    char command;
    bool flag = false; // 是否打扫干净
    while (k--)
    {
        cin >> command;
        if (command == 'W')
        {
            point[0]--;
        }
        else if (command == 'S')
        {
            point[0]++;
        }
        else if (command == 'A')
        {
            point[1]--;
        }
        else if (command == 'D')
        {
            point[1]++;
        }

        num++;
        if (room[point[0]][point[1]] == 0)
        {
            done++;
            room[point[0]][point[1]] = 1;
        }
        if (done == all_floor)
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        cout << "Yes" << endl;
        cout << num << endl;
    }
    else
    {
        cout << "No" << endl;
        cout << all_floor - done << endl;
    }
    return 0;
}