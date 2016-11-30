/* Frank M. Carrano, Data Abstraction & Problem Solving with C++, 
Walls & Mirrors, Fifth Edition, Pearson Education, Inc., 2007,  
p. 555. 
*/

/** @file KeyedItem.h */
typedef string KeyType;

/**  @class KeyedItem
 *   Search key class for the ADT binary search tree. */
class KeyedItem
{
public:
   KeyedItem() {}
   KeyedItem(const KeyType& keyValue)
      : searchKey(keyValue) {}
   KeyType getKey() const
   {  return searchKey;
   }  // end getKey
private:
   KeyType searchKey;
}; // end KeyedItem
