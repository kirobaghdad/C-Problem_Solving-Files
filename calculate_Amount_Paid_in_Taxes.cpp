#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <iomanip>
#include <string>
#include <limits>
#include <queue>
#include <stack>
using namespace std;

void read2D_Vector(vector<vector<int>> &brackets)
{
    char chk;
    cin >> chk;
    int i = 0;
    int upper, percent;
    vector<int> temp(2, 0);

    while (chk != 's')
    {
        cin >> upper >> percent;
        temp[0] = upper;
        temp[1] = percent;
        brackets.insert(brackets.end(), temp);
        cin >> chk;
        i++;
    }
}

class Solution
{
public:
    double calculateTax(vector<vector<int>> &brackets, int income)
    {
        double tax = 0;
        int i = 0;
        int prev = 0;
        while (income || i < brackets.size() && income >= (brackets[i][0] - prev))
        {
            tax += (brackets[i][0] - prev) * brackets[i][1];
            income -= brackets[i][0] - prev;
            prev = brackets[i][0];
            i++;
        }
        return tax;
    }
};

int main()
{
    Solution sol;
    int income;
    vector<vector<int>> brackets;
    read2D_Vector(brackets);

    cin >> income;
    cout << sol.calculateTax(brackets, income);
}