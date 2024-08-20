#include <iostream>
#include <algorithm>

using namespace std;

void sift_up(int A[], int n);
void print(int A[], int n);
void sift_down(int A[], int n);
void heap_sort(int A[], int n);


int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    cin >> A[i];
    print (A, n);
    for (int j = 2; j <= n; j++)
    sift_up(A, j);
    cout << endl;
    print (A, n);
    cout << endl;
    heap_sort(A, n);
    print (A, n);
    


    return 0;
}

void sift_up(int A[], int n){
    for (int i = n-1; i > 0 && A[i] > A[(i-1)/2]; i = (i-1)/2)
    swap(A[i], A[(i-1)/2]);
}

void print(int A[], int n){
    for (int i = 0; i < n; i++){
        cout << A[i];
        if (i < n-1)
        cout << ", ";
    }
}

void sift_down(int A[], int n){
    int i = 0;
    while(2 * i + 1 < n){
        int child = 2*i+1;
        if (child+1 < n && A[child] < A[child+1])
        child++;
        if (A[i] >= A[child])
        break;
        swap(A[i], A[child]);
        i = child;

    }
}

void heap_sort(int A[], int n){
    for (int i = n-1; i > 0; i--){
        swap(A[0], A[i]);
        sift_down(A, i);
    }
}
