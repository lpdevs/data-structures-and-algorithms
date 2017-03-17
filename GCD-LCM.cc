// GCD: greatest common divisor
// when at least one of them is not zero
int GCD(int a, int b)
{
  if(a == 0 || b == 0) return a + b;
  return GCD(b, a%b);
}

// LCM : least common multiple
// when both a and b are different from zero
int LCM(int a, int b)
{
  return (a*b) / GCD(a, b);
}

