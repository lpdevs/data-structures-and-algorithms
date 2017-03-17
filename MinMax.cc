// find max value in "a" array with it's length is N
int Max(int *a, int N)
{
  int _idmax = 0;
  for(int i = 1; i < N; i++)
    if(a[i] > a[_idmax]) _idmax = i;
  return a[_idmax];
}

// find min value in "a" array with it's length is N
int Min(int *a, int N)
{
  int _idmin = 0;
  for(int i = 1; i < N; i++)
    if(a[i] < a[_idmin]) _idmin = i;
  return a[_idmin];
}

// find max between a and b
int Max(int a, int b)
{
  return (a > b) ? a : b;
}

// find min between a and b
int Min(int a, int b)
{
  return (a < b) ? a : b;
}

