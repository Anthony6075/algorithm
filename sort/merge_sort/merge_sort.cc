#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& v, vector<int>& temp, int left_pos, int right_pos, int right_end) {
    int num = right_end - left_pos + 1;
    int temp_pos = left_pos;
    int left_end = right_pos - 1;
    while (left_pos <= left_end && right_pos <= right_end) {
        if (v[left_pos] <= v[right_pos]) {
            temp[temp_pos++] = v[left_pos++];
        } else {
            temp[temp_pos++] = v[right_pos++];
        }
    }
    while (left_pos <= left_end) {
        temp[temp_pos++] = v[left_pos++];
    }
    while (right_pos <= right_end) {
        temp[temp_pos++] = v[right_pos++];
    }
    for (int i = right_end - num + 1; i <= right_end; ++i) {
        v[i] = temp[i];
    }
}

void merge_sort(vector<int>& v, vector<int>& temp, int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;
        merge_sort(v, temp, left, middle);
        merge_sort(v, temp, middle + 1, right);
        merge(v, temp, left, middle + 1, right);
    }
}

int main() {
    vector<int> v {0, 2, 4, 6, 8, 9, 7, 5, 3, 1};
    vector<int> temp (v.size());
    merge_sort(v, temp, 0, v.size() - 1);
    for (auto e : v) {
        cout << e << " ";
    }
    cout << endl;
}