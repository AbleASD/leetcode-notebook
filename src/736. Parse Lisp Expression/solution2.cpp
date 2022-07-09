/*
 * @Author: Able
 * @Date: 2022-07-06 15:06:40
 * @Last Modified by: Able
 * @Last Modified time: 2022-07-07 10:16:43
 * @link https://leetcode.cn/problems/parse-lisp-expression/ @endlink
 */

#include "bits/stdc++.h"
using namespace std;

// State machine
enum ExprStatus
{
    VALUE = 0,
    NONE,
    LET,
    LET1,
    LET2,
    ADD,
    ADD1,
    ADD2,
    MULT,
    MULT1,
    MULT2,
    DONE
};

struct Expr
{
    ExprStatus status;
    string var;
    int value;
    int e1, e2;
    Expr(ExprStatus s)
    {
        status = s;
    }
};

class Solution
{
private:
    unordered_map<string, vector<int>> scope;

public:
    int evaluate(string expression)
    {
        vector<vector<string>> vars;
        int start = 0, n = expression.size();
        stack<Expr> s;
        Expr cur(VALUE);

        while (start < n)
        {
            if (expression[start] == ' ')
            {
                start++;
                continue;
            }
            if (expression[start] == '(')
            {
                start++;
                s.push(cur);
                cur = Expr(NONE);
                continue;
            }

            string token;
            if (expression[start] == ')')
            {
                start++;
                if (cur.status == LET2)
                {
                    token = to_string(cur.value);
                    for (auto var : vars.back())
                    {
                        scope[var].pop_back();
                    }
                    vars.pop_back();
                }
                else if (cur.status == ADD2)
                {
                    token = to_string(cur.e1 + cur.e2);
                }
                else
                {
                    token = to_string(cur.e1 * cur.e2);
                }
                cur = s.top();
                s.pop();
            }
            else
            {
                while (start < n && expression[start] != ' ' && expression[start] != ')')
                {
                    token.push_back(expression[start]);
                    start++;
                }
            }
            switch (cur.status)
            {
            case VALUE:
                cur.value = stoi(token);
                cur.status = DONE;
                break;
            case NONE:
                if (token == "let") {
                    cur.status = LET;
                    vars.emplace_back();
                } else if (token == "add") {
                    cur.status = ADD;
                } else if (token == "mult") {
                    cur.status = MULT;
                }
                break;
            case LET:
                if (expression[start] == ')') {
                    cur.value = calculateToken(token);
                    cur.status = LET2;
                } else {
                    cur.var = token;
                    vars.back().push_back(token);
                    cur.status = LET1;
                }
                break;
            case LET1:
                scope[cur.var].push_back(calculateToken(token));
                cur.status = LET;
                break;
            case ADD:
                cur.e1 = calculateToken(token);
                cur.status = ADD1;
                break;
            case ADD1:
                cur.e2 = calculateToken(token);
                cur.status = ADD2;
                break;
            case MULT:
                cur.e1 = calculateToken(token);
                cur.status = MULT1;
                break;
            case MULT1:
                cur.e2 = calculateToken(token);
                cur.status = MULT2;
                break;
            }
        }
        return cur.value;
    }

    int calculateToken(const string &token)
    {
        if (islower(token[0]))
        {
            return scope[token].back();
        }
        else
        {
            return stoi(token);
        }
    }
};

int main()
{
    Solution slt;
    string expression = "(let x 2 (mult x (let x 3 y 4 (add x y))))";
    slt.evaluate(expression);
    return 0;
}