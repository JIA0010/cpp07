#include "whatever.hpp"

int main( void ) {
int a = 2;
int b = 3;

//swapのテスト
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;

//min, maxのテスト
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

//文字列のテストで、swap, min, maxを使えるか確認
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}