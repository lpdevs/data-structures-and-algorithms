### Data structures and algorithms

  * Practicing some data structures and algorithms from basic to advanced level.
  * Programming languague: C/C++

### Contents

  * **Absolute.cc**:

    ```cc
    int Abs(int a);
    ```

  * **Combination.cc**:

    ```cc
    int Combination(int k, int n);
    ```

  * **Factorial.cc**:

    ```cc
    int Factorial(int N);
    ```

  * **GCD-LCM.cc**:

    ```cc
    int GCD(int a, int b);
    int LCM(int a, int b);
    ```

  * **MinMax.cc**:

    ```cc
    int Max(int *a, int N);
    int Min(int *a, int N);
    int Max(int a, int b);
    int Min(int a, int b);
    ```

  * **Prime.cc**:

    ```cc
    bool IsPrimeNumber(int a);
    bool* GeneratePrimeArray(int N);
    ```

  * **PriorityQueue.cc**:

    ```cc
    class PriorityQueue
    {
      void Heapify(int *a, int leng, int i);
      PriorityQueue(int _size);
      ~PriorityQueue();
      bool IsEmpty();
      bool IsFull();
      void Enqueue(int x);
      int Dequeue();
    }
    ```

  * **Queue.cc**:

   ```cc
   class Queue
   {
      Queue(int _size);
      ~Queue();
      bool IsEmpty();
      bool IsFull();
      void Enqueue(int x);
      int Dequeue();
      int Peek();
      int Length();
   }
   ```

  * **Sorting.cc**:

    ```cc
    void Selection(int *a, int N);
    void Insertion(int *a, int N);
    void BinaryInsertion(int *a, int N);
    void InterChange(int *a, int N);
    void Bubble(int *a, int N);
    void Shake(int *a, int N);
    void Quick(int *a, int left, int right);
    void Merge(int *a, int left, int m, int right);
    void MergeSort(int *a, int left, int right); --> main here
    void Heapify(int *a, int N, int i);
    void BuildHeap(int *a, int N);
    void Heap(int *a, int N); --> main here
    ```

  * **Square.cc**:

    ```cc
    bool IsSquareNumber(int a);
    ```

  * **Stack.cc**:

    ```cc
    class Stack
    {
      Stack(int _size);
      ~Stack();
      bool IsEmpty();
      bool IsFull();
      void Push(int x);
      int Pop();
      int Peek();
      int Length();
    }
    ```

  * **Swap.cc**:

    ```cc
    void Swap(int &a, int &b);
    ```
    
  * **N-aryTreeExample.cc**
  
    ```c
    struct _Node
    {
	     int id;
	     struct _Node *child;
	     struct _Node *next;
	     struct _Node *previous;
	     struct _Node *parent;
    };
    typedef _Node Node;

    void init(Node *root, int id);
    Node* find(Node *p, int id);
    void printTree(Node *p);
    void traversalTree(Node *node);
    void add(int id, int pid);
    void move(int id, int pid);
    void remove(int id);
    void getDepth(Node *node, int depth);
    ```

(to be continue...)
