I did this exact same implementation last year in Olga Lepsky's class when we were
studying abstract data types. Basically I had a variable to hold the index of the
first and last element in the buffer. Then everytime something was enqueued or dequeued
I checked to see if the next element to increment to was the last of the array, and if
it was I would loop that index back around to index 0. I would also do the conditional
checks to see if the buffer was full or empty when necessary.

I tested my implementation with a main function as I added to the code, making sure every
function was working as I went through. Then I used the boost library afterwards to make
sure every function worked in every situation I could think of.

I'm not exactly sure how time compares to dynamically allocating memory as you go to allocating
everything in the start like we did in this program. I feel like space wise it would be better
to allocate when you need it, but time wise it probably slows down the program a lot when it has
to constantly allocate new space. Using a ring buffer definitely makes things faster too. If
I used a linear implementation, where everytime I dequeued I had to shift all the elements back,
it would drastically increase the operation time when running this program with a large buffer.
Since we used a ring buffer, it circles around to the first index when it hits the end of the
array and doesn't have to do any shifting. So I guess in my implementation time wise would be
O(1) since the amount of time doesn't change no matter how big the ring is. Every operation is
the same and they don't change when the ring gets bigger. If I were shifting index positions
in a linear buffer it would be O(n) because as the ring gets bigger I have to shift more and
more elements.
