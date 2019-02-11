//
//  main.cpp
//  6s081 cpp
//
//  Created by Alexander H List on 2/11/19.
//  Copyright © 2019 Alexander H List. All rights reserved.
//

#include <iostream>
#include "polymorphism.h"

int main(int argc, const char * argv[]) {
  // insert code here...
  //std::cout << "Hello, World!\n";
  
  /// Not the c++ 11 way
  BaseClass * object = new ChildClass();
  std::cout << object->nonVirtualFavoriteString() << std::endl;
  std::cout << object->virtualFavoriteString() << std::endl;
  /// Note 1: Now this works because ~BaseClass destructor is virtual
  delete object;
  
  return 0;
}


