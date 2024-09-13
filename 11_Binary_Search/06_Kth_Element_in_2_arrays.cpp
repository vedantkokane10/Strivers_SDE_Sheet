/*
Given two sorted arrays arr1 and arr2 and an element k. The task is to find the element that would be at the kth position of the combined sorted array.

Examples :
Input: k = 5, arr1[] = [2, 3, 6, 7, 9], arr2[] = [1, 4, 8, 10]
Output: 6
Explanation: The final combined sorted array would be - 1, 2, 3, 4, 6, 7, 8, 9, 10. The 5th element of this array is 6.

Input: k = 7, arr1[] = [100, 112, 256, 349, 770], arr2[] = [72, 86, 113, 119, 265, 445, 892]
Output: 256
Explanation: Combined sorted array is - 72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892. 7th element of this array is 256.

*/

int kthElement(int kth, vector<int>& arr1, vector<int>& arr2) {
    int i = 0;
    int j = 0;
    int k = 0;
    int currentElement = 0;
    while(i < arr1.size() && j < arr2.size()){
        if(arr1[i] <= arr2[j]){
            currentElement = arr1[i];
            i++;
        }
        else{
            currentElement = arr2[j];
            j++;
        }
        if(k == kth-1){
            return currentElement;
        }
        k++;
    }
    
    while(i < arr1.size()){
        currentElement = arr1[i];
        i++;
        if(k == kth-1){
            return currentElement;
        }
        k++;
        
    }
    while(j < arr2.size()){
        currentElement = arr2[j];
        j++;
        if(k == kth-1){
            return currentElement;
        }
        k++;
    }
    
    return currentElement;
}
