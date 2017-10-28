1;3201;0c/**********************************************************************
 *  readme template                                                   
 *  DNA Sequence Alignment
 **********************************************************************/

Name: Adam Melle
Login: ?


Hours to complete assignment (optional): 12+



/**********************************************************************
 *  Explain what you did to find the alignment itself.
 **********************************************************************/
I used the Needleman-Wunsch algorithm to find the edit distance with a
matrix and then used the algorithm to backtrack through the matrix to
align the two strings.


/**********************************************************************
 * Does your code work correctly with the endgaps7.txt test file? 
 * 
 * This example should require you to insert a gap at the beginning
 * of the Y string and the end of the X string.
 **********************************************************************/
Input:

atattat
tattata

Expected output:

Edit distance = 4
a - 2
t t 0
a a 0
t t 0
t t 0
a a 0
t t 0
- a 2


What happened:

It worked!

Edit distance = 4
a - 2
t t 0
a a 0
t t 0
t t 0
a a 0
t t 0
- a 2




/**********************************************************************
 *  How much main memory does your computer have? Typical answers
 *  are 2 GB to 16 GB.
 **********************************************************************/
8GB


/**********************************************************************
 *  For this question assume M=N. Look at your code and determine
 *  approximately how much memory it uses in bytes, as a function of 
 *  N. Give an answer of the form a * N^b for some constants a 
 *  and b, where b is an integer. Note chars are 2 bytes long, and 
 *  ints are 4 bytes long.
 *
 *  Provide a brief explanation.
 *
 *  What is the largest N that your program can handle if it is
 *  limited to 8GB (billion bytes) of memory?
 **********************************************************************/
I set "b" as 2 because when creating a matrix with two equal strings
the matrix size will be M*N so since they are the same value N^2 will
work. I set "a" as 4 because it's the number of bytes in an int, and
my matrix only contains ints. So as you can see below, ecoli10000.txt used 382MB, so
4*10000^2 = 400,000,000 bytes = 400MB, so the calculation is pretty close. So
25,000 length would be about 1GB, so 200,000 would be about 8GB and would be
the largest N.
a = 4
b = 2
largest N = 200,000

/**********************************************************************
 *  Were you able to run Valgrind's massif tool to verify that your
 *  implementation uses the expected amount of memory?
 *
 *  Answer yes, no, I didn't try, I tried and failed, or I used a 
 *  different tool.
 *
 *  If yes, paste in the ms_print top chart of memory use over time,
 *  and also indicate which file your code was solving.
 * 
 *  Explain if necessary.
/**********************************************************************
yes
ecoli10000.txt

MB
382.0^                                                                       :
     |:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::#
     |:      :                                                               #
     |:      :                                                               #
     |:      :                                                               #
     |:      :                                                               #
     |:      :                                                               #
     |:      :                                                               #
     |:      :                                                               #
     |:      :                                                               #
     |:      :                                                               #
     |:      :                                                               #
     |:      :                                                               #
     |:      :                                                               #
     |:      :                                                               #
     |:      :                                                               #
     |:      :                                                               #
     |:      :                                                               #
     |:      :                                                               #
     |:      :                                                               #
   0 +----------------------------------------------------------------------->Gi
     0                                                                   14.94



/**********************************************************************
 *  For each data file, fill in the edit distance computed by your
 *  program and the amount of time it takes to compute it.
 *
 *  If you get segmentation fault when allocating memory for the last
 *  two test cases (N=20000 and N=28284), note this, and skip filling
 *  out the last rows of the table.
 **********************************************************************/

data file           distance       time (seconds)     memory (MB)
------------------------------------------------------------------
ecoli2500.txt	      118		0.141		23.97
ecoli5000.txt	      160		0.527		95.61
ecoli7000.txt	      194		1.023		187.3
ecoli10000.txt	      223		2.062		382.0
ecoli20000.txt	      3135		8.711		1491.0
ecoli28284.txt        8394		17.667		2982.0

Fill out the data here first, then go to the assignment web page for
instructions on sharing your data on iSENSE.

/*************************************************************************
 *  Here are sample outputs from a run on a different machine for 
 *  comparison.
 ************************************************************************/

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt          118             0.171
ecoli5000.txt          160             0.529
ecoli7000.txt          194             0.990
ecoli10000.txt         223             1.972
ecoli20000.txt         3135            7.730

/**********************************************************************
 *  Enter your data onto iSENSE per the directions on the course web
 *  site. Then, paste a URL to your data set here.
 *
 *  YOU WILL ONLY RECEIVE CREDIT FOR YOUR iSENSE WORK IF YOU PROVIDE
 *  THE URL HERE.
 *
 *  e.g.: http://isenseproject.org/projects/871/data_sets/7893
 ************************************************************************/

http://isenseproject.org/projects/871/data_sets/8029

/**********************************************************************
 *  For this question assume M=N (which is true for the sample files 
 *  above). By applying the doubling method to the data points that you
 *  obtained, estimate the running time of your program in seconds as a 
 *  polynomial function a * N^b of N, where b is an integer.
 *  (If your data seems not to work, describe what went wrong and use 
 *  the sample data instead.)
 *
 *  Provide a brief justification/explanation of how you applied the
 *  doubling method.
 * 
 *  What is the largest N your program can handle if it is limited to 1
 *  day of computation? Assume you have as much main memory as you need.
 **********************************************************************/
By finding out what "a" is using an already calculated time above, I
can create the equation .00000002 * N^2 to estimate a time. As you can
see, .00000002 * 200000^2 = 8 seconds, which is close to what I got above. Now
I can apply this formula to find the largest N possible in 86400 seconds(one day)

a = .00000002
b = 2
largest N = around 2,078,000 which is 86361 seconds

/**********************************************************************
 *  List whatever help (if any) you received from the course TAs,
 *  instructor, classmates, or anyone else.
 **********************************************************************/
none


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
Not a serious problem, but some strings were so long that the buffer runs
out and you can't scroll up far enough to see what the edit distance was.
So I just had it print the edit distance last temporarily.


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
The two questions calculating memory and time were not explained very well.
I think I did them correctly but I'm not sure.

