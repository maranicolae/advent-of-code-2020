#include <bits/stdc++.h>

using namespace std;

void valid_password(ifstream& in, int& cnt) {
    unordered_map<char, int> um;
    int min_count, max_count;
    char chr, c;
    string password;

    in >> min_count >> c >> max_count >> chr >> c;
    in >> password;
    

    for (auto& p : password) {
        if (um.find(p) == um.end()) {
            um[p] = 1;
        } else {
            um[p]++;
        }
    }

    if (um.find(chr) != um.end() && um[chr] >= min_count 
        && um[chr] <= max_count) {
        cnt++;
    }    
}

void valid_password2(ifstream& in, int& cnt) {
    int first_pos, second_pos;
    char chr, c;
    string password;
    
    in >> first_pos >> c >> second_pos >> chr >> c;
    in >> password;


    if (first_pos <= password.size() && second_pos <= password.size()) {
        if ((password[first_pos - 1] == chr || password[second_pos - 1] == chr) 
            && password[first_pos - 1] != password[second_pos - 1]) {
            cnt++;
        }
    }
}

int main() {
    ifstream in;
    in.open("day2.in");
    int cnt = 0;

    while(!in.eof()) {
        valid_password2(in, cnt);
    }

    std::cout << cnt << "\n";
    in.close();
}
