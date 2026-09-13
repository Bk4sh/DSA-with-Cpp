#include <iostream>
#include <stack>
using namespace std;

bool isValid(string str) {
    stack<char> s;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            s.push(str[i]);
        } else {
            if (s.size() == 0) {    //closing > openning
                return false;
            }

            if (s.top() == '(' && str[i] == ')' || s.top() == '{' && str[i] == '}' || s.top() == '[' && str[i] == ']') {
                s.pop();
            } else {
                return false;
            }
        }
    }

    return s.size() == 0; //openning > closing
}

int main() {
    string str = "({[]})";
    cout << isValid(str) << endl;

    return 0;
}