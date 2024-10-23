#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void printGreaterElm(vector<int> arr) {
    int n = arr.size();
    vector<int> greaterElm(n, -1);  
    stack<int> stk;

    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && stk.top() <= arr[i]) {
            stk.pop();
        }
        if (!stk.empty()) {
            greaterElm[i] = stk.top();
        }
        stk.push(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " -> " << greaterElm[i] << endl;
    }
}

int main() {
    vector<int> arr = { 4, 5, 2, 25 };
    printGreaterElm(arr);
    return 0;
}
