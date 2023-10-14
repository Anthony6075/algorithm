#include <iostream>
#include <vector>
using namespace std;

int lower_bound(const vector<int>& v, int target) {
    int left = 0, right = v.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (v[mid] >= target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    vector<int> v {0, 1, 2, 3, 5, 5, 6, 7, 8, 9};
    cout << lower_bound(v, 5) << endl;
}