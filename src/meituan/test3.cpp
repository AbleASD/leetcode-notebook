#include "bits/stdc++.h"
using namespace std;

// 1 2 3 4

// 4 2 1 3

// 1 2 3 4 5 6
// 3 6 4 3 2 5

// 剩余两张牌即不会发生变化
// 剩余三张牌
// 1 2 3
// 3 1 2
int main()
{
    int n, tmp;
    cin >> n;
    queue<int> indexs;
    vector<int> ret(n, 0);
    vector<int> nums;

    while (n--) {
        cin >> tmp;
        nums.push_back(tmp);
    }

    for (int i = 0; i < nums.size(); ++i) {
        indexs.push(i);
    }

    int cur = 0;
    while (!indexs.empty()) {
        int front = indexs.front();
        indexs.pop();
        indexs.push(front);

        front = indexs.front();
        indexs.pop();
        indexs.push(front);

        front = indexs.front();
        indexs.pop();
        ret[front] = nums[cur++];
    }

    for (auto r: ret) {
        cout << r << " ";
    }

    return 0;
}