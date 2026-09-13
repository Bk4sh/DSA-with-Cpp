#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> m;

    m["tv"] = 100;
    m["laptop"] = 50;
    m["watch"] = 60;
    m["headphones"] = 100;
    m["tablet"] = 50;

    m.insert({"camera", 40});

    for (auto p : m) {
        cout << p.first << " " << p.second << endl;
    }

    if (m.find("camera") != m.end()) {
        cout << "found";
    } else {
        cout << "not found";
    }

    return 0;
}