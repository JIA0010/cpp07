#ifndef ARRAY_HPP 
#define ARRAY_HPP

#include <iostream>

// テスト用のユーザー定義クラス
class CustomClass {
public:
    int value;
    CustomClass(int val = 0) : value(val) {}
};

// operator<< をオーバーロードして CustomClass の出力をサポート
std::ostream& operator<<(std::ostream& os, const CustomClass& obj) {
    os << obj.value;
    return os;
}

template <typename T>
class Array {
private:
    T *array;
    unsigned int _size;

public:
    Array();
    Array(unsigned int n);
    Array(const Array &other);
    ~Array();

    Array &operator=(const Array &other);

    T &operator[](unsigned int i);

    unsigned int size() const;
};

template <typename T>
Array<T>::Array() : array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array &other) : array(new T[other._size]), _size(other._size) {
    for (unsigned int i = 0; i < _size; i++)
        array[i] = other.array[i];
}

template <typename T>
Array<T>::~Array() {
    delete[] array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
    if (this == &other)
        return *this;
    delete[] array;
    array = new T[other._size];
    _size = other._size;
    for (unsigned int i = 0; i < _size; i++)
        array[i] = other.array[i];
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int i) {
    if (i >= _size)
        throw std::out_of_range("Index out of range");
    return array[i];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}


#endif