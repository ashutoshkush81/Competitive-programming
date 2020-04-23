#! /bin/bash
cd  cp/codeforces
mkdir "$1 $2"
cd "$1 $2"
code -n .
echo "Welcome to Codeforces  $1 $2"
echo "Good Luck and High Rating"
touch 1.cpp
touch 2.cpp
touch 3.cpp
touch 4.cpp
cp ~/test.py .
code 1.cpp
code 2.cpp
code 3.cpp
code 4.cpp
echo "//   https://codeforces.com/contest/$3/problem/A" >>1.cpp
echo "//   https://codeforces.com/contest/$3/problem/B" >>2.cpp
echo "//   https://codeforces.com/contest/$3/problem/C" >>3.cpp
echo "//   https://codeforces.com/contest/$3/problem/D" >>4.cpp
#echo "Welcome to the codeforces"
#echo "Good luck & High rating!"
