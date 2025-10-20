#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

// ---------- Sorting Algorithms ----------
void bubbleSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

void merge(vector<int>& a, int l, int m, int r) {
    vector<int> L(a.begin() + l, a.begin() + m + 1);
    vector<int> R(a.begin() + m + 1, a.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < L.size() && j < R.size()) a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < L.size()) a[k++] = L[i++];
    while (j < R.size()) a[k++] = R[j++];
}

void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

int partition(vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

// ---------- Binary Search Demo ----------
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

// ---------- Main Program ----------
int main() {
    srand(time(0));
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = rand();

    cout << "\nSorting Performance Comparison (in ms):\n";

    vector<int> temp;

    // Bubble Sort
    if (n <= 5000) {
        temp = arr;
        auto start = high_resolution_clock::now();
        bubbleSort(temp);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start).count();
        cout << "Bubble Sort: " << duration / 1000.0 << " ms\n";
    } else {
        cout << "Bubble Sort skipped for large n (too slow)\n";
    }

    // Merge Sort
    temp = arr;
    auto start = high_resolution_clock::now();
    mergeSort(temp, 0, n - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start).count();
    cout << "Merge Sort: " << duration / 1000.0 << " ms\n";

    // Quick Sort
    temp = arr;
    start = high_resolution_clock::now();
    quickSort(temp, 0, n - 1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start).count();
    cout << "Quick Sort: " << duration / 1000.0 << " ms\n";

    // Binary Search
    cout << "\nEnter element to search: ";
    int x; cin >> x;
    sort(arr.begin(), arr.end());
    binarySearchDemo(arr, x);

    return 0;
}
