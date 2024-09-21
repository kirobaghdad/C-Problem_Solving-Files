// C++ code for the above approach:
#include <bits/stdc++.h>
using namespace std;

// Function to solve Increasing
// Monotonic queue
deque<int> increasing_monotonic_queue(int arr[], int n)
{

    deque<int> q;
    for (int i = 0; i < n; i++)
    {

        // If recently added element is
        // greater current element
        while (!q.empty() && q.back() > arr[i])
        {

            q.pop_back();
        }

        q.push_back(arr[i]);
    }

    return q;
}

// Driver code
int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function call
    deque<int> q = increasing_monotonic_queue(arr, n);

    for (int i : q)
    {
        cout << i << " ";
    }
    return 0;
}
