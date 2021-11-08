#include <iostream>
#include <sstream>
#include <stack>
#include <string>

/* Определяет сколько дней необходимо лесорубу, срубающем
  а деревьев в день и имеющего каждый k-тый день выходной,
  срубить Х деревьев.
*/
long long f(long long a, long long k, long long x);

int main()
{
  long long A = 0;// Количество деревьев срубаемых Дмитрием за 1 день
  long long B = 0;// Количество деревьев срубаемых Фёдором за 1 день
  long long K = 0;// Каждый k-тый день выходной Дмитрия
  long long M = 0;// Каждый m-ный день выходной Фёдора
  long long X = 0;// Всего деревьев в лесу

  std::cin >> A >> K >> B >> M >> X;

  long long l = 1;
  //Максимальное количество дней,за которое срубят лес
  long long r = 2 * (X + 1) / (A + B);
  long long m = 0;

  while (l < r) {
    m = (l + r) / 2;

    long long Xa = f(A, K, m);
    long long Xb = f(B, M, m);
    if ((Xa + Xb) >= X) {
      r = m;
    } else {
      l = m + 1;
    }
  }

  std::cout << l;

  return 0;
}

long long f(long long a, long long k, long long x)
{
  return a * (x - x / k);
}