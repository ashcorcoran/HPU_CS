
#ifndef H_orderedArrayListType
#define H_orderedArrayListType
  
#include "arrayListType.h" 
#include <string>

class orderedArrayListType: public arrayListType
{
public:
    void insertAt(int location, string insertItem);
    void insertEnd(string insertItem);
    void replaceAt(int location, string repItem);
    int seqSearch(string searchItem) const;
    void insert(string insertItem);
    void remove(string removeItem);

    orderedArrayListType(int size = 100);
       //Constructor
};

#endif
