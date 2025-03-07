#include <bits/stdc++.h>

std::vector<std::pair<int,std::string>> vec;

int main() {
    std::string s;
    while(getline(std::cin, s)) {
        if(s!="end") {
            std::stringstream ss;
            int hlp1;
            std::string hlp2;
            ss >> hlp1;
            ss >> hlp2;
            vec.emplace_back(hlp1,hlp2);
        }
        else {
            break;
        }
    }


    int k,t;
    std::cin>>k>>t;

    int start = 0;
    int sum = 0;
    bool chain = true;

    int i = 1;
    for(const auto& u: vec) {
        if(u.second=="Gold") {
            if(!chain) {
                    start = i;
                    sum = u.first;
                    chain = true;
            }
            else {
                sum += u.first;
            }
        }
        else if(chain) {
            if(sum == t) {
                std::cout<<start<<std::endl;
            }
            chain = false;
        }
        i++;
    }
}