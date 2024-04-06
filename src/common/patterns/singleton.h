//
// Created by Lucas Agullo on 25-03-24.
//

#ifndef SINGLETON_H
#define SINGLETON_H

// Singleton base class
template <typename T>
class Singleton {
 protected:
  Singleton() {}
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;

 public:
  static T& Instance() {
    static T instance;
    return instance;
  }
};

#endif  //SINGLETON_H
