/*
 * @Author: Able 
 * @Date: 2022-07-02 21:12:07 
 * @Last Modified by: Able
 * @Last Modified time: 2022-07-02 21:37:45
 * @link https://leetcode.cn/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/ @endlink
 */


#include "bits/stdc++.h"
using namespace std;

// greedy, select the biggest one. complex: log(k)
class Solution {
public:
    vector<int> fibonacci(int k) {
        vector<int> fib = {0, 1, 1};
        while (fib.back() < k) {
            fib.push_back(*(fib.end() - 2) + *(fib.end() - 1));
        }
        return fib;
    }
    int findMinFibonacciNumbers(int k) {
        vector<int> fib = fibonacci(k);
        int n = fib.size();
        if (k == fib[n - 1]) return 1;
        
        int i = n - 1, ret = 0;
        while (k != 0) {
            for (int j = i; j > 0; --j) {
                if (fib[j] <= k) {
                    k -= fib[j];
                    i = j;
                    ret++;
                    break;
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution slt;
    slt.findMinFibonacciNumbers(7);
    return 0;
}