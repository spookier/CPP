#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <class T>
class Array
{
    private:
        T *array;
        unsigned int _size;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        Array &operator=(const Array &other);
        ~Array();

        unsigned int size() const;

        T &operator[](unsigned int i);

        class OutOfRange : public std::exception
        {
            const char *what() const throw();
        };
};

template <class T>
Array<T>::Array() : array(NULL), _size(0)
{
}

template <class T>
Array<T>::Array(unsigned int n) : array(new T[n]), _size(n)
{
}


template <class T> 
Array<T>::Array(const Array &other)
{
  this->array = new T[other.size()];

  for(unsigned int i = 0; i < other.size(); ++i)
  {
    this->array[i] = other.array[i];
  }

  this->_size = other._size;
}


template <class T>
Array<T> &Array<T>::operator=(const Array &other)
{
  if(this == &other)
    return(*this);

  delete[] this->array; // clean up existing memory

  this->array = new T[other.size()];

  for (unsigned int i = 0; i < other.size(); i++)
  {
    this->array[i] = other.array[i];
  }

    this->_size = other._size;
    return (*this);
}

template <class T>
Array<T>::~Array()
{
  delete[] this->array;
}

template <class T>
unsigned int Array<T>::size() const
{
  return (this->_size);
}

template <class T>
T &Array<T>::operator[](unsigned int i)
{
  if(i >= this->size())
  {
    throw OutOfRange();
  }
  return this->array[i];
}

template <class T>
const char* Array<T>::OutOfRange::what() const throw()
{
    return "Index is out of range.";
}


#endif
