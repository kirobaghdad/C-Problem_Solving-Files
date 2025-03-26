#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkValidCuts(int n, vector<vector<int>> rec)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        // sort
        sort(rec.begin(), rec.end(), [](vector<int> &a, vector<int> &b)
             { return a[0] < b[0]; });

        int endLine = rec[0][2];
        bool check = 0;

        // check vertical cuts
        for (int i = 0; i < rec.size(); i++)
        {

            if (rec[i][0] >= endLine)
            {
                if (!check)
                {
                    check = true;
                }
                else
                    return true;
            }

            endLine = max(endLine, rec[i][2]);
        }

        sort(rec.begin(), rec.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });

        endLine = rec[0][3];

        check = 0;

        // check horizontal cuts
        for (int i = 0; i < rec.size(); i++)
        {
            if (rec[i][1] >= endLine)
            {
                if (!check)
                {
                    check = true;
                }
                else
                    return true;
            }

            endLine = max(endLine, rec[i][3]);
        }

        return false;
    }
};

int main()
{
    Solution s;

    cout << s.checkValidCuts(1000000000, {{681349876, 0, 712926801, 534476204}, {290870720, 884292556, 312498043, 1000000000}, {479767687, 889285693, 537634991, 1000000000}, {867028333, 551242279, 907769660, 558100125}, {113211417, 651417577, 152274374, 884272767}, {348130025, 738415577, 375895192, 884292556}, {853011409, 0, 894230265, 232018238}, {889871811, 692929397, 925081240, 906304820}, {0, 304310748, 79326087, 566988415}, {33614188, 855641317, 78838510, 1000000000}, {166195555, 884292556, 263722924, 981931794}, {841560849, 906304820, 880461961, 1000000000}, {255337303, 566988415, 316059548, 651417577}, {730037246, 835593048, 768355314, 1000000000}, {856356021, 692929397, 889871811, 906304820}, {792940227, 538123842, 822890232, 835593048}, {907769660, 266791352, 920615349, 558100125}, {358261176, 304310748, 384419068, 498028147}, {393036549, 738415577, 438478430, 884292556}, {909755882, 906304820, 1000000000, 1000000000}, {952891444, 266791352, 970471452, 558100125}, {634302816, 793297783, 656664400, 1000000000}, {367815420, 884292556, 438478430, 1000000000}, {256480847, 304310748, 321237549, 498028147}, {920615349, 266791352, 930183400, 558100125}, {856356021, 558100125, 925081240, 692929397}, {971693240, 0, 1000000000, 251401513}, {323895793, 884292556, 367815420, 1000000000}, {403689562, 304310748, 438478430, 498028147}, {79326087, 460366605, 138001006, 566988415}, {822890232, 558100125, 856356021, 906304820}, {930183400, 266791352, 936122918, 558100125}, {78838510, 992164570, 166195555, 1000000000}, {0, 855641317, 33614188, 1000000000}, {375895192, 738415577, 393036549, 884292556}, {937048071, 0, 941312425, 251401513}, {950645831, 558100125, 954235973, 906304820}, {366944341, 566988415, 438478430, 651417577}, {695653014, 534476204, 712926801, 1000000000}, {712926801, 0, 853011409, 266791352}, {256480847, 498028147, 438478430, 530703606}, {138001006, 530703606, 157767173, 566988415}, {438478430, 0, 681349876, 793297783}, {853011409, 232018238, 894230265, 266791352}, {936122918, 266791352, 952891444, 558100125}, {205969595, 738415577, 257049618, 884292556}, {438478430, 889285693, 479767687, 1000000000}, {880461961, 906304820, 909755882, 1000000000}, {894230265, 251401513, 1000000000, 266791352}, {822890232, 266791352, 867028333, 558100125}, {384419068, 304310748, 403689562, 498028147}, {958831941, 0, 971693240, 251401513}, {166195555, 981931794, 263722924, 1000000000}, {78838510, 884292556, 166195555, 992164570}, {537634991, 793297783, 605779185, 948884409}, {925081240, 558100125, 950645831, 906304820}, {79326087, 304310748, 138001006, 460366605}, {693001454, 534476204, 695653014, 1000000000}, {771079573, 538123842, 775372290, 835593048}, {268773526, 738415577, 302892489, 884292556}, {302892489, 738415577, 348130025, 884292556}, {157767173, 530703606, 278949783, 566988415}, {278949783, 530703606, 438478430, 566988415}, {681349876, 534476204, 693001454, 1000000000}, {656664400, 793297783, 681349876, 1000000000}, {312498043, 884292556, 323895793, 1000000000}, {867028333, 266791352, 907769660, 551242279}, {321237549, 304310748, 358261176, 498028147}, {537634991, 948884409, 605779185, 1000000000}, {712926801, 538123842, 728433330, 1000000000}, {316059548, 566988415, 366944341, 651417577}, {975848054, 558100125, 1000000000, 906304820}, {78838510, 566988415, 113211417, 884292556}, {438478430, 793297783, 537634991, 889285693}, {822890232, 906304820, 841560849, 1000000000}, {257049618, 738415577, 268773526, 884292556}, {941312425, 0, 958831941, 251401513}, {188516253, 304310748, 256480847, 505016752}, {152274374, 738415577, 205969595, 884292556}, {0, 566988415, 78838510, 855641317}, {712926801, 266791352, 822890232, 538123842}, {894230265, 0, 937048071, 251401513}, {0, 0, 438478430, 304310748}, {954235973, 558100125, 975848054, 906304820}, {775372290, 538123842, 778245950, 835593048}, {768355314, 835593048, 822890232, 1000000000}, {263722924, 884292556, 290870720, 1000000000}, {152274374, 651417577, 294881794, 738415577}, {778245950, 538123842, 792940227, 835593048}, {113211417, 566988415, 255337303, 651417577}, {728433330, 538123842, 771079573, 835593048}, {294881794, 651417577, 334894018, 738415577}, {334894018, 651417577, 438478430, 738415577}, {188516253, 505016752, 256480847, 530703606}, {113211417, 884272767, 152274374, 884292556}, {970471452, 266791352, 1000000000, 558100125}, {605779185, 793297783, 634302816, 1000000000}, {728433330, 835593048, 730037246, 1000000000}, {138001006, 304310748, 188516253, 530703606}});

    // cout << s.checkValidCuts(4, {{0, 2, 2, 4}, {1, 0, 3, 2}, {2, 2, 3, 4}, {3, 0, 4, 2}, {3, 2, 4, 4}}) << endl;
    // cout << s.checkValidCuts(4, {{0, 0, 1, 1}, {2, 0, 3, 4}, {0, 2, 2, 3}, {3, 0, 4, 3}}) << endl;

    return 0;
}