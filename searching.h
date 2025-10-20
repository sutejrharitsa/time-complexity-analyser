#include <bits/stdc++.h>
using namespace std;

void binarySearchDemo(vector<int>& arr, int x) {
    int l = 0, r = arr.size() - 1;
    int comparisons = 0;
    while (l <= r) {
        comparisons++;
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) {
            cout << "Found at index " << mid << " after " << comparisons << " comparisons.\n";
            return;
        }
        if (arr[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    cout << "Not found after " << comparisons << " comparisons.\n";
}
