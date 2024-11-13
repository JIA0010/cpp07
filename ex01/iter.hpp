#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void print(T const &x) {
    std::cout << x << std::endl;
}

template <typename T>
void iter(T const *array, int length, void (*func)(T const &)) {
    if(!array || !func) {
        return;
    }
    for (int i = 0; i < length; i++) {
        func(array[i]);
    }
}

//オーバーロードした。関数の引数がconstでない場合。利用者が使いやすいように意識する
template <typename T>
void iter(T *array, int length, void (*func)(T &)) {
    if(!array || !func) {
        return;
    }
    for (int i = 0; i < length; i++) {
        func(array[i]);
    }
}

#endif