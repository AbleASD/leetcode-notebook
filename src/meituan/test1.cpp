#include "bits/stdc++.h"
using namespace std;


int getMaxMoney(vector<int> & nodes, int root) {
    if (root >= nodes.size()) return 0;

    return nodes[root] + max(getMaxMoney(nodes, 2 * (root + 1) - 1), getMaxMoney(nodes, 2*(root + 1)));
}

int main(void)
{
    int n;
    cin >> n;
    vector<int> nodes(n, 0);

    int val;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        nodes[i] = val;
    }

    cout << getMaxMoney(nodes, 0) << endl;


    return 0;
}