#include <bits/stdc++.h
using namespace std;

#define MAX_SIZE 100
#define MAX_RANGE 100
//https://chat.deepseek.com/share/3mlgqz8e94ms59hjgl
void countsortSimple(int arr[], int n) {
    // Find maximum
    int maxval = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxval) {
            maxval = arr[i];
        }
    }
    
    // Count array
    int cntArr[MAX_RANGE];
    for (int i = 0; i <= maxval; i++) {
        cntArr[i] = 0;
    }
    
    // Count frequencies
    for (int i = 0; i < n; i++) {
        cntArr[arr[i]]++;
    }
    
    // Reconstruct sorted array
    int index = 0;
    for (int i = 0; i <= maxval; i++) {
        for (int j = 0; j < cntArr[i]; j++) {
            arr[index] = i;
            index++;
        }
    }
}

int main() {
    int arr[] = {2, 5, 3, 0, 2, 3, 0, 3};
    int n = 8;
    cout<<"Original: ";
    
    for (int i = 0; i < n; i++) {
      cout<<arr[i];
       
    }
    cout<<"\n";
    
    countsortSimple(arr, n);
    
cout<<"Sorted: ";
    for (int i = 0; i < n; i++) {
          cout<<arr[i];
    }
    cout<<"\n";
    
    return 0;
}
