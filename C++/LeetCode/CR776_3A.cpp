#include <iostream>
#include <string>
using namespace std;

template <class T>
void printArray(T arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i])
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}
bool canGet(string in, char c)
{
    for (int i = 0; i < in.length(); i++)
    {
        if (in[i] == c)
        {
            if (i % 2 == 0 && (in.length() - i - 1) % 2 == 0)
                return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    string in;
    char c;
    bool *ans = new bool[t];

    for (int i = 0; i < t; i++)
    {
        cin >> in;
        cin >> c;
        ans[i] = canGet(in, c);
    }

    printArray(ans, t);
    delete[] ans;
}