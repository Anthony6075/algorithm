#include <iostream>
#include <vector>
using namespace std;

void quicksort(vector<int>& nums, int left, int right) {
    int mid = nums[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (nums[i] < mid) ++i;
        while (nums[j] > mid) --j;
        if (i <= j) {
            swap(nums[i], nums[j]);
            ++i;
            --j;
        }
    }
    if (left < j) quicksort(nums, left, j);
    if (right > i) quicksort(nums, i, right);
}

int main() {
    vector<int> v {0, 2, 4, 6, 8, 9, 7, 5, 3, 1};
    quicksort(v, 0, v.size() - 1);
    for (auto e : v) {
        cout << e << " ";
    }
    cout << endl;
}