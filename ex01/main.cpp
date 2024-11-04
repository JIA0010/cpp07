#include "iter.hpp"

int main() {
    //数字で配列を作成し、関数を呼び出す
    int arr[] = {0, 1, 2, 3, 4};
    iter(arr, 5, print);

    //文字列で配列を作成し、関数を呼び出す
    std::string strArr[] = {"one", "two", "three"};
    iter(strArr, 3, print);

    return 0;
}