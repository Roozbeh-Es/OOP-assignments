#include <bits/stdc++.h>


int main() {
    std::vector<std::pair<int, std::string> > vec;

    std::string s;
    while (getline(std::cin, s)) {
        if (s != "end") {
            std::stringstream ss(s);
            int hlp1;
            std::string hlp2;
            ss >> hlp1 >> hlp2;
            vec.emplace_back(hlp1, hlp2);
        } else {
            break;
        }
    }


    int k, t;
    std::cin >> k >> t;

    int start = 0;
    int sum = 0;
    bool ans = false;

    for (int i = 0; i < vec.size(); i++) {
        if (ans)
            break;
        if (vec[i].second == "Gold") {
            bool prob = false;
            start = i + 1;
            sum = vec[i].first;
            for (int j = 1; j <= k; j++) {
                if (vec[i + j].second == "Gold") {
                    sum += vec[i + j].first;
                } else {
                    prob = true;
                    break;
                }
            }
            if (sum == t && !prob) {
                ans = true;
                std::cout << start << std::endl;
                break;
            }
        }
    }
    if (!ans) {
        int min = INT_MAX;
        for (int i = 0; i < vec.size(); i++) {
            int hlp = vec[i].first;
            for (int j = 1; j <= k; j++) {
                hlp += vec[i + j].first;
            }
            if (hlp < min) {
                min = hlp;
                start = i + 1;
            }
        }
        std::cout << start << std::endl;
    }
}
