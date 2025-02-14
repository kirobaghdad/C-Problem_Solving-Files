#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class ProductOfNumbers
{
public:
    vector<int> nums;
    int lastZero = -1;

    ProductOfNumbers()
    {
        nums.push_back(1);
    }

    void add(int num)
    {
        if (!num)
        {
            lastZero = nums.size() - 1;
            nums.push_back(1);
        }

        else if (nums[nums.size() - 1])
            nums.push_back(nums[nums.size() - 1] * num);
        else
        {
            nums.push_back(num);
        }
    }

    int getProduct(int k)
    {
        if (lastZero == -1 || nums.size() - k - 1 > lastZero)
            return nums[nums.size() - 1] / nums[nums.size() - k - 1];
        return 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ProductOfNumbers *productOfNumbers = new ProductOfNumbers();
    productOfNumbers->add(1);                        // [3]
    cout << productOfNumbers->getProduct(1) << endl; // return 20. The product of the last 2 numbers is 5 * 4 = 20

    // productOfNumbers->add(0);                        // [3,0]
    // productOfNumbers->add(2);                        // [3,0,2]
    // productOfNumbers->add(5);                        // [3,0,2,5]
    // productOfNumbers->add(4);                        // [3,0,2,5,4]
    // cout << productOfNumbers->getProduct(2) << endl; // return 20. The product of the last 2 numbers is 5 * 4 = 20
    // cout << productOfNumbers->getProduct(3) << endl; // return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
    // cout << productOfNumbers->getProduct(4) << endl; // return 0. The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
    // productOfNumbers->add(8);                        // [3,0,2,5,4,8]
    // cout << productOfNumbers->getProduct(2) << endl; // return 32. The product of the last 2 numbers is 4 * 8 = 32

    return 0;
}