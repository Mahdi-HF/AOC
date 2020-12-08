#include <bits/stdc++.h>

std::vector<std::pair<std::string, int>> vec;
std::set<int> st;
bool hasLoop = false;

void reverseIt(int j){
    if (vec[j].first == "nop")
        vec[j].first = "jmp";
    else if (vec[j].first == "jmp")
        vec[j].first = "nop";
}

int solveIt(){
    int acc = 0;
    hasLoop = false;
    st.clear();
    for (int i = 0; i < vec.size(); i++) {
        if (st.count(i) == 1) {
            hasLoop = true;
            break;
        }
        st.insert(i);
        if (vec[i].first == "acc")
            acc += vec[i].second;
        else if (vec[i].first == "jmp")
            i += vec[i].second - 1;
    }
    return acc;
}

int main() {    
    std::string str;
    int n;
    while (std::cin >> str >> n) vec.push_back({str, n});
    std::cout << solveIt() << std::endl;
    for (int j = 0; j < vec.size(); j++) {
        reverseIt(j);
        int acc = solveIt();
        reverseIt(j);
        if(!hasLoop){
            std::cout << acc << std::endl;
            break;
        }
    }
}