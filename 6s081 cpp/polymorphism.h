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

class LifetimeTestee {
 public:
  LifetimeTestee() {
    std::cout << "I AM BORN!! \n";
  }
  
  ~LifetimeTestee() {
    std::cout << "I'm BEING DELETED!! \n";
  }
};

class ChildClass : public BaseClass {
 /// reps should be private anyway..
 private:
  /// Note A: Behold, unique_ptr, it only allows one (owner).
  ///         i.e. std::unique_ptr<std::vector<int>> myData = associatedData; leaves
  ///         associatedData without any internal pointer.
  ///         unique only has move constructor-- red EffModC++ pp49-51 for constructor basics.
  std::unique_ptr<std::vector<int>> associatedData = std::unique_ptr<std::vector<int>>(new std::vector<int>{});
  /// Note 1: AND Behold shared_ptr, it supports the copy and move constructor.
  ///         it deletes the underlying object when no copies of the shared_ptr exist anymore
  std::shared_ptr<LifetimeTestee> testeePtr = std::shared_ptr<LifetimeTestee>(new LifetimeTestee);
  
 public:
  ChildClass() {}
  
  std::string nonVirtualFavoriteString() {
    return "ChildClass virtualFavoriteString";
  }
  
  std::string virtualFavoriteString() override {
    return "ChildClass virtualFavoriteString";
  }
  
  ~ChildClass(){
    std::cout << "deleting ChildClass and associatedData \n";
    // Note C: smart pointers automatcially freed with *destruction* of the object!
  }
};

#endif /* polymorphism_h */


