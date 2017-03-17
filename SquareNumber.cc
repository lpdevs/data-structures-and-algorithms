// a is square number if exists x, x*x = a
bool IsSquareNumber(int a)
{
    int left = 1, right = a, m;
    while(left < right)
    {
      m = (left + right) / 2;
      if(m*m > a) right = m - 1;
      else if(m*m < a) left = m + 1;
      else return true;
    }
    if(left * left == a) return true;
    return false;
}

