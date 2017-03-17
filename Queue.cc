class Queue
{
private:
	int size;
	int front, rear;
	int leng;
	int *value;
public:
	Queue(int _size)
	{
		size = _size;
		front = rear = leng = 0;
		value = new T[size];
	}

	~Queue()
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
		if(IsFull() == false)
		{
			value[rear] = x;
			rear = (rear + 1) % size;
			leng++;
		}
	}

	int Dequeue()
	{
		if(IsEmpty() == false)
		{
			int tmp = value[front];
			front = (front + 1) % size;
			leng--;
			return tmp;
		}
	}

	int Peek()
	{
		if(IsEmpty() == false)
		{
			return value[front];
		}
	}

	int Length()
	{
		return leng;
	}
};

