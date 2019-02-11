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
  /// Note B: According to https://en.cppreference.com/w/cpp/language/default_initialization
  ///         class types like (smart pointers) are default initialized,
  ///         but that does not mean their internals are too!!
  std::unique_ptr<std::vector<int>> associatedData;
  /// Note 1: AND Behold shared_ptr, it supports the copy and move constructor.
  ///         it deletes the underlying object when no copies of the shared_ptr exist anymore
  /// Note 2: If you run now, you'll see it is not "BORN".
  std::shared_ptr<LifetimeTestee> testeePtr;
  
 public:
  ChildClass() {
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
    
    //
    // YES. Otherwise child objects don't get dumped.
    // NOTE E: When rolling polymorphic, use virtual destructors.
  }
};

#endif /* polymorphism_h */


