#include<iostream>
using namespace std;

void merge(int *arr, int s, int e) {

    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    
    //babbars way of creating an array, i have created 2 arrays normally
    int *first = new int[len1];
    int *second = new int[len2];

    
    
    
    
    
    
    
    //copy values from main array to 2 separate arrays to sort and put onto main array later using sorting
    
    //for left array 
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    //for right array
    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    
    
    
    
    
    
    //merge 2 sorted arrays 
    
    //setting the indices of the two array to input the data of the 2 arrays to the main array by sorting
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    
    //Input the data of the 2 arrays to the main array by sorting
    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }   

    
    
    
    
    
    
    
    
    //only one case is possible now , either left or right array is left so copy its values now
    
    //if left array's any element is left then copy everything at last to the main array
    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    
    //if right array's any element is left then copy everything at last to the main array
    while(index2 < len2 ) {
        arr[mainArrayIndex++] = second[index2++];
    }
        
    
    
    
    
    delete []first;
    delete []second;

}

void mergeSort(int *arr, int s, int e) {

    //base case
    if(s >= e) {
        return;
    }
    
    int mid = (s+e)/2;

    //left part sort karna h 
    mergeSort(arr, s, mid);
    
    //right part sort karna h 
    mergeSort(arr, mid+1, e);

    //merge
    merge(arr, s, e);

}

int main() {

    int arr[15] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int n = 15;

    mergeSort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}
