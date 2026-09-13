#include <iostream>
#include <vector>
using namespace std;

class Stack {
    vector<int> s;

    public:
        void push(int val) {
            s.push_back(val);
        }

        void pop() {
            s.pop_back();
        }

        int top() {
            return s[s.size()-1];
        }

        bool empty() {
            return s.size() == 0;
        }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}