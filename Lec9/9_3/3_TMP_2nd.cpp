// 최대공약수를 구하기 위한 방법
// int gcd(int a, int b) {
//   if (b == 0) {
//     return a;
//   }

//   return gcd(b, a % b);
// }

#include <iostream>

template <int x, int y>
struct gcd
{
    /* data */
    static const int value = gcd<y, x % y>::value;
};

template <int x>
struct gcd<x, 0>
{
    /* data */
    static const int value = x;
};


template <int N, int D = 1>
struct Ratio {
  typedef Ratio<N, D> type;
  static const int num = N;  // 분자
  static const int den = D;  // 분모
};
template <class R1, class R2>
struct _Ratio_add {
  typedef Ratio<R1::num * R2::den + R2::num * R1::den, R1::den * R2::den> type;
};

template <class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_subtract {
  using type = Ratio<R1::num * R2::den - R2::num * R1::den, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_subtract : _Ratio_subtract<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_multiply {
  using type = Ratio<R1::num * R2::num, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_multiply : _Ratio_multiply<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_divide {
  using type = Ratio<R1::num * R2::den, R1::den * R2::num>;
};

template <class R1, class R2>
struct Ratio_divide : _Ratio_divide<R1, R2>::type {};



int main(){

  using r1 = Ratio<2, 3>;
  using r2 = Ratio<3, 2>;

  using r3 = Ratio_add<r1, r2>;
  std::cout << "2/3 + 3/2 = " << r3::num << " / " << r3::den << std::endl;

  using r4 = Ratio_multiply<r1, r3>;
  std::cout << "13 / 6 * 2 /3 = " << r4::num << " / " << r4::den << std::endl;

  return 0;
}