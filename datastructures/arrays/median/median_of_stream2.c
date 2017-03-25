/*

Given that integers are read from a data stream. Find median of elements read so for in efficient way. For simplicity assume there are no duplicates. For example, let us consider the stream 5, 15, 1, 3 …

After reading 1st element of stream - 5 -> median - 5
After reading 2nd element of stream - 5, 15 -> median - 10
After reading 3rd element of stream - 5, 15, 1 -> median - 5
After reading 4th element of stream - 5, 15, 1, 3 -> median - 4, so on...
Making it clear, when the input size is odd, we take the middle element of sorted data. If the input size is even, we pick average of middle two elements in sorted stream.

Note that output is effective median of integers read from the stream so far. Such an algorithm is called online algorithm. Any algorithm that can guarantee output of i-elements after processing i-th element, is said to be online algorithm. Let us discuss three solutions for the above problem.

Method 1: Insertion Sort

If we can sort the data as it appears, we can easily locate median element. Insertion Sort is one such online algorithm that sorts the data appeared so far. At any instance of sorting, say after sorting i-th element, the first i elements of array are sorted. The insertion sort doesn’t depend on future data to sort data input till that point. In other words, insertion sort considers data sorted so far while inserting next element. This is the key part of insertion sort that makes it an online algorithm.

However, insertion sort takes O(n2) time to sort n elements. Perhaps we can use binary search on insertion sort to find location of next element in O(log n) time. Yet, we can’t do data movement in O(log n) time. No matter how efficient the implementation is, it takes polynomial time in case of insertion sort.

Interested reader can try implementation of Method 1.

Method 2: Augmented self balanced binary search tree (AVL, RB, etc…)

At every node of BST, maintain number of elements in the subtree rooted at that node. We can use a node as root of simple binary tree, whose left child is self balancing BST with elements less than root and right child is self balancing BST with elements greater than root. The root element always holds effective median.

If left and right subtrees contain same number of elements, root node holds average of left and right subtree root data. Otherwise, root contains same data as the root of subtree which is having more elements. After processing an incoming element, the left and right subtrees (BST) are differed utmost by 1.

Self balancing BST is costly in managing balancing factor of BST. However, they provide sorted data which we don’t need. We need median only. The next method make use of Heaps to trace median.

Method 3: Heaps

Similar to balancing BST in Method 2 above, we can use a max heap on left side to represent elements that are less than effective median, and a min heap on right side to represent elements that are greater than effective median.

After processing an incoming element, the number of elements in heaps differ utmost by 1 element. When both heaps contain same number of elements, we pick average of heaps root data as effective median. When the heaps are not balanced, we select effective median from the root of heap containing more elements.

*/

Given below is implementation of above method. For algorithm to build these heaps, please read the highlighted code.

#include <iostream>
using namespace std;
 
// Heap capacity
#define MAX_HEAP_SIZE (128)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
 
//// Utility functions
 
// exchange a and b
inline
void Exch(int &a, int &b)
{
    int aux = a;
    a = b;
    b = aux;
}
 
// Greater and Smaller are used as comparators
bool Greater(int a, int b)
{
    return a > b;
}
 
bool Smaller(int a, int b)
{
    return a < b;
}
 
int Average(int a, int b)
{
    return (a + b) / 2;
}
 
// Signum function
// = 0  if a == b  - heaps are balanced
// = -1 if a < b   - left contains less elements than right
// = 1  if a > b   - left contains more elements than right
int Signum(int a, int b)
{
    if( a == b )
        return 0;
 
    return a < b ? -1 : 1;
}
 
// Heap implementation
// The functionality is embedded into
// Heap abstract class to avoid code duplication
class Heap
{
public:
    // Initializes heap array and comparator required
    // in heapification
    Heap(int *b, bool (*c)(int, int)) : A(b), comp(c)
    {
        heapSize = -1;
    }
 
    // Frees up dynamic memory
    virtual ~Heap()
    {
        if( A )
        {
            delete[] A;
        }
    }
 
    // We need only these four interfaces of Heap ADT
    virtual bool Insert(int e) = 0;
    virtual int  GetTop() = 0;
    virtual int  ExtractTop() = 0;
    virtual int  GetCount() = 0;
 
protected:
 
    // We are also using location 0 of array
    int left(int i)
    {
        return 2 * i + 1;
    }
 
    int right(int i)
    {
        return 2 * (i + 1);
    }
 
    int parent(int i)
    {
        if( i <= 0 )
        {
            return -1;
        }
 
        return (i - 1)/2;
    }
 
    // Heap array
    int   *A;
    // Comparator
    bool  (*comp)(int, int);
    // Heap size
    int   heapSize;
 
    // Returns top element of heap data structure
    int top(void)
    {
        int max = -1;
 
        if( heapSize >= 0 )
        {
            max = A[0];
        }
 
        return max;
    }
 
    // Returns number of elements in heap
    int count()
    {
        return heapSize + 1;
    }
 
    // Heapification
    // Note that, for the current median tracing problem
    // we need to heapify only towards root, always
    void heapify(int i)
    {
        int p = parent(i);
 
        // comp - differentiate MaxHeap and MinHeap
        // percolates up
        if( p >= 0 && comp(A[i], A[p]) )
        {
            Exch(A[i], A[p]);
            heapify(p);
        }
    }
 
    // Deletes root of heap
    int deleteTop()
    {
        int del = -1;
 
        if( heapSize > -1)
        {
            del = A[0];
 
            Exch(A[0], A[heapSize]);
            heapSize--;
            heapify(parent(heapSize+1));
        }
 
        return del;
    }
 
    // Helper to insert key into Heap
    bool insertHelper(int key)
    {
        bool ret = false;
 
        if( heapSize < MAX_HEAP_SIZE )
        {
            ret = true;
            heapSize++;
            A[heapSize] = key;
            heapify(heapSize);
        }
 
        return ret;
    }
};
 
// Specilization of Heap to define MaxHeap
class MaxHeap : public Heap
{
private:
 
public:
    MaxHeap() : Heap(new int[MAX_HEAP_SIZE], &Greater)  {  }
 
    ~MaxHeap()  { }
 
    // Wrapper to return root of Max Heap
    int GetTop()
    {
        return top();
    }
 
    // Wrapper to delete and return root of Max Heap
    int ExtractTop()
    {
        return deleteTop();
    }
 
    // Wrapper to return # elements of Max Heap
    int  GetCount()
    {
        return count();
    }
 
    // Wrapper to insert into Max Heap
    bool Insert(int key)
    {
        return insertHelper(key);
    }
};
 
// Specilization of Heap to define MinHeap
class MinHeap : public Heap
{
private:
 
public:
 
    MinHeap() : Heap(new int[MAX_HEAP_SIZE], &Smaller) { }
 
    ~MinHeap() { }
 
    // Wrapper to return root of Min Heap
    int GetTop()
    {
        return top();
    }
 
    // Wrapper to delete and return root of Min Heap
    int ExtractTop()
    {
        return deleteTop();
    }
 
    // Wrapper to return # elements of Min Heap
    int  GetCount()
    {
        return count();
    }
 
    // Wrapper to insert into Min Heap
    bool Insert(int key)
    {
        return insertHelper(key);
    }
};
 
// Function implementing algorithm to find median so far.
int getMedian(int e, int &m, Heap &l, Heap &r)
{
    // Are heaps balanced? If yes, sig will be 0
    int sig = Signum(l.GetCount(), r.GetCount());
    switch(sig)
    {
    case 1: // There are more elements in left (max) heap
 
        if( e < m ) // current element fits in left (max) heap
        {
            // Remore top element from left heap and
            // insert into right heap
            r.Insert(l.ExtractTop());
 
            // current element fits in left (max) heap
            l.Insert(e);
        }
        else
        {
            // current element fits in right (min) heap
            r.Insert(e);
        }
 
        // Both heaps are balanced
        m = Average(l.GetTop(), r.GetTop());
 
        break;
 
    case 0: // The left and right heaps contain same number of elements
 
        if( e < m ) // current element fits in left (max) heap
        {
            l.Insert(e);
            m = l.GetTop();
        }
        else
        {
            // current element fits in right (min) heap
            r.Insert(e);
            m = r.GetTop();
        }
 
        break;
 
    case -1: // There are more elements in right (min) heap
 
        if( e < m ) // current element fits in left (max) heap
        {
            l.Insert(e);
        }
        else
        {
            // Remove top element from right heap and
            // insert into left heap
            l.Insert(r.ExtractTop());
 
            // current element fits in right (min) heap
            r.Insert(e);
        }
 
        // Both heaps are balanced
        m = Average(l.GetTop(), r.GetTop());
 
        break;
    }
 
    // No need to return, m already updated
    return m;
}
 
void printMedian(int A[], int size)
{
    int m = 0; // effective median
    Heap *left  = new MaxHeap();
    Heap *right = new MinHeap();
 
    for(int i = 0; i < size; i++)
    {
        m = getMedian(A[i], m, *left, *right);
 
        cout << m << endl;
    }
 
    // C++ more flexible, ensure no leaks
    delete left;
    delete right;
}
// Driver code
int main()
{
    int A[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
    int size = ARRAY_SIZE(A);
 
    // In lieu of A, we can also use data read from a stream
    printMedian(A, size);
 
    return 0;
}
/*
Time Complexity: If we omit the way how stream was read, complexity of median finding is O(N log N), as we need to read the stream, and due to heap insertions/deletions.

At first glance the above code may look complex. If you read the code carefully, it is simple algorithm.
*/