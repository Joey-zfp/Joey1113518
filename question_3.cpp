#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void printFirstNegInt(vector<int>& arr, int k) {
    int n = arr.size();
    queue<int> negative;

    for (int i = 0; i < n; i++) {
        if (!negative.empty() && negative.front() < i - k + 1) {
            negative.pop();
        }

        if (arr[i] < 0) {
            negative.push(i);
        }

        if (i >= k - 1) {
            if (!negative.empty()) {
                cout << arr[negative.front()] << " ";
            }
            else {
                cout << "0 ";
            }
        }
    }
    cout << endl;
}

int main() {
    vector<int> arr = { -8, 2, 3, -6, 10 };
    int k = 2;

    cout << "First negative integers for each window of size " << k << ": ";
    printFirstNegInt(arr, k);

    return 0;
}
