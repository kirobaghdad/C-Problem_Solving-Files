#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    long long atLeastK(string &word, int k)
    {
        int n = word.size();
        long long ans = 0;
        int consonants = 0;
        int left = 0;
        unordered_map<char, int> vowel_map;

        for (int right = 0; right < n; right++)
        {
            if (isVowel(word[right]))
            {
                vowel_map[word[right]]++;
            }
            else
            {
                consonants++;
            }

            while (vowel_map.size() == 5 && consonants >= k)
            {
                ans += n - right;
                if (isVowel(word[left]))
                {
                    vowel_map[word[left]]--;
                    if (vowel_map[word[left]] == 0)
                    {
                        vowel_map.erase(word[left]);
                    }
                }
                else
                {
                    consonants--;
                }
                left++;
            }
        }
        return ans;
    }

    long long countOfSubstrings(string word, int k)
    {
        return atLeastK(word, k) - atLeastK(word, k + 1);
    }
};

// class Solution

// {
//     static bool isVowel(char c)
//     {
//         return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
//     }

// public:
//     long long countOfSubstrings(string word, int k)
//     {
//         ios::sync_with_stdio(false);
//         cin.tie(nullptr);
//         cout.tie(nullptr);
//         long long ans = 0;
//         int cons = 0;

//         map<int, int> v;

//         int j = 0;

//         for (int i = 0; i < word.size(); i++)
//         {
//             int tot1 = 0, tot2 = 0;
//             if (isVowel(word[i]))
//             {
//                 v[word[i]]++;
//             }
//             else
//             {
//                 cons++;
//             }

//             if (v.size() == 5 && cons == k)
//             {

//                 tot1++;
//                 int h = i + 1;

//                 while (h < word.size() && isVowel(word[h]))
//                 {
//                     h++;
//                     tot1++;
//                 }

//                 do
//                 {
//                     if (isVowel(word[j]))
//                     {
//                         if (v.size() == 5)
//                             tot2++;

//                         v[word[j]]--;

//                         if (!v[word[j]])
//                             v.erase(word[j]);
//                     }
//                     else
//                     {
//                         cons--;
//                     }
//                     j++;

//                 } while (j < word.size() && v.size() == 5 && cons == k);
//             }

//             if (cons > k)
//             {
//                 v.clear();

//                 if (k == 0)
//                 {
//                     cons = 0;
//                     j = i + 1;
//                 }
//                 else
//                 {
//                     cons = 1;
//                     j = i;
//                 }
//             }

//             if (tot1 && tot2)
//                 ans += tot1 * tot2;
//             else if (tot1)
//                 ans += tot1;
//             else if (tot2)
//                 ans += tot2;
//         }

//         return ans;
//     }
// };

int main()
{
    Solution s;

    cout << s.countOfSubstrings("ieaouqqieaouqq", 1);

    return 0;
}