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
  /// Note 1: this makes sure we're converting using parent class ABI -- this case,
  /// using explicitly definined conversions or using constructor
  BaseClass * object = static_cast<BaseClass*>(new ChildClass());
  std::cout << object->nonVirtualFavoriteString() << std::endl;
  std::cout << object->virtualFavoriteString() << std::endl;
  /// Note 2: static_cast downcast would work HERE, but wouldn't in all cases
  ///         i.e. ChildClass * childCastedObject = static_cast<ChildClass*>(object);
  /// Note 3: Dynamic cast is preferred (not to 6.031 paradigms), but requires ≥ 1 virtual method in BaseClass
  ChildClass * childCastedObject = dynamic_cast<ChildClass*>(object);
  delete childCastedObject;
  
  return 0;
}


