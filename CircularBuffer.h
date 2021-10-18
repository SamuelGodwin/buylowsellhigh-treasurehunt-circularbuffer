#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H


#include <vector>
using std::vector;


/** TODO: complete the definition of the class CircularBuffer here
 *
 * Its constructor should take the size of the buffer as an argument
 *
 * It needs to have the functions:
 * - count() which returns how many things are in the buffer
 * - full() which returns true iff the buffer is full
 * - add() which takes an element and adds it to the buffer (you can assume the buffer is not full)
 * - remove() which removes the next element from the buffer (you can assume the buffer is not empty)
 */
class CircularBuffer {

	vector<char> vectorOfChars;
	int capacity;
	//you'll never need more than 5
	//store the size to tell if its full

	// PROBABLY BETTER TO USE UNIQUE_PTRS:
	//char * head; // first pointer points to the first stored element of vector
	//char * tail; // second pointer points to first empty position of vector

	// Ensure you use the initialisation syntax with your constructor to appropriately initialise the vector to be the right size.

public:

	CircularBuffer(int capacityIn)
	: capacity(capacityIn) { //vectorOfChars.reserve(capacity);
	}
    
	// There should be no default constructor. <- ? is this already handled now?


    //count() which returns how many things are in the buffer
	int count() {
		return vectorOfChars.size();
	}
    //full() which returns true iff the buffer is full
	bool full() {
		if (!(vectorOfChars.size() < capacity)) { // if current size is not less than total capacity
			return true; // buffer is full
		}
		return false;

	}
    //add() which takes a character and adds it to the buffer (you can assume the buffer is not full -- you do not need to implement error handling)
	void add(char & c) {
		// When the element is added to the structure, the second index is incremented
		vectorOfChars.push_back(c);
		//tail++; //? increment this pointer as an iterator.
	}
    //remove() which removes and returns the next character from the buffer (you can assume the buffer is not empty -- you do not need to implement error handling)
	char remove() {
		// When the first element of the array is polled (removed), the first element is incremented and the position is nulled (and the element is destructed).
		//char temp = *head;
		//*head = null; // ? want to make the position null but haven't looked up the syntax juts yet.
		// element destructed

		char temp = vectorOfChars.front();

		vectorOfChars.erase(vectorOfChars.begin());

		return temp;


		//head++; //? increment this pointer as an iterator...






		return temp;

	}

};


// don't write any code below this line

#endif
