// 단위 데이터를 일반적인 변수에 보관하지 말고 클래스를 만들어서 클래스 객체에서 보관.
// -> 만일 틀린 단위를 연산하는 코드가 일어난다면 런타임에서 그냥 넘어갈 수 있다.

// 가장 이상적인 상황은 단위가 맞지 않는 연산을 수행하는 코드가 있다면 아예 컴파일 시에 오류를 발생시켜버리는 것
#include <iostream>
#include <typeinfo>

// 예시 1
template <typename U, typename V, typename W>
struct Dim
{
  using M = U;  //kg
  using L = V;  // m
  using T = W;  // s

  using type = Dim<M, L, T>;
};
// m/s == Dim<0,1,-1>


// 예시 2
template <typename U, typename V>
struct add_dim_ {
  typedef Dim<typename Ratio_add<typename U::M, typename V::M>::type,
              typename Ratio_add<typename U::L, typename V::L>::type,
              typename Ratio_add<typename U::T, typename V::T>::type>
    type;
};

template <typename U, typename V>
struct subtract_dim_ {
  typedef Dim<typename Ratio_subtract<typename U::M, typename V::M>::type,
              typename Ratio_subtract<typename U::L, typename V::L>::type,
              typename Ratio_subtract<typename U::T, typename V::T>::type>
    type;
};


// 예시 3
template <typename T, typename D>
struct quantity {
  T q;    // q 라는 멤버 변수에 데이터를 담고,
  using dim_type = D;   // dim_type 에 차원 정보를 담게 된다.
};

// error 
quantity operator+(quantity<T, D> quant) {return quantity<T, D>(q + quant.q);}
quantity operator-(quantity<T, D> quant) { return quantity<T, D>(q - quant.q); }