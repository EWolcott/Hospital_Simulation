#include "hash.h"

template <typename T>
cs273::Hash<T>::Hash()
{
    data.resize(2000);     //set size
    hashtable_size = 2000; // set variable value
}

template <typename T> //copy contructor
cs273::Hash<T>::Hash(int size)
{
    data.resize(size);     //set size
    hashtable_size = size; // set variable value
}
template <typename T>
cs273::Hash<T>::Hash(const Hash<T> &other)
{
    data.resize(other.data.size());        //copy size to accomodate
    hashtable_size = other.hashtable_size; //copy variable
    data = other.data;                     //copy data value
}

template <typename T> //hash function
int cs273::Hash<T>::hash_it_up(std::string key)
{
    int index = 0;
    int hash = 0;
    for (int i = 0; i < key.length(); i++)
    {
        hash += (int)key[i]; //obtain values of letters
    }
    index = (hash % hashtable_size); //mod it by 20 to fit in data table
    return index;                    //return position in the vector
}

template <typename T> //insert based on pair
typename std::list<pair<T>>::iterator cs273::Hash<T>::insert(pair<T> item)
{
    int index;
    index = hash_it_up(item.first);                                 //obtain vector placement
    data[index].push_back(item);                                    //add to linked list
    typename std::list<pair<T>>::iterator iter = data[index].end(); //return iterator for item added
    return iter;
}

template <typename T> //remove based on pair
bool cs273::Hash<T>::remove(const pair<T> &item)
{
    int index;
    index = hash_it_up(item.first); //find vector placement
    typename std::list<pair<T>>::iterator j;
    for (j = data[index].begin(); j != data[index].end(); j++)
    {
        if (j->first == item.first && j->second == item.second)
        { //find the value i the linked list
            data[index].erase(j);
            return true;
        }
    }
    return false;
}

template <typename T> //print table contents
void cs273::Hash<T>::displayHash()
{
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << i;
        typename std::list<pair<T>>::iterator j;
        for (j = data[i].begin(); j != data[i].end(); j++)
        {
            std::cout << " --> " << j->first << " " << j->second;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template <typename T> //remove based on key
bool cs273::Hash<T>::remove(const std::string &key)
{
    int index;
    index = hash_it_up(key); //find vector placement
    typename std::list<pair<T>>::iterator j;
    for (j = data[index].begin(); j != data[index].end(); j++)
    {
        if (j->first == key)
        { //find value in linked list
            data[index].erase(j);
            return true;
        }
    }
    return false;
}

template <typename T> //locate based on pair
typename std::list<pair<T>>::iterator cs273::Hash<T>::locate(const pair<T> &item)
{
    int index;
    index = hash_it_up(item.first); //find vector placement
    typename std::list<pair<T>>::iterator j = data[index].begin();
    for (j = data[index].begin(); j != data[index].end(); j++)
    {
        if (j->first == item.first)
        { //find linked list placement

            return j;
        }
    }
    std::cout << "not found" << std::endl;
    return j;
}

template <typename T> //locate based on key
typename std::list<pair<T>>::iterator cs273::Hash<T>::locate(const std::string &key)
{
    int index;
    index = hash_it_up(key); //find vector placement
    typename std::list<pair<T>>::iterator j = data[index].begin();
    for (j = data[index].begin(); j != data[index].end(); j++)
    {
        if (j->first == key)
        { //find linked list placement

            return j;
        }
    }
    std::cout << "not found" << std::endl;
    return j;
}


