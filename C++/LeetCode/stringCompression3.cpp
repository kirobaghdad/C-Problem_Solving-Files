#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string compressedString(string word)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        string comp = "";

        char last = ' ';
        int count = 0;

        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] != last)
            {
                if (count)
                {
                    comp += to_string(count) + last;
                }

                last = word[i];
                count = 1;
            }
            else
            {
                count++;

                if (count == 9)
                {
                    comp += to_string(count) + last;
                    count = 0;
                    last = ' ';
                }
            }
        }

        if (count)
            comp += to_string(count) + last;

        return comp;
    }
};

int main()
{

    return 0;
}