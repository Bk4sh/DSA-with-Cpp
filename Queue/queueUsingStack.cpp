#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStack {
    public:
        stack<int> s1;
        stack<int> s2;

        void push(int data) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }

            s1.push(data);

            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }

        int pop() {
            int ans = s1.top();
            s1.pop();
            return ans;
        }

        int front() {
            return s1.top();
        }

        bool empty() {
            return s1.empty();
        }
};

int main() {
    QueueUsingStack qs;

    qs.push(1);
    qs.push(2);
    qs.push(3);
    qs.push(4);

    qs.pop();

    while (!qs.empty()) {
        cout << qs.front() << " ";
        qs.pop();
    }
    cout << endl;

    return 0;
}