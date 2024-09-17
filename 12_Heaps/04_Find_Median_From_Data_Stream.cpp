/*
The median is the middle value in an ordered integer list. 
If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:
MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.


Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]
Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 
*/

/*
Appraoch - 
Maintain 2 heaps left side max and right side min.
If elements in left is 0 or less than right add new element to left else right.
Balance both the heaps in such a way that left has only 1 element more than right.

Assume if X is middle element, then all elements on X's left will go in leftHeap
and right elements on rightHeap.

  [1, 2, 3,         x ,      5, 6, 7]
Left side heap             Right side heap
 Max Value                  Min value

if no of elements in leftHeap + rightHeap is even then take top elements from both heaps and divide it by 2 and return it.
else return leftHeap's top element.
*/


class MedianFinder {
public:
    // [1, 2, 3,         x ,      5, 6, 7]
    // Left side heap             Right side heap
    // Max Value                  Min value
    priority_queue<int> leftMaxHeap;
    priority_queue<int,vector<int>, greater<int>> rightMinHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(leftMaxHeap.size() == 0 || num < leftMaxHeap.top()){
            leftMaxHeap.push(num);
        }
        else{
            rightMinHeap.push(num);
        }


        // balancing the heaps
        if(leftMaxHeap.size() > rightMinHeap.size() + 1){
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        }
        else if(rightMinHeap.size() > leftMaxHeap.size()){
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }

    }
    
    double findMedian() {
        if(leftMaxHeap.size() == rightMinHeap.size()){
            double result = (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
            return result;
        }
        else{
            return leftMaxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
