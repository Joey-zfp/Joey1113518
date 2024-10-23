#include <iostream>
#include <stack>
using namespace std;

void insertBottom(stack<int>& s, int element) {
    if (s.empty()) {
        s.push(element);
    }
    else {
        int topElement = s.top();
        s.pop();
        insertBottom(s, element);
        s.push(topElement);
    }
}

void reverseStack(stack<int>& s) {
    if (!s.empty()) {
        int topElement = s.top();
        s.pop();
        reverseStack(s);
        insertBottom(s, topElement);
    }
}

int main() {
    stack<int> s;
    s.push(28);
    s.push(29);
    s.push(30);
    s.push(31);

    cout << "Stack before reverse: ";
    stack<int> temp = s;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    reverseStack(s);

    cout << "Stack after reverse: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
