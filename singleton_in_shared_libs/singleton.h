/*
 * singleton.h
 *
 *  Created on: 2011-12-24
 *      Author: bourneli
 */

#ifndef SINGLETON_H_
#define SINGLETON_H_

struct MyData
{
    int num;
};

template <class T>
class SingletonT
{
  /// \brief Get an instance of the singleton
  public: static T& instance()
  {
    return GetInstance();
  }

  /// \brief Constructor
  protected: SingletonT() {}

  /// \brief Destructor
  protected: virtual ~SingletonT() {}

  /// \brief Creates and returns a reference to the unique (static) instance
  private: static T &GetInstance()
  {
    static T t;
    return static_cast<T &>(t);
  }
};


using singleton = SingletonT<MyData>;

// Commenting this line out makes it so that there are two instances of the 
// singleton.
// extern template class SingletonT<MyData>;

#endif /* SINGLETON_H_ */
