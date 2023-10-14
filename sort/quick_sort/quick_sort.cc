#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& nums, int left, int right) {
    int r = rand() % (right - left) + left;
    swap(nums[r], nums[right]);

    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (nums[j] <= nums[right]) {
            ++i;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[right]);
    return i + 1;
}

void quicksort(vector<int>& nums, int left, int right) {
    if (left < right) {
        int p = partition(nums, left, right);
        quicksort(nums, left, p - 1);
        quicksort(nums, p + 1, right);
    }
}

int main() {
    vector<int> v {0, 2, 4, 6, 8, 9, 7, 5, 3, 1};
    quicksort(v, 0, v.size() - 1);
    for (auto e : v) {
        cout << e << " ";
    }
    cout << endl;
}