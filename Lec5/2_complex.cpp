#include <iostream>

using namespace std;

class Complex{
    private:
    double real, img;

    public:
    Complex(double real, double img) : real(real), img(img){}
    Complex(const Complex& c) {real = c.real, img = c.img;}

    // 연산자 오버로딩을 모른다고 가정했을 때
    // Complex plus(const Complex& c);
    // Complex minus(const Complex& c);
    // Complex times(const Complex& c);
    // Complex divide(const Complex& c);

    /*
    하지만 연산자 오버로딩을 이용해서 plus 를 operator+ 로, divide 를 operator/ 로, 
    등등 바꿔준다면 단순히 프로그래머가a + b/c + d; 게 쓴다고 해도, 
    컴파일러가 a.operator+(b.operator/(c)).operator+(d); 로 알아서 변환시켜서 처리하기 때문에
    속도나 다른 면의 어떠한 차이 없이 뛰어난 가독성과 편리함을 얻을 수 있게 됩니다.
    */

    

    Complex operator+(const Complex& c) const;
    Complex operator-(const Complex& c) const;
    Complex operator*(const Complex& c) const;
    Complex operator/(const Complex& c) const;
//    Complex operator=(const Complex& c);     // a = b = c
// operator= 를 만들지 않더라도 c = a * b 연산 가능.
// 컴파일러 차원에서 디폴트 대입 연산자를 지원하고 있다.
    Complex& operator+=(const Complex& c);
    Complex& operator-=(const Complex& c);
    Complex& operator*=(const Complex& c);
    Complex& operator/=(const Complex& c);


   void println() { std::cout << "( " << real << " , " << img << " ) " << std::endl; }
};

Complex Complex::operator+(const Complex& c) const{
    Complex temp(real + c.real, img + c.img);
    return temp;
}
Complex Complex::operator-(const Complex& c) const{
    Complex temp(real - c.real, img - c.img);
    return temp;
}
Complex Complex::operator*(const Complex& c) const{
    Complex temp(real*c.real - img*c.img, real*c.img + img*c.real);
    return temp;
}
Complex Complex::operator/(const Complex& c) const{
    Complex temp(
        (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
        (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
    return temp;   
}
// Complex Complex::operator=(const Complex& c){
//     real = c.real;
//     img = c.img;
//     return *this;
// }
Complex& Complex::operator+=(const Complex& c) {
  (*this) = (*this) + c;
  return *this;
}
Complex& Complex::operator-=(const Complex& c) {
  (*this) = (*this) - c;
  return *this;
}
Complex& Complex::operator*=(const Complex& c) {
  (*this) = (*this) * c;
  return *this;
}
Complex& Complex::operator/=(const Complex& c) {
  (*this) = (*this) / c;
  return *this;
}

int main(){
    Complex a(1.0, 2.0);
    Complex b(3.0, -2.0);
    // Complex c(0.0,0.0);

    // c = a * b + a / b + a + b;
    // c.println();

    a += b;
    a.println();
    b.println();
}