
/**********************************************************************
 *  readme.txt template                                                   
 *  Plucking a Guitar String
 **********************************************************************/

Name: Adam Melle
CS Login:


Hours to complete assignment (optional):


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
I successfully completed the assignment. I think all parts are working
and I tested the program using the BOOST file provided. I also wrote my
own testing code that would print out the index of the key being pressed,
and would also print the frequency sent to the GuitarString constructor
after using the 440 * 2^((i-24)/12) formula and every index matched the
correct frequency. When running my program only the keys that are meant
to play a sound do, and the ones that aren't don't crash the program.

And then as for the RingBuffer portion of the assignment, I already knew
it was working because of the passing unit tests I ran on it.



/**********************************************************************
 *  Did you attempt the extra credit parts? Which one(s)?
 *  Successfully or not?  As a pair, or individually?
 *  If you completed the AutoGuitar, what does it play?
 **********************************************************************/



/**********************************************************************
 *  Does your GuitarString implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/
My GuitarString passes the unit tests. The tests utilize the constructor
that accepts a vector of Int16's. That constuctor will then enqueue each
Int16 in the vector to the Ringbuffer. Now the unit test will call the
sample function which will peek the front of the RingBuffer. If the value
at the front is equal to what the unit test is looking for it will move on,
which it does. Then the tic function is called which will dequeue the first
element and perform the calculation .996*((popped + peek)/2), where popped
is the dequeued value and peek is the next element in front. Then it will
repeat the same thing comparing each front value. Once the tests are done
it will print the number of errors, which is 0 in my case.



/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
none


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
none


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
