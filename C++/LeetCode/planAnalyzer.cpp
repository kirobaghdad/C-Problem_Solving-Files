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

int main()
{
    multimap<int, string> arr;
    string temp;
    string str;
    int in;

    getline(cin, temp);
    while (temp != "-1")
    {
        getline(cin, str);
        in = stoi(str);
        arr.insert(pair<int, string>(in, temp));
        getline(cin, temp);
    }

    for (auto it = --arr.end(); arr.begin() != it; it--)
        cout << "- " << it->second << "   " << it->first << endl;

    cout << "- " << arr.begin()->second << "   " << arr.begin()->first << endl;
    return 0;
}

/*

Summer Plan:
 NU Competition
  100
 Embedded Systems
 100
 Freelancing (Flutter  Web)
    100
 3D Printer
   100
 Projects
 95
 German
 90
 Electronics Youtube
  85
 Using VS Code
     90
 React
 95
 Assembly
     95
 Qt
   95
 Church Project and School Project
     100
 CCNA
      80
 CodeBlocks
   75
 Quantum Computing
  80
 Drone
   75
 Operating System
   70
 Web Browser
      75
 كتاب عن القضية الفلسطينية
     80
 القرية الزكية
  30
 Tabulation Method
    65
 Function Pointer in C
     60
 Complex Analysis
   65
 Problem Solving
  95
 Algorithms Course
   95
 Unreal Game Engine
  80
 My father's Company Website
    85
 قراءة القرآن الكريم
  80
 انهاء العهد القديم من الكتاب المقدس
  80
 DS Course Repo.
  80
 Memoiztion
   50
 Alexandria
   50
 Databases
  50
 Tesla Internships
   40
 Intel Internships
    40
 Linux and UNIX
   40
 TCL/Python
  50
 TypeScript
   40
 Introduction to Algorithms, Cormen
   50
 Game Theory
   50
 Have Fun
     80
 Code Forces
     110
 Discrete Mathematics
     80
 Compiler
  80
 Java
  80
 .NET
    80
 Altium
    80
 .JSON file
     80
 Bike
    0
 Logic Design
  20
 VLSI
 20
 Course Slides
   30
 Slide Share
  30
 How do it know?
   50
 TicTacToe
   80
 Shell
  50
 Angular
   100
 Functional Programming
    50
 Math Competition
     70
 Fortran
     80
 Bakery ALgorithm
   40
 OS
    40
 Shell
  40
 Hacking (Kali Linux)
    50
 Signals
    50
 Mega.io
    50
 Fermat's Last Theorem
  50
 Goldbach's conjecture
    50
 Trie DS
   80
 Hour of Code
   80
 GDWC
  80
 Enigma Machine
   80
 Graphs
   90
 Doctor Who
  50
 Ruby
  50
 Alan Turing (The Enigma)
  80
 Embedded Linux
   100
 Permutation Graph
  90
 Global stats
    20
 God Father
   50
 Android
  50
 Notion
   80
 typeform
  40
 Catalan Conjecture
   50
 Brilliant
  80
 Quartz Watches
   20
 Photonics
   30
 SVG
 20
 Laser Cutter
   40
 CodeForces API
  40
 Fourier Analysis
   50
 Watch our (home) movie:
    50
  Trillions of Questions, No Easy Answers
     80
 Hamming Code
  70
 Bash
 80
 Haskell
    70
 Access
    80
 IGBT
  30
 The C programming language (Book)
   100
 UNIX
  60
 Interpreter and Compiler
  60
 OpenCV
 60
 Chromium
   60
 ReactOS
  70
 Android Source
    40
 Social Dilemma
   80






-  Code Forces   110
-  Angular   100
-  Embedded Linux   100
-  3D Printer   100
-  Freelancing (Flutter  Web)   100
-  Embedded Systems   100
-  Qt   95
-  Problem Solving   95
-  Church Project and School Project   100
-  Assembly   95
-  The C programming language (Book)   100
-  NU Competition   100
-  Algorithms Course   95
-  React   95
-  Projects   95
-  Permutation Graph   90
-  Graphs   90
-  Using VS Code   90
-  German   90


*/