#include<iostream>
#include<string>
#include<vector>
using namespace std;

string timeToWord(int H, int M) {
    // code here
    vector<string>cc = { "one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","one"};
    vector<string>cc1 = { "twenty","thirty","forty" };
    vector<string>cc2 = { "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen" };
    if (M == 0) {
        return cc[H-1] + " o'clock";
    }
    else if (M == 15) {
        return "quarter past " + cc[H-1];
    }
    else if (M == 30) {
        return "half past " + cc[H-1];
    }
    else if (M == 45) {
        return "quarter to " + cc[H];
    }
    else {
        if (M == 1) {
            return "one minute past " + cc[H - 1];
        }
        else if (M <= 10) {
            return cc[M - 1] + " minutes past " + cc[H - 1];
        }
        else if (M >= 11 && M < 20) {
            return cc2[M - 11] + " minutes past " + cc[H - 1];
        }
        else if (M >= 20 && M < 30) {
            return cc1[(M / 10) - 2] + "-" + cc[(M % 10) - 1] + " minutes past " + cc[H - 1];
        }
        else {
            M = 60 - M;
            if (M == 1) {
                return "one minute to " + cc[H];
            }
            else if (M <= 10) {
                return cc[M - 1] + " minutes to " + cc[H];
            }
            else if (M >= 11 && M < 20) {
                return cc2[M - 11] + " minutes to " + cc[H];
            }
            else if (M >= 20 && M < 30) {
                return cc1[(M / 10) - 2] + "-" + cc[(M % 10) - 1] + " minutes to " + cc[H];
            }
        }
    }
}           

int main() {
    int h, m;
    cin >> h;
    cin >> m;
    cout << timeToWord(h, m);
}