/*
Problem
Supervin has a unique calculator. This calculator only has a display, a plus
button, and a minus button. Currently, the integer N is displayed on the
calculator display.

Pressing the plus button increases the current number displayed on the
calculator display by 1. Similarly, pressing the minus button decreases the
current number displayed on the calculator display by 1. The calculator does not
display any leading zeros. For example, if 100 is displayed on the calculator
display, pressing the minus button once will cause the calculator to display 99.

Supervin does not like odd digits, because he thinks they are "odd". Therefore,
he wants to display an integer with only even digits in its decimal
representation, using only the calculator buttons. Since the calculator is a bit
old and the buttons are hard to press, he wants to use a minimal number of
button presses.

Please help Supervin to determine the minimum number of button presses to make
the calculator display an integer with no odd digits.

Input
The first line of the input gives the number of test cases, T. T test cases
follow. Each begins with one line containing an integer N: the integer initially
displayed on Supervin's calculator.

Output
For each test case, output one line containing Case #x: y, where x is the test
case number (starting from 1) and y is the minimum number of button presses, as
described above.

Limits
1 ≤ T ≤ 100.
Small dataset
1 ≤ N ≤ 105.
Large dataset
1 ≤ N ≤ 1016.
*/

#include <iostream> // includes cin to read from stdin and cout to write to stdout
#include <vector>
using namespace std; // since cin and cout are both in namespace std, this saves
                     // some text
// Works on small practise, TLE on Large one
// Judge One by One
// bool valid(long n) {
//     while (n > 0) {
//         int a = n % 10;
//         if (a % 2)
//             return false;
//         n /= 10;
//     }
//     return true;
// }
// void solution(long n) {
//     long i = 0;
//     while (1) {
//         if (valid(n + i) || valid(n - i)) {
//             cout << i << endl;
//             return;
//         }
//         ++i;
//     }
// }
vector<int> getNums(long n) {
    vector<int> num;
    while (n > 0) {
        num.push_back(n % 10);
        n /= 10;
    }
    return num;
}
long toInt(vector<int> num) {
    long ret = 0;
    for (int i = num.size() - 1; i >= 0; --i)
        ret = ret * 10 + num[i];
    return ret;
}
// Construct two target by rule.
void solution(long n) {
    vector<int> sm = getNums(n);
    sm.push_back(0);
    vector<int> big(sm);
    bool flag_0 = false, flag_8 = false;
    for (int i = big.size() - 1; i >= 0; --i) {
        if (flag_0)
            big[i] = 0;
        else if (big[i] == 9) {
            flag_0 = true;
            big[i] = 0;
            for (int j = i + 1; j < big.size(); ++j) {
                if (big[j] == 8)
                    big[j] = 0;
                else {
                    big[j] += 2;
                    break;
                }
            }
        } else if (big[i] % 2) {
            big[i] += 1;
            flag_0 = true;
        }
        if (flag_8)
            sm[i] = 8;
        else if (sm[i] % 2) {
            sm[i] -= 1;
            flag_8 = true;
        }
    }
    cout << min(toInt(big) - n, n - toInt(sm)) << endl;
}

int main() {
    int t;
    long n;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> n;
        cout << "Case #" << i << ": ";
        solution(n);
    }

    return 0;
}
