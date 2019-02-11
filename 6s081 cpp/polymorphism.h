//
//  polymorphism.h
//  6s081 cpp
//
//  Created by Alexander H List on 2/11/19.
//  Copyright © 2019 Alexander H List. All rights reserved.
//

#ifndef polymorphism_h
#define polymorphism_h
/// Note A: You often need to do imports like this
#include <vector>

class BaseClass {
 public:
  std::string nonVirtualFavoriteString(){
    return "BaseClass nonVirtualFavoriteString";
  }
  
  virtual std::string virtualFavoriteString(){
    return "BaseClass virtualFavoriteString";
  }
  
  ~BaseClass(){
    std::cout << "deleting BaseClass \n";
  }
};

/// Note 1: ChildClass AFTER BaseClass
///
/// Note 2: Must put public before BaseClass here
class ChildClass : public BaseClass {
 public:
  std::vector<int>* associatedData;
  ChildClass() {
    associatedData = new std::vector<int>{10};
   }
  
  std::string nonVirtualFavoriteString() {
    return "ChildClass virtualFavoriteString";
  }
  
  std::string virtualFavoriteString() override {
    return "ChildClass virtualFavoriteString";
  }
  
  ~ChildClass(){
    std::cout << "deleting ChildClass and associatedData \n";
    // Note B:
    // you wouldn't have to do this if associatedData were a smart pointer,
    // or not a pointer
    delete associatedData;
  }
};

#endif /* polymorphism_h */
