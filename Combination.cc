// nCk
int Combination(int k, int n)
{
  int r = 1;
  for(int i = 1; i <= k; i++, n--)
    r = r * n / i;
  return r;
}

