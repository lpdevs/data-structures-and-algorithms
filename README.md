### Data structures and algorithms

  * Practicing some data structures and algorithms from basic to advanced level.
  * Programming languague: C/C++

### Contents

  * **Absolute.cc**:

    ```cpp
    int Abs(int a)
    ```

  * **Combination.cc**:

    ```cpp
    int Combination(int k, int n)
    ```

  * **Factorial.cc**:

    ```cpp
    int Factorial(int N)
    ```

  * **GCD-LCM.cc**:

    ```cpp
    int GCD(int a, int b)
    int LCM(int a, int b)
    ```

  * **MinMax.cc**:

    ```cpp
    int Max(int *a, int N)
    int Min(int *a, int N)
    int Max(int a, int b)
    int Min(int a, int b)
    ```

  * **Prime.cc**:

    ```cpp
    bool IsPrimeNumber(int a)
    bool* GeneratePrimeArray(int N)
    ```

  * **PriorityQueue.cc**:

    ```cpp
    class PriorityQueue
    {
      void Heapify(int *a, int leng, int i)
      PriorityQueue(int _size)
      ~PriorityQueue()
      bool IsEmpty()
      bool IsFull()
      void Enqueue(int x)
      int Dequeue()
    }
    ```

  * **Queue.cc**:

   ```cpp
   class Queue
   {
      Queue(int _size)
      ~Queue()
      bool IsEmpty()
      bool IsFull()
      void Enqueue(int x)
      int Dequeue()
      int Peek()
      int Length()
   }
   ```

  * **Sorting.cc**:

    ```cpp
    void Selection(int *a, int N)
    void Insertion(int *a, int N)
    void BinaryInsertion(int *a, int N)
    void InterChange(int *a, int N)
    void Bubble(int *a, int N)
    void Shake(int *a, int N)
    void Quick(int *a, int left, int right)
    void Merge(int *a, int left, int m, int right)
    void MergeSort(int *a, int left, int right) --> main here
    void Heapify(int *a, int N, int i)
    void BuildHeap(int *a, int N)
    void Heap(int *a, int N) --> main here
    ```

  * **Square.cc**:

    ```cpp
    bool IsSquareNumber(int a)
    ```

  * **Stack.cc**:

    ```cpp
    class Stack
    {
      Stack(int _size)
      ~Stack()
      bool IsEmpty()
      bool IsFull()
      void Push(int x)
      int Pop()
      int Peek()
      int Length()
    }
    ```

  * **Swap.cc**:

    ```cpp
    void Swap(int &a, int &b)
    ```

(to be continue...)
