#include "TestUtils.hpp"
#include "Array.hpp"

// class ArrayTest : public ::testing::Test {
//  protected:
//   void SetUp() override {
//     // テストの前に実行される処理
//     array = new Array<int>();
//   }
//   void TearDown() override { delete array; }
//   Array<int>* array;
// };

//Arrayが空の場合、size()は0を返す
TEST(ArrayTest, EmptyArraySize) {
  array_return_test<unsigned int, Array<unsigned int>>(new Array<unsigned int>(), &Array<unsigned int>::size, 0);
}

//Arrayが_sizeの長さを持つ場合、size()は_sizeを返す
TEST(ArrayTest, ArraySize) {
  array_return_test<unsigned int, Array<unsigned int>>(new Array<unsigned int>(5), &Array<unsigned int>::size, 5);
}

//Arrayが空の場合、operator[]は例外を投げる
TEST(ArrayTest, EmptyArrayOperator) {
  Array<int> empty;
  EXPECT_THROW(empty[0], std::exception);
}

//コピーコンストラクタの時、ディープコピーを返す
TEST(ArrayTest, CopyConstructor) {
  Array<int> arr(5);
  for (unsigned int i = 0; i < arr.size(); i++) {
    arr[i] = i * 2;
  }
  Array<int> copied(arr);
  for (unsigned int i = 0; i < arr.size(); i++) {
    EXPECT_EQ(arr[i], copied[i]);
  }
}

//代入演算子の時、ディープコピーを返す
TEST(ArrayTest, AssignmentOperator) {
  Array<int> arr(5);
  for (unsigned int i = 0; i < arr.size(); i++) {
    arr[i] = i * 2;
  }
  Array<int> copied = arr;
  for (unsigned int i = 0; i < arr.size(); i++) {
    EXPECT_EQ(arr[i], copied[i]);
  }
}

//operator[] のテスト
TEST(ArrayTest, Operator) {
  Array<int> arr(5);
  for (unsigned int i = 0; i < arr.size(); i++) {
    arr[i] = i * 2;
    EXPECT_EQ(arr[i], i * 2);
  }
}

//範囲外アクセスのテスト
TEST(ArrayTest, OutOfRange) {
  Array<int> arr(5);
  for (unsigned int i = 0; i < arr.size(); i++) {
    arr[i] = i * 2;
  }
  EXPECT_THROW(arr[5], std::exception);
}