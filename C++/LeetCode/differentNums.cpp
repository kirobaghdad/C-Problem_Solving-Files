#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numDifferentIntegers(string word)
    {
        // O(n)

        set<string> nums;

        for (int i = 0; i < word.size(); i++)
        {
            int j = i;
            while (j < word.size() && isdigit(word[j]))
            {
                j++;
            }

            if (i != j)
            {
                string temp = word.substr(i, j - i);

                // Remove leading zeros

                int k = 0;

                while (k < temp.size() && temp[k] == '0')
                    k++;

                temp.erase(0, k);

                nums.insert(temp);

                i = j - 1;
            }
        }

        return nums.size();
    }
};

int main()
{

    Solution s;

    cout << s.numDifferentIntegers("a1b01c00");

    return 0;
}