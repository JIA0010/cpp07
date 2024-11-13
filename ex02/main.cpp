#include "Array.hpp"



int main() {

    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;


    // 単純な型（int）のテスト
    Array<int> arr(5);
    for (unsigned int i = 0; i < arr.size(); i++) {
        arr[i] = i * 2;
        std::cout << arr[i] << std::endl;
    }

    // 複雑な型（std::string）のテスト
    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "Array";
    stringArray[2] = "Template";
    std::cout << "stringArray: ";

    for (unsigned int i = 0; i < stringArray.size(); i++) {
        std::cout << stringArray[i] << " ";
    }
    std::cout << std::endl;

    // 範囲外アクセスのテスト
    try {
        std::cout << arr[3] << std::endl; // 正常アクセス
        std::cout << arr[5] << std::endl; // 範囲外アクセス
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        // ユーザー定義クラス CustomClass のテスト
        Array<CustomClass> customArray(3);
        for (unsigned int i = 0; i < customArray.size(); i++) {
            customArray[i] = CustomClass(i * 10);  // 異なる値で初期化
        }
        std::cout << "customArray: ";
        for (unsigned int i = 0; i < customArray.size(); i++) {
            std::cout << customArray[i] << " ";
        }
        std::cout << std::endl;
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
    }

    return 0;
}