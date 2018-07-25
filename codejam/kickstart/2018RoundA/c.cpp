/*
Problem
Professor Scrmable noticed spelling mistakes in a research paper she was
reviewing, but she had no difficulty in reading or understanding the words. Upon
doing some research, she found an interesting article as described below:

According to a study at an English University, it doesn't matter in what order
the letters in a word are, the only important thing is that the first and last
letter be at the correct place. The rest can be a total mess and you can still
read it without a problem. This is because the human mind does not read every
letter by itself but the word as a whole.

Or rather ...

Aoccdrnig to a study at an Elingsh uinervtisy, it deosn't mttaer in waht oredr
the ltteers in a wrod are, the olny iprmoetnt tihng is taht the frist and lsat
ltteer be at the corecrt pclae. The rset can be a toatl mses and you can sitll
raed it wouthit a porbelm. Tihs is bcuseae the huamn mnid deos not raed ervey
lteter by istlef, but the wrod as a wlohe.

Professor Scrmable wants to explore this concept further and starts compiling
different sentences containing similarly scrambled words to send to a popular
publication. Unfortunately, the space key on the professor's keyboard is not
working, so she has produced one long string of characters. She has asked you to
determine how many of the words in her dictionary appear (at least once) as
substrings in the long string of characters, either in their original or
scrambled forms. (A scrambled form consists of the same set of letters with the
first and last letters in the same places, and the others in any order.)

Note that a dictionary word can appear multiple times in the string (though it
should be counted only once since we only need to know whether it shows up at
least once). For example, if we had the word this in the dictionary, the
possible valid words which would be counted are this (original version) and tihs
(scrambled version), whereas tsih, siht and other variations are not valid since
they do not start with t and end with s. Also, tis, tiss, and thiss are not
scrambled forms, because they are not reorderings of the original set of
letters.

Since the professor is extremely busy, she gives this task to you, her favorite
and most trusted research assistant. Given a dictionary, can you count the
number of words in the dictionary that appear as a substring in the professor's
string at least once, in either their scrambled or original forms.

Input
The first line of the input gives the number of test cases, T. T test cases
follow. Each testcase contains three lines. The first line contains an integer
L. The second line contains a list of L words made of lowercase English letters;
these make up the dictionary. The third line contains two lowercase English
letters S1 and S2, and five integers N, A, B, C and D. S1 and S2 are the first
two characters of the professor's string S, N is the length of S, and the other
four integers are parameters that you should use to generate the characters of
S, as follows:

First we define ord(c) as the decimal value of a character c and char(n) as the
character value of a decimal n. For example, ord('a') = 97 and char(97) = 'a'.
You can refer to ASCII table for other conversions.

Now, define x1 = ord(S1), x2 = ord(S2). Then, use the recurrence below to
generate xi for i = 3 to N:

xi = ( A * xi-1 + B * xi-2 + C ) modulo D.
We define Si = char(97 + ( xi modulo 26 )), for all i = 3 to N.
Output
For each test case, output one line containing Case #x: y, where x is the test
case number (starting from 1) and y is the number of words from the dictionary
that appear (in their original or scrambled forms, as defined above) as
substrings of the given string.

Limits
1 ≤ T ≤ 20.
No two words in the dictionary are the same.
Each word in the dictionary is between 2 and 105 letters long, inclusive.
The sum of lengths of all words in the dictionary does not exceed 105.
S1 and S2 are lowercase English letters.
0 ≤ A ≤ 109.
0 ≤ B ≤ 109.
0 ≤ C ≤ 109.
1 ≤ D ≤ 109.
Small dataset
1 ≤ L ≤ 1000.
2 ≤ N ≤ 1000.
Large dataset
1 ≤ L ≤ 20000.
2 ≤ N ≤ 106.
Sample

Input

Output

1
5
axpaj apxaj dnrbt pjxdn abd
a a 50 1 1 1 30

Case #1: 4

In Sample Case #1, using the generation method, the generated string S is
aapxjdnrbtvldptfzbbdbbzxtndrvjblnzjfpvhdhhpxjdnrbt. Scrambled or original
occurences of dictionary words are highlighted as follows: axpaj occurs in its
scrambled form as aapxjdnrbtvldptfzbbdbbzxtndrvjblnzjfpvhdhhpxjdnrbt. apxaj
occurs in its scrambled form as
aapxjdnrbtvldptfzbbdbbzxtndrvjblnzjfpvhdhhpxjdnrbt. Note that even though apxaj
is the scrambled form of another dictionary word axpaj, both should be counted.
dnrbt occurs twice in its original form as
aapxjdnrbtvldptfzbbdbbzxtndrvjblnzjfpvhdhhpxjdnrbt, though it should be counted
only once. pjxdn occurs in its scrambled form as
aapxjdnrbtvldptfzbbdbbzxtndrvjblnzjfpvhdhhpxjdnrbt. Note this occurence overlaps
with occurence of another dictionary word, but still they're counted
independently. abd doesn't occur at all. Note: We do not recommend using
interpreted/slower languages for the Large dataset of this problem.
*/

#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string.h>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef long double ld;

// Small AC
// Large TLE

void solution() {
    int L;
    cin >> L;
    vector<pair<vi, vi>> dict(L);
    char s[100000]; // input string
    for (int i = 0; i < L; ++i) {
        cin >> s;
        // cout << s << endl;
        vi cot(26);
        for (int k = strlen(s) - 2; k > 0; --k)
            ++cot[s[k] - 'a'];
        dict[i] = {{s[0] - 97, s[strlen(s) - 1] - 97, (int)strlen(s)}, cot};
    }

    char s1, s2;
    int N, A, B, C, D;
    cin >> s1 >> s2 >> N >> A >> B >> C >> D;
    // cout << endl;
    // cout << s1 << s2 << N << A << B << C << D << endl;
    vector<pair<int, vi>> sentence(N + 1);
    vi word(26);
    sentence[0] = {0, vi(26)};

    vvi idx(26);
    int w;
    long long x1 = s1, x2 = s2;
    for (int i = 1; i <= N; ++i) {
        if (i == 1)
            w = s1 - 97;
        else if (i == 2)
            w = s2 - 97;
        else {
            long long temp = x2;
            x2 = ((A * x2 % D + B * x1 % D) % D + C % D) % D;
            x1 = temp;
            w = x2 % 26;
        }
        // cout << (char)(w + 97);
        ++word[w];
        idx[w].push_back(i);
        sentence[i] = {w, vi(word)};
    }
    // cout << endl;
    int ret = 0;
    for (auto word : dict) {
        for (int i : idx[word.first[0]]) {

            if (i - 1 + word.first[2] <= N &&
                sentence[i - 1 + word.first[2]].first == word.first[1]) {
                int j = 0;
                for (; j < 26; ++j) {
                    if (word.second[j] !=
                        sentence[i - 2 + word.first[2]].second[j] -
                            sentence[i].second[j])
                        break;
                }
                if (j == 26) {
                    ++ret;
                    break;
                }
            }
        }
    }
    cout << ret;
}

int main() {
    int t;
    cin >> t; // read t. cin knows that t is an int, so it reads it as such.
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solution();
        cout << endl;
    }

    return 0;
}
/*
C++:
gcc 6.3.0 (packages: gcc, g++)


g++ c.cpp -std=c++14 -pthread -O3 -o Solution
./Solution < c-test.in > ct.out
./Solution < C-small-practice.in > cs.out
./Solution < C-large-practice.in > cl.out

*/
