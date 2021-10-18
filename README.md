# Buy low, sell high

Run TestTrade.cpp.

e.g. g++ -std=c++11 -o TestTrade TestTrade.cpp, then ./TestTrade (Unix) or TestTrade (Windows).

Run ItemTest.cpp.

e.g. g++ -std=c++11 -o ItemTest ItemTest.cpp, then ./ItemTest (Unix) or ItemTest (Windows).

Run TestCircularBuffer.cpp.

e.g. g++ -std=c++11 -o TestCircularBuffer TestCircularBuffer.cpp, then ./TestCircularBuffer (Unix) or TestCircularBuffer (Windows).

The price of a given commodity can be represented by a vector of prices.  For instance:

`vector<int> prices {28, 18, 20, 26, 24};`  

To maximise profit, we would want to buy low and sell high -- in this case, buy at time 1 (when the cost is 18), sell at time 3 (when the cost is 26).

In `Trade.h` is a function `bestBuySellTime` that takes a vector of prices and returns a `Trade` object with the buy and sell time that maximises profit.  This function does not live inside any class -- it is to be defined as a global function.

## Usage

To perform some basic testing on this code, `TestTrade.cpp` defines a simple test harness for the function `bestBuySellTime`. 

A wider range of test cases can be used, including input vectors that contains millions of numbers -- my code is able to handle these with modest resources (10 seconds of CPU on a desktop machine, and 0.5GB of RAM).  

# Treasure hunt

Code to work with data about items that are placed at different places on a map, each of which is available for just 15 minutes starting at a certain number of seconds past the hour.

Items are described by four properties:

- Their latitude (a number in degrees, e.g. 51.75087595155126)
- Their longitude (a number in degrees, e.g. -0.33483137537806396)
- A string ID
- The time at which they become available: an integral number of seconds past the hour

In Item.h is a class Item that contains these as private member variables.

The `operator<<` function in Item.h is for printing out Item objects, so that the following code will work:

`Item strand(51.5115, -0.116, "StrandCampus", 600);`  
`cout << strand << endl;`  

...and will produce output of the form:

`{latitude, longitude, "ID", time}`

...in this case:

`{51.5115, -0.116, "StrandCampus", 600}` 

A class function `distanceTo` takes another Item, and returns the distance to it in metres.  To compute this distance the [Haversine Formula](http://andrew.hedges.name/experiments/haversine/) is used, implemented using the following pseudo-code:

`dlon = lon2 - lon1`  
`dlat = lat2 - lat1`  
`a = pow((sin(dlat/2)), 2) + cos(lat1) * cos(lat2) * pow((sin(dlon/2)), 2)`  
`c = 2 * atan2( sqrt(a), sqrt(1-a) )`  
`distance = R * c (where R is the radius of the Earth)`  

Note that this pseudo-code assumes the latitude and longitude are in *radians*, whereas my class stores them in degrees - they are converted to radians first. I assume `R`, the radius of the earth in metres, is 6373000.

## Usage

In Item.h is a class Item.

To test this code, you can compile and run `ItemTest.cpp`.

# A circular buffer

Circular buffers use a fixed-size block of memory to temporary buffer data.  For instance, keypresses on the keyboard put characters in the buffer; and when the operating system is ready to process them, it reads characters from the buffer.


The buffer starts as being empty.  For instance, if we had a buffer of size 5 it would look like:

`[   |   |   |   |   ]`  


If we then write 'a' and 'b' into the buffer it would look like:

`[ a | b |   |   |   ]`  


...and then removing the next item in the buffer would give:

`[   | b |   |   |   ]`  


If we continue to write elements into the buffer, e.g. 'c', 'd', 'e', 'f' then when the end is reached, elements start being written into any spare space at the start:

`[ f | b | c | d | e ]`  


At this point the buffer is full.  We can't write any more data to it -- in the case of keyboard buffers, the computer would start beeping.  We can remove an element though, which always removes the *oldest*, i.e. the letter 'b', which would leave the buffer:

`[ f |   | c | d | e ]`  

We could then remove the next element (c), or as there is now a space again, write another character into the buffer.

It has the functions:  
1. `count()` which returns how many things are in the buffer  
2. `full()` which returns true *iff* the buffer is full  
3. `add()` which takes a character and adds it to the buffer (you can assume the buffer is not full -- you do not need to implement error handling)  
4. `remove()` which removes and returns the next character from the buffer (you can assume the buffer is not empty -- you do not need to implement error handling)  

## Usage

In the file `CircularBuffer.h` is a definition of the CircularBuffer class. The implementation is based on a vector of characters.

To test this code, you can compile and run `TestCircularBuffer.cpp`.
