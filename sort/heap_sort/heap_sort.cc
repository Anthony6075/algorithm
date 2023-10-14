#include <iostream>
#include <vector>
using namespace std;

void max_heapify(vector<int>& v, int len, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int maxIndex = index;
    if (left < len && v[left] > v[maxIndex]) {
        maxIndex = left;
    }
    if (right < len && v[right] > v[maxIndex]) {
        maxIndex = right;
    }
    if (maxIndex != index) {
        swap(v[index], v[maxIndex]);
        max_heapify(v, len, maxIndex);
    }
}

void build_max_heap(vector<int>& v, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        max_heapify(v, size, i);
    }
}

vector<int> heap_sort(vector<int>& nums) {
    build_max_heap(nums, nums.size());
    for (int i = nums.size() - 1; i >= 1; i--) {
        swap(nums[0], nums[i]);
        max_heapify(nums, i, 0);
    }
    return nums;
}

int main() {
    vector<int> v {0, 2, 4, 6, 8, 9, 7, 5, 3, 1};
    heap_sort(v);
    for (auto e : v) {
        cout << e << " ";
    }
    cout << endl;
}