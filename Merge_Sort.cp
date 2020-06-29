/* Merge sort in C++ */
#include <iostream>
using namespace std;
 
// Function to Merge Arrays L and R into A.
// lefCount = number of elements in L
// rightCount = number of elements in R.
void Merge(int A[],int L[],int leftCount,int R[],int rightCount) {
    int i,j,k;
 
    // i - to mark the index of left subarray (L)
    // j - to mark the index of right subaraay (R)
    // k - to mark the index of merged subarray (A)
    //L:0 - leftCount, R:leftCount+1 - rightCount.
    i = 0; j = 0; k =0;
 
    while(i<leftCount && j< rightCount) {
        if(L[i] < R[j]) A[k++] = L[i++];
        else A[k++] = R[j++];
    }
    while(i < leftCount) A[k++] = L[i++];
    while(j < rightCount) A[k++] = R[j++];
}
 
// Recursive function to sort an array of integers.
void MergeSort(int A[],int n) {
    int mid,i;
    //L[], R[];
    if(n < 2) return; // base condition. If the array has less than two element, do nothing.
 
    mid = n/2;  // find the mid index.
 
    // create left and right subarrays
    // mid elements (from index 0 till mid-1) should be part of left sub-array
    // and (n-mid) elements (from mid to n-1) will be part of right sub-array
    //在使用new的时候，一般的形式如下：
            //    1. 删除单变量地址空间
            //          int *a = new int;
            //          delete a;   //释放单个int的空间
            //    2. 删除数组空间
            //          int *a = new int[5];
            //          delete []a;    //释放int数组空间
    int * L = new int[mid];
    int * R = new int [n - mid];
    for(i = 0;i<mid;i++) L[i] = A[i]; // creating left subarray
    for(i = mid;i<n;i++) R[i-mid] = A[i]; // creating right subarray
 
    MergeSort(L,mid);  // sorting the left subarray
    MergeSort(R,n-mid);  // sorting the right subarray
    Merge(A,L,mid,R,n-mid);  // Merging L and R into A as sorted list.
    // the delete operations is very important
    delete [] R;
    delete [] L;
}
 
int main() {
    /* Code to test the MergeSort function. */
 
    int A[] = {6,2,3,1,9,10,15,13,12,17}; // creating an array of integers.
    int i,numberOfElements;
    numberOfElements = sizeof(A)/sizeof(A[0]);
 
    // Calling merge sort to sort the array.
    MergeSort(A,numberOfElements);
 
    //printing all elements in the array once its sorted.
    for(i = 0;i < numberOfElements;i++)
       cout << " " << A[i];
       cout<<endl;
    return 0;
}
