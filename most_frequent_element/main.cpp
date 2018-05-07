/**
 * @file    main.cpp
 * @author  Wojtek Węclewski <w.weclewski@protonmail.com>
 * @date    April, 2018
 * @brief   Find most frequent element in array
 *
 * For further development:
 *  -show all of most frequent elements
 *  -change second template to template specialization
 */

#include <iostream>
#include <unordered_map>
#include <exception>
#include <vector>
#include <type_traits>

template<typename C>
auto most_frequent(const C &array){
  using val_type = typename C::value_type;
  try{
    if(array.empty()) throw 0;
    auto max = array[0];
    std::unordered_map<val_type, int> tmp_map;
    for(auto&& el : array){
      if(++tmp_map[el] > max) max = el;
    }

    return max;

  }catch(int err_code){
    return static_cast<val_type>(err_code);
  }
}

template<typename T, unsigned int N>
auto most_frequent(const T (&array)[N]){
  try{
    if(N == 0) throw 0;
    auto max = array[0];
    std::unordered_map<T, int> tmp_map;
    for(auto&& el : array){
      if(++tmp_map[el] > max) max = el;
    }

    return max;

  }catch(int err_code){
    return static_cast<T>(err_code);
  }
}

int main(void){
  const std::array<int, 10> test0{1, 4, 5, 1, 2, 1, 4, 4, 5, 4};
  std::vector<char> test1{'c', 'd', 'c', 'a', 'z', 'a', 'c'};
  int test2[] = {1, 4, 5, 1, 2, 1, 5, 5, 5, 4};
  std::array<float, 0> test3;
  std::cout << "Test0: " << most_frequent(test0) << std::endl;
  std::cout << "Test1: " << most_frequent(test1) << std::endl;
  std::cout << "Test2: " << most_frequent(test2) << std::endl;
  std::cout << "Test3: " << most_frequent(test3) << std::endl;
  return 0;
}

