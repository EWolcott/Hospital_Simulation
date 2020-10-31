#ifndef HASH_H
#define HASH_H

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <typeinfo>
#include <list>
#include <pair.h>
//hash table class
namespace cs273
{
  template <typename T> //I was having a heck of a time iterating through the std::unorderd_map, so I just went
                        //with the custom one that I know works, figure it's the same idea memory-wise.
  class Hash
  {
  private:
   // std::vector<std::list<pair<T>>> data; // the hash table data
    int hashtable_size;                   // size of the table

  public:
   std::vector<std::list<pair<T>>> data; // the hash table data
  Hash();
    Hash(int size);                                                       //copy constructor with specified size
    Hash(const Hash<T> &other);                                           //copy constructor
    int hash_it_up(std::string key);                                      //hash function based on key
    typename std::list<pair<T>>::iterator insert(pair<T> item);           //insert a pair into table
    bool remove(const pair<T> &item);                                     //remove based on pair
    bool remove(const std::string &key);                                  //remove based on key
    void displayHash();                                                   //display contents
    typename std::list<pair<T>>::iterator locate(const pair<T> &item);    //find an item based on pair
     //typename std::list<pair<T>>::iterator printlist(const std::string &key);
    typename std::list<pair<T>>::iterator locate(const std::string &key); //find an item based on key
  };
} // namespace cs273
#include "hash.cpp"

#endif