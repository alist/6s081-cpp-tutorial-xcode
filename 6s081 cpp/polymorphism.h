//
//  polymorphism.h
//  6s081 cpp
//
//  Created by Alexander H List on 2/11/19.
//  Copyright © 2019 Alexander H List. All rights reserved.
//

#ifndef polymorphism_h
#define polymorphism_h
#include <vector>

class BaseClass {
 public:
  std::string nonVirtualFavoriteString(){
    return "BaseClass nonVirtualFavoriteString";
  }
  
  virtual std::string virtualFavoriteString(){
    return "BaseClass virtualFavoriteString";
  }
  
  virtual ~BaseClass(){
    std::cout << "deleting BaseClass \n";
  }
};

class ChildClass : public BaseClass {
 /// reps should be private anyway..
 private:
  /// Note A: Behold, unique_ptr, it only allows one
  /// Note B: According to https://en.cppreference.com/w/cpp/language/default_initialization
  ///         class types like (smart pointers) are default initialized,
  ///         but that does not mean their internals are too!!
  std::unique_ptr<std::vector<int>> associatedData;
  
 public:
  ChildClass() {
    //     associatedData->push_back(1); would fail until we do the next line...
    associatedData = std::unique_ptr<std::vector<int>>(new std::vector<int>{});
  }
  
  std::string nonVirtualFavoriteString() {
    return "ChildClass virtualFavoriteString";
  }
  
  std::string virtualFavoriteString() override {
    return "ChildClass virtualFavoriteString";
  }
  
  ~ChildClass(){
    std::cout << "deleting ChildClass and associatedData \n";
    // Note C: smart pointers automatcially freed with deletion of the object!
    // Note D: Delete (for c++ objects) calls the ~Destructor before calling unix dealloc
    //          with unix dealloc necessarily cleaning the memory,
    //          do you need virtual destructor when you have smart pointers??
  }
};

#endif /* polymorphism_h */


