Adam Melle

Basically, using the starter code that was provided, I used an algorithm to find the midpoints using _top _left _right of the first traingle(the invisible one). Then I decremented depth, checked to see if it was still greater than 0. If not the child nodes would be set to null. If so, I'd send p1 p2 and p3 to a new constructor where they would be passed as _top _left _right once again. This pattern was then recursed until the depth was equal to 0. Then in the draw function I recursed through all the child nodes checking if they are null and drawing them if they aren't. It was interesting to see how high of a depth I could set before the pixels in the screen were too big to create a triangle. I found this happened around depth 10 and beyond. The hardest part of this project was actually learning how to use linux and console commands. I've always used an IDE in windows and never had to deal with argc argv and compiler flags. I also got really annoyed with virtual box and ended up creating a linux partition right on my hard drive. Overall I still hate linux and it caused me more problems than my actual program. But in the end I guess I learned a lot and had fun when I actually got to code the assignment.

For my original program I used four coordinate points and recursively drew squares within themselves. I randomly generated a custom color every iteration and set the outline color and fill color with it. I used the same recursion method but with different points and different algorithms to calculate midpoints.

Analysis of how much memory each of the programs uses, depending on depth.

I've never done this before. Is there a tool I can use to calculate this? I know you can check memory usage in task manager on windows but I don't know how to on linux. I also have never heard of stack frames and have no idea how to calculate this.  


I invested probably 10+ hours trying to get linux to work correctly and about 4 hours working on the assigment.
