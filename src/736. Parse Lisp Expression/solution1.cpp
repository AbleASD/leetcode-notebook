/*
 * @Author: Able
 * @Date: 2022-07-06 15:06:40
 * @Last Modified by: Able
 * @Last Modified time: 2022-07-06 21:38:29
 * @link https://leetcode.cn/problems/parse-lisp-expression/ @endlink
 */

#include "bits/stdc++.h"
using namespace std;

class Solution
{
private:
    unordered_map<string, vector<int>> scope;
public:
    int evaluate(string expression)
    {
        int start = 0;
        return innerEvaluate(expression, start);
    }

    int innerEvaluate(const string &expression, int &start) {
        if (expression[start] != '(') {
            if (islower(expression[start])) {
                string var = parseVar(expression, start);
                return scope[var].back();
            } else {
                return parseInt(expression, start);
            }
        }

        int ret;
        start++;

        if (expression[start] == 'l') {
            start += 4;  // 移除 "let "
            vector<string> vars;
            while (true) {
                if (!islower(expression[start])) {
                    ret = innerEvaluate(expression, start);  // 如果非小写字母 说明为一个表达式 返回该表达式结果
                    break;
                }
                string var = parseVar(expression, start);
                if (expression[start] == ')') {
                    ret = scope[var].back();  // 如果结束，则返回最后一个变量的值
                    break;
                }
                vars.push_back(var);
                start++;  // 跳过空格
                int e = innerEvaluate(expression, start);
                scope[var].push_back(e);
                start++;
            }
            for (auto var: vars) {
                scope[var].pop_back();
            }
        } else if (expression[start] == 'a') {
            start += 4;  // 移除 "add "
            int e1 = innerEvaluate(expression, start);
            start++;
            int e2 = innerEvaluate(expression, start);
            ret = e1 + e2;
        } else if (expression[start] == 'm') {
            start += 5;  // 移除 "mult "
            int e1 = innerEvaluate(expression, start);
            start++;
            int e2 = innerEvaluate(expression, start);
            ret = e1 * e2;
        }
        start++;
        return ret;
    }

    // parse value
    int parseInt(const string &expression, int &start) {
        int n = expression.size();

        int ret = 0, sign = 1;
        if (expression[start] == '-') {
            sign = -1;
            start++;
        }

        while (start < n && isdigit(expression[start])) {
            ret = 10 * ret + expression[start++] - '0';
        }
        return sign * ret;
    }

    // parse variable
    string parseVar(const string &expression, int &start)
    {
        int n = expression.size();
        string ret;
        while (start < n && expression[start] != ' ' && expression[start] != ')') {
            ret.push_back(expression[start++]);
        }
        return ret;
    }
};

int main()
{
    Solution slt;
    return 0;
}