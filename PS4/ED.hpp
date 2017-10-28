// Copyright 2015 Adam Melle
#ifndef _HOME_ADAM_ED_H_
#define _HOME_ADAM_ED_H_
#include <string>
#include <vector>

class EditDistance {
 public:
    EditDistance(std::string s1, std::string s2);
    ~EditDistance();
    static int penalty(char a, char b);   // returns penalty for aligning
                                          // chars a and b (this will be
                                          // a 0 or a 1)
    static int my_min(int a, int b, int c);  // returns the minimum of
                                          // the three arguments.
    int OptDistance();   // populates the matrix based on having the two
                         // strings, and returns the optimal distance
                         // (from the[0][0]cell of the matrix when done)
    std::string Alignment();  // traces the matrix and returns a string that
                         // can be printed to display actual alignment

 private:
    int **matrix;  // will be a 2d array once constructed
    int s1L, s2L;
    std::string str1, str2;
};
#endif  // _HOME_ADAM_ED_H_
