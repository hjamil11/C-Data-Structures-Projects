doxygen site link: 
https://kuvapcsitrd01.kutztown.edu/~hahme858/

Container:
1. WordVectorList:
    - Description: This subclass contains the function implementations to parse the file and print the list iteratively and recursively.
    - Reasons for choosing vector:
        a. Vector is faster dealing with smaller than other type of lists
        b. It is faster to push elements at the back
        c. Vector works faster to find an element because when accessing an element
           the next element is in the cache automatically. Moreover, the main memory
           is slower than the cache.

Known bugs:
Using the iterator in WordCList is not working.