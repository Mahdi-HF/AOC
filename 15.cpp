#include <bits/stdc++.h>
using namespace std;
#define int long long

int vec[30000005];
unordered_map<int, int> isSeen;

int32_t main() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int ii = 0;
    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        int val = stoi(substr);
        vec[ii] = val;
        if (ii > 0) isSeen[vec[ii - 1]] = ii;
        ii++;
    }
    for (int i = ii; i < 30000005; i++) {
        if (isSeen[vec[i - 1]] == 0) {
            vec[i] = 0;
            isSeen[vec[i - 1]] = i;
        } else {
            vec[i] = i - isSeen[vec[i - 1]];
            isSeen[vec[i - 1]] = i;
        }
    }
    cout << vec[2019] << endl;
    cout << vec[29999999] << endl;
}