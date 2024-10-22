#include "iter.hpp"

int main() {
    int arr[] = {0, 1, 2, 3, 4};
    iter(arr, 5, print);

    std::string strArr[] = {"one", "two", "three"};
    iter(strArr, 3, print);

    return 0;
}