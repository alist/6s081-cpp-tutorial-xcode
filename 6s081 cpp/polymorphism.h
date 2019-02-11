//
//  polymorphism.h
//  6s081 cpp
//
//  Created by Alexander H List on 2/11/19.
//  Copyright © 2019 Alexander H List. All rights reserved.
//

#ifndef polymorphism_h
#define polymorphism_h

class BaseClass {
 public:
  std::string nonVirtualFavoriteString(){
    return "BaseClass nonVirtualFavoriteString";
  }
  
  virtual std::string virtualFavoriteString(){
    return "BaseClass virtualFavoriteString";
  }
};

/// Note 1: ChildClass AFTER BaseClass
///
/// Note 2: Must put public before BaseClass here
class ChildClass : public BaseClass {
 public:
  std::string nonVirtualFavoriteString() {
    return "ChildClass virtualFavoriteString";
  }
  
  std::string virtualFavoriteString() override {
    return "ChildClass virtualFavoriteString";
  }  
};

#endif /* polymorphism_h */
