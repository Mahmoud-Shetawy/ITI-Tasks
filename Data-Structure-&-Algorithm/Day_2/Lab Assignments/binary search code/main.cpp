#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int x) {

    int low = 0, high = size - 1;


    while (low <= high) {

        int mid = (low + high) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        else if (arr[mid] < x) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }
}
int main()
{
  int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    int result = binarySearch(arr, n, x);
    cout << result << endl;
    return 0;
}
