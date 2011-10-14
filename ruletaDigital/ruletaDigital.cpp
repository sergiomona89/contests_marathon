#include <iostream>
#include <set>

long long pow(long long b, int e, long long mod)
{
  return (e == 0) ? 1 : b  * pow(b, e - 1, mod) % mod;
}

using namespace std;
int main (int argc, char ** argv)
{
  long long N, M;
  int k;

  while(true)
  {
    cin >> N;
    cin >> M;

    if(N == 0 && M == 0) break;

    cin >> k;

    long long P [k + 1];

    for (long long i = 0; i <= k; i++) cin >> P[i];

    set<long long> R;
    long long mod = (N + 1);

    for(long long i = 0; i <= M; i++)
    {
      long long f = 0;

      for(int j = k; j > 0; j--) f += (((pow(i, j, mod) % mod) * P[j]));

      f += P[0];
      f %= mod;
      R.insert(f);
    }
    cout << R.size() << endl;
  }
}
