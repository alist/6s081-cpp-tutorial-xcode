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
  /// NOTE 1: Can't use auto easily for member variables, not even private ones, unfortunately
  std::unique_ptr<std::vector<int>> associatedData = std::unique_ptr<std::vector<int>>(new std::vector<int>{});
  
 public:
  ChildClass() {}
  
  std::string nonVirtualFavoriteString() {
    return "ChildClass virtualFavoriteString";
  }
  
  std::string virtualFavoriteString() override {
    // Note 2: Can use auto inside methods to make your life better...
    auto testeePtr = std::shared_ptr<LifetimeTestee>(new LifetimeTestee); // unique_ptr is prolly faster, but don't sweat it
    std::cout << "Printing something here just to really illustrate the smart ptr deletes AFTER the end of the function\n";
    // Note 3: And yes, this didn't really need to be a pointer at all. Could have been a local. EXCEPT: We can return testeePtr and the underlying
    //          object would still exist on the heap until the smart pointer is dropped.
    return "ChildClass virtualFavoriteString";
  }
  
  ~ChildClass(){
    std::cout << "deleting ChildClass and associatedData \n";
    // Note C: smart pointers automatcially freed with *destruction* of the object!
  }
};

#endif /* polymorphism_h */


