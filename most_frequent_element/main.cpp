/**
 * @file    main.cpp
 * @author  Wojtek Węclewski <w.weclewski@protonmail.com>
 * @date    kwiecień, 2018
 * @brief   Find most frequent element in array
 *
 * For further development:
 *  -show all of most frequent elements
 *  -add exceptions for inappropriate containers
 */

#include <iostream>
#include <unordered_map>
#include <algorithm>

template<typename C>
auto most_frequent(const C &array){
  using val_type = typename C::value_type;
  auto max = array[0];
  std::unordered_map<val_type, int> tmp_map;
  for(auto el : array){
    if(++tmp_map[el] > max) max = el;
  }

  return max;
}

int main(void){
  const std::array<int, 10> test = {1, 4, 5, 1, 2, 1, 4, 4, 5, 4};
  std::cout << most_frequent(test) << std::endl;
  return 0;
}

