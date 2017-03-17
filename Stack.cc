class Stack
{
private:
	int size;
	int top;
	int *value;
public:
	Stack(int _size)
	{
		size  = _size;
		top   = 0;
		value = new int[size];
	}

	~Stack()
	{
		delete[] value;
	}

	bool IsEmpty()
	{
		return (top == 0);
	}

	bool IsFull()
	{
		return (top == size);
	}

	void Push(int x)
	{
		if(IsFull() == false)
		{
			value[top] = x;
			top++;
		}
	}

	int Pop()
	{
		if(IsEmpty() == false)
		{
			top--;
			return value[top];
		}
	}

	int Peek()
	{
		if(IsEmpty() == false)
		{
			return value[top-1];
		}
	}

	int Length()
	{
		return top;
	}
};

