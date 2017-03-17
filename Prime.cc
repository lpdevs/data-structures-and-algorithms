bool IsPrimeNumber(int a)
{
  if(a < 2) return false;
  for(int i = 2; i*i <= a; i++)
    if(a % i == 0) return false;
  return true;
}

// genarate a prime array from 0 to N.
bool* GeneratePrimeArray(int N)
{
  bool *prime = new bool[N + 1];
  for(int i = 0; i <= N; i++)
    prime[i] = true;
  prime[0] = prime[1] = false;

  for(int i = 2; i * i <= N; i++)
    if(prime[i] == true)
    {
      int j = 2;
      while(i * j <= N)
      {
        prime[i * j] = false;
        j++;
      }
    }
  return prime;
}

