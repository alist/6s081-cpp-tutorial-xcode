//
//  main.cpp
//  6s081 cpp
//
//  Created by Alexander H List on 2/11/19.
//  Copyright © 2019 Alexander H List. All rights reserved.
//

#include <iostream>
#include "polymorphism.h"


void doCoolStuff() {
  // Note 1: Make sure you understand const, it's immutability to help make nice interfaces
  const auto vec = std::vector<int>{1, 2, 3, 4, 5};
  
  // Note 2: This is a c++ lambda, inside [] are capture semantics,
  //         &vec means pass vec by reference it's also possible to use = to copy construct
  // Note 3: More on lambdas from pp215 of EffModC++. You should almost definitely use them.
  auto announceItem = [&vec](int val) {
    std::cout << "item " << val << " of " << vec.size() << " items \n";
  };
  
  // range based for loop
  for (auto && item : vec) {
    announceItem(item);
  }
}

int main(int argc, const char * argv[]) {
  // insert code here...
  //std::cout << "Hello, World!\n";
  
  doCoolStuff();
  
  // Not the c++ 11 way -- use smart pointers and auto
  // Note 4: Last note. If ever auto is giving you grief, just switch back to defining your types.
  // There's no great way to inspect the inferred type (besides using the `boost` C++ libraries methods)
  auto object = std::unique_ptr<BaseClass>(new ChildClass());
  std::cout << object->nonVirtualFavoriteString() << std::endl;
  std::cout << object->virtualFavoriteString() << std::endl;
  
  return 0;
}


