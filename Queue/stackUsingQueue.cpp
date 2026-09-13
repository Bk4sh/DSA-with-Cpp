#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueue {
    public:
        queue<int> q1;
        queue<int> q2;

        void push(int data) {
            while (!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }

            q1.push(data);

            while (!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }

        int pop() {
            int ans = q1.front();
            q1.pop();
            return ans;
        }

        int top() {
            return q1.front();
        }

        bool empty() {
            return q1.empty();
        }
};

int main() {
    StackUsingQueue sq;

    sq.push(1);
    sq.push(2);
    sq.push(3);
    sq.push(4);

    sq.pop();

    while (!sq.empty()) {
        cout << sq.top() << " ";
        sq.pop();
    }
    cout << endl;

    return 0;
}