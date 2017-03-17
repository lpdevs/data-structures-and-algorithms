class PriorityQueue
{
private:
	int size;
	int leng;
	int *value;

private:
	friend void Heapify(int *a, int leng, int i)
	{
		int Left = 2*i + 1, Right = 2*i + 2;
		int Smallest;
		if (Left < leng && a[Left] < a[i]) Smallest = Left;
		else Smallest = i;
		if (Right < leng && a[Right] < a[Smallest]) Smallest = Right;
		if (Smallest != i)
		{
			Swap(a[i], a[Smallest]);
			Heapify(a, leng, Smallest);
		}
	}

public:
	PriorityQueue(int _size)
	{
		size  = _size;
		leng  = 0;
		value = new int[size];
	}

	~PriorityQueue()
	{
		delete[] value;
	}

	bool IsEmpty()
	{
		return (leng == 0);
	}

	bool IsFull()
	{
		return (leng == size);
	}

	void Enqueue(int x)
	{
		if(IsFull() == true) return;
		if(leng == 0)
		{
			value[leng++] = x;
		}
		else
		{
			value[leng++] = x;
			int current = leng - 1;
			int parent  = (current - 1)/2;
			while (current > 0)
			{
				if(value[current] < value[parent])
				{
					Swap(value[current], value[parent]);
					current = parent;
					parent = (current - 1)/2;
				}
				else break;
			}
		}
	}

	int Dequeue()
	{
		if(IsEmpty() == false)
		{
			int t = value[0];
			value[0] = value[leng-1];
			leng--;
			Heapify(value, leng, 0);
			return t;
		}
	}
};

