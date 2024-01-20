/** @file abstract_bag.hpp 
 * @author Mitch McKain
 * @date 1/20/24
*/
#ifndef _ABSTRACT_BAG_HPP_
#define _ABSTRACT_BAG_HPP_

#include <cstdlib>

template<typename T>

/** @class AbstractBag
 * Serves as the base class for our future derived class */
class AbstractBag
{
    public:
        /** Default Contructor */
        AbstractBag();

        /** Destructor */
        ~AbstractBag();

        /** Gets the number of items in the bag at this time
         * @pre bag must exist
         * @return the number of items in the bag */
        virtual std::size_t getCurrentSize() const = 0;

        /** Determines if the bag is empty or not
         * @pre bag must exist
         * @return true if the bag has no items in it, or false if there are items inside */
        virtual bool isEmpty() const = 0;

        /** Adds an item to the bag, if there is still room
         * @pre bag must exist and not be at full capacity
         * @param entry is for the item to be placed into bag
         * @return bool that is true if item was successfully added, or false if there is no room to add item
         * @post a new item will be placed into the bag */
        virtual bool add(const T& entry) = 0;

        /** Removes all instances of a user specified item from the bag
         * @pre bag must exist
         * @param entry is what item will be removed from bag
         * @return True if item was successfully removed from bag, or false if item could not be removed
         * @post All instances of a user specified item should not longer exist in the bag */
        virtual bool remove(const T& entry) = 0;

        /** Removes all items from the bag
         * @pre bag must exist
         * @post the bag will be empty */
        virtual void clear() = 0;

        /** Gets the number of occurences of a specified item
         * @pre bag must exist
         * @param entry is for the item to be looking for in the bag
         * @return the number of times entry exists in the bag */
        virtual std::size_t getFrequencyOf(const T& entry) const = 0;

        /** Determines if the bag contains a specified item
         * @pre bag must exist
         * @param entry if the item to be looking for in the bag
         * @return true if that item exists in the bag, or false if the item doesnt exist in the bag */
        virtual bool contains(const T& entry) const = 0;
};


#endif