// Sorting from smaller to larger

// Selection sort
void Selection(int *a, int N)
{
	for(int i = 0; i < N - 1; i++)
	{
		int idmin = i;
		for(int j = i + 1; j < N; j++)
		  if(a[j] < a[idmin]) idmin = j;
			Swap(a[i], a[idmin]);
	}
}

// Insertion sort
void Insertion(int *a, int N)
{
	int pos, x;
	for(int i = 1; i < N; i++)
	{
    pos = i - 1;
		x = a[i];
		while(pos >= 0 && a[pos] > x)
		{
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos+1] = x;
	}
}

// BinaryInsertion sort
void BinaryInsertion(int *a, int N)
{
	int l, r, m, x;
	for(int i = 1; i < N; i++)
	{
		l = 0;
		r = i - 1;
		x = a[i];
		while (l <= r)
		{
			m = (l + r) / 2;
			if(a[m] > x) r = m - 1;
			else l = m + 1;
		}
		for(int j = i; j > l; j--)
		  a[j] = a[j-1];
		a[l] = x;
	}
}

// InterChange sort
void InterChange(int *a, int N)
{
	for(int i = 0; i < N - 1; i++)
		for(int j = i + 1; j < N; j++)
			if(a[j] < a[i]) Swap(a[j], a[i]);
}

// Bubble sort
void Bubble(int *a, int N)
{
	for(int i = 0; i < N-1; i++)
		for(int j = N-1; j > i; j--)
			if(a[j] < a[j-1]) Swap(a[j], a[j-1]);
}

// Shake sort
void Shake(int *a, int N)
{
	int left = 0, right = N - 1, k = N - 1;
	while(left < right)
	{
		for(int j = right; j > left; j--)
		{
			if(a[j] < a[j-1])
			{
				Swap(a[j], a[j-1]);
				k = j;
			}
		}
		left = k;
		for (int j = left; j < right; j++)
		{
			if (a[j] > a[j+1])
			{
				Swap(a[j], a[j+1]);
				k = j;
			}
		}
		right = k;
	}
}

// Quick sort
void Quick(int *a, int left, int right)
{
	int l = left, r = right, pivot = a[(l + r) / 2];
	while(l <= r)
	{
		while(a[l] < pivot) l++;
		while(a[r] > pivot) r--;
		if(l <= r)
		{
			Swap(a[l], a[r]);
			l++;
			r--;
		}
	}
	if(left < r) Quick(a, left, r);
	if(l < right) Quick(a, l, right);
}

// Merge sort
void Merge(int *a, int left, int m, int right)
{
	int l = left, r = m + 1, k = 0;
	int *tmp = new int[right - left + 1];
	while(l <= m && r <= right)
	{
		if(a[l] < a[r]) tmp[k++] = a[l++];
		else tmp[k++] = a[r++];
	}
	while (l <= m) tmp[k++] = a[l++];
	while (r <= right) tmp[k++] = a[r++];
	for(int i = 0; i < k; i++)
		a[i+left] = tmp[i];
	delete[] tmp;
}
// main here
void MergeSort(int *a, int left, int right)
{
	int m;
	if(left < right)
	{
		m = (left + right) / 2;
		MergeSort(a, left, m);
		MergeSort(a, m + 1, right);
		Merge(a, left, m, right);
	}
}

// Heap sort
void Heapify(int *a, int N, int i)
{
	int Left = 2*i + 1, Right = 2*i + 2, Largest;
	if(Left < N && a[Left] > a[i]) Largest = Left;
	else Largest = i;
  if(Right < N && a[Right] > a[Largest]) Largest = Right;
	if(Largest != i)
	{
		Swap(a[i], a[Largest]);
		Heapify(a, N, Largest);
	}
}

void BuildHeap(int *a, int N)
{
	for(int i = N/2-1; i >= 0; i--)
		Heapify(a, N, i);
}
// main here
void Heap(int *a, int N)
{
	BuildHeap(a, N);
	for(int i = N - 1; i >= 0; i--)
	{
		Swap(a[i], a[0]);
		Heapify(a, i, 0);
	}
}

