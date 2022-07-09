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

bool SpecialChar(char x)
{
    string eg = "!@#$%^&*()-+";
    if (eg.find(x) != -1)
        return true;
    else
        return false;
}

class Solution
{
public:
    bool strongPasswordCheckerII(string str)
    {
        bool lowCase = false;
        bool upperCase = false;
        bool digit = false;
        bool specialChar = false;

        if (str.length() < 8)
            return false;

        for (int i = 0; i < str.length(); i++)
        {
            if (i + 1 < str.length() && str[i] == str[i + 1])
                return false;
            else
            {
                if (str[i] > 64 && str[i] < 91)
                    upperCase = true;
                else if (str[i] > 96 && str[i] < 123)
                    lowCase = true;
                else if (str[i] > 47 && str[i] < 58)
                    digit = true;
                else if (SpecialChar(str[i]))
                    specialChar = true;
            }
        }
        return lowCase && upperCase && digit && specialChar;
    }
};

int main()
{
    Solution sol;
    cout << sol.strongPasswordCheckerII("IloveLe3tcode!") << endl;
    cout << sol.strongPasswordCheckerII("Me+You--IsMyDream") << endl;
    cout << sol.strongPasswordCheckerII("1aB!") << endl;
}

/*

Summer Plan:
- NU Competition
- Embedded Systems
- Freelancing (Flutter - Web)
- 3D Printer
- Projects
- The C programming language (Book)
- Using VS Code
- Assembly
- Problem Solving
- German
- React
- Angular
- Church Project and School Project
- انهاء العهد القديم من الكتاب المقدس
- Electronics Youtube
- Qt
- Tic-Tac-Toe
- CCNA
- CodeBlocks
- Quantum Computing
- Algorithms Course
- Operating System
- Web Browser
- كتاب عن القضية الفلسطينية
- القرية الزكية
- Tabulation Method
- Function Pointer in C
- Complex Analysis
- Unreal Game Engine
- My father's Company Website
- قراءة القرآن الكريم
- DS Course Repo.
- Memoiztion
- Alexandria
- Databases
- Tesla Internships
- Intel Internships
- Linux and UNIX
- TCL/Python
- TypeScript
- Introduction to Algorithms, Cormen
- Game Theory
- Have Fun
- Code Forces
- Discrete Mathematics
- Compiler
- Java
- .NET
- Altium
- .JSON file
- Bike
- Logic Design
- General Motors Internship
- VLSI
- Course Slides
- Slide Share
- How do it know?
- Shell
- Functional Programming
- Math Competition
- Graphs
- Bakery ALgorithm
- Drone
- Fortran
- OS
- Shell
- Hacking (Kali Linux)
- Signals
- Mega.io
- Fermat's Last Theorem
- Goldbach's conjecture
- Trie DS
- Hour of Code
- GDWC
- Enigma Machine
- Doctor Who
- Ruby
- Alan Turing (The Enigma)
- Embedded Linux
- Permutation Graph
- Global stats
- God Father
- Android
- Notion
- typeform
- Catalan Conjecture
- Quartz Watches
- Photonics
- SVG
- Laser Cutter
- Watch our (home) movie:
- Hamming Code
- Bash
- CodeForces API
- Brilliant
  Trillions of Questions, No Easy Answers
- Haskell
- Access
- IGBT
- UNIX
- Interpreter and Compiler
- OpenCV
- Chromium
- ReactOS
- Android Source
- Social Dilemma
- Fourier Analysis

*/