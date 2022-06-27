////#include <iostream>
////#include <algorithm>
////using namespace std;
////
////class Vehicle {
////private:
////	int test;
////public:
////	Vehicle() {
////		test = 0;
////	}
////
////	virtual int getType() = 0;
////};
////
////class Car :public Vehicle
////{
////	int type;
////public:
////	Car() {
////		type = -1;
////	}
////	int getType() {
////		return type;
////	}
////};
////
////
////int main() {
////	Vehicle* car = new Car();
////	cout << car->getType();
////}
////
////template<class T>
////void printarray(T* arr, int n) {
////	for (int i = 0; i < n; i++)
////	{
////		if (arr[i] == 1)
////			cout << "YES" << endl;
////		else cout <<"NO"<< endl;
////	}
////}
////
////template <class T>
////void readArray(T* arr, int n) {
////	for (int i = 0; i < n; i++)
////		cin >> arr[i];
////}
////                            // 13
//////1 1 3 5 5 6 7 8 8 9 12 12 12 13 13 14
////bool candies(int* arr, int n) {
////	std::sort(arr, arr + n);
////	if (n == 1) {
////		if (arr[0] > 1)
////			return 0;
////		else return 1;
////	}
////
////	if (arr[n - 1] - arr[n - 2] <= 1)
////		return true;
////	else return false;
////}
////
////int main() {
////	int t;
////	cin >> t;
////	bool* ans = new bool[t];
////	int n;
////
////	for (int i = 0; i < t; i++) {
////		cin >> n;
////		int* arr = new int[n];
////		readArray(arr, n);
////		ans[i] = candies(arr, n);
////		delete[]arr;
////	}
////
////	printarray(ans, t);
////
////}
//
//
//#include <iostream>
//using namespace std;
//
//template <class T>
//void printArray(T arr, int n)
//{
//    for (int i = 0; i < n; i++)
//    {
//        cout << arr[i] << endl;
//    }
//}
//
//int minNum(int n)
//{
//    int y = 1;
//    while ((n & y == 0) || (n ^ y == 0))
//    {
//        y++;
//    }
//    return y;
//}
//
//int main()
//{
//    int t;
//    cin >> t;
//    int* ans = new int[t];
//    int n;
//
//    for (int i = 0; i < t; i++)
//    {
//        cin >> n;
//        ans[i] = minNum(n);
//    }
//
//    printArray(ans, t);
//}

#include <iostream>
#include <limits.h>
using namespace std;

template <class T>
void readArray(T arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

template <class T>
void printArray(T arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

int countOdds(int* arr, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 1)
            count++;
    }
    return count;
}

int getMin(int* arr, int n)
{
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

int* getZeros(int* arr, int n)
{
    int* zeros = new int[n] {};
    int x;
    for (int i = 0; i < n; i++)
    {
        x = arr[i] & ~(arr[i] - 1);
        while (x / 2)
        {
            zeros[i]++;
            x /= 2;
        }
        x = 0;
    }
    return zeros;
}

int func(int* arr, int n)
{
    int odds = countOdds(arr, n);
    if (odds)
    {
        return n - odds;
    }
    else
    {
        int* numOfZeros;
        numOfZeros = getZeros(arr, n);
        return getMin(numOfZeros, n) + n - 1;
    }
}

int main()
{
    int t;
    cin >> t;
    int* ans = new int[t];
    int n;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        int* arr = new int[n];
        readArray(arr, n);
        ans[i] = func(arr, n);
        delete[] arr;
    }

    printArray(ans, t);
    delete[] ans;
}
