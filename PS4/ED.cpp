// Copyright 2015 Adam Melle
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include "ED.hpp"

EditDistance::EditDistance(std::string s1, std::string s2) {
    s1L = (s1.length() + 1);  // Length of string 1 plus 1 for - char
    s2L = (s2.length() + 1);  // Length of string 2 plus 1 for - char
    str1 = s1;  // record string 1
    str2 = s2;  // record string 2
    int penalty = 0;

    // allocate space for the matrix
    matrix = new int*[s1L];
    for (int i = 0; i < s1L; i++) {
        matrix[i] = new int[s2L];
    }

    // initialize the array to zero and set the perimeter values
    for (int i = 0; i < s1L; i++) {
        for (int j = 0; j < s2L; j++) {
            matrix[i][j] = 0;
        }
    }
    for (int j = s2L-1; j >= 0; j--) {
        matrix[s1L - 1][j] = penalty;
        penalty += 2;
    }
    penalty = 0;
    for (int i = s1L-1; i >= 0; i--) {
        matrix[i][s2L - 1] = penalty;
        penalty += 2;
    }
}

EditDistance::~EditDistance() {
    for (int i = 0; i < s1L; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int EditDistance::penalty(char a, char b) {
    if (a == b)
        return 0;  // they match
    else
        return 1;  // they don't match
}

int EditDistance::my_min(int a, int b, int c) {
    int min = a;

    if (b < min)
        min = b;
    if (c < min)
        min = c;

    return min;
}

int EditDistance::OptDistance() {
    int pen;  // calculated penalty for match or mismatch

    // start at [s1L-2][s2L-2] since we already filled out the perimeter
    for (int i = s1L - 2; i >= 0; i--) {
        for (int j = s2L - 2; j >= 0; j--) {
            pen = penalty(str1[i], str2[j]);
            matrix[i][j] = my_min(matrix[i][j + 1] + 2,
                matrix[i + 1][j] + 2, matrix[i + 1][j + 1] + pen);
        }
    }

    return matrix[0][0];
}

std::string EditDistance::Alignment() {
    std::string combined;
    int match, i = 0, j = 0, asciichar;

    // start at cell[0][0]
    while (i < s1L - 1 || j < s2L - 1) {
        match = penalty(str1[i], str2[j]);  // see what the penalty is

        if ((i + 1) != s1L && matrix[i+1][j] == (matrix[i][j] - 2)) {
            // Check down: insert gap into str2
            combined += str1[i];
            combined += ' ';
            combined += '-';
            combined += ' ';
            combined += 50;
            combined += '\n';
            i++;
        } else if (i + 1 != s1L && j + 1 != s2L && matrix[i+1][j+1] ==
                                                 matrix[i][j] - match) {
            // Check Diagonal: no gaps
            combined += str1[i];
            combined += ' ';
            combined += str2[j];
            combined += ' ';
            if (match == 0) {
               asciichar = 48;
            } else {
                asciichar = 49;
              }
            combined += asciichar;
            combined += '\n';
            i++;
            j++;
        } else if (matrix[i][j+1] == (matrix[i][j] - 2)) {
            // Check right: insert gap into str1
            combined += '-';
            combined += ' ';
            combined += str2[j];
            combined += ' ';
            combined += 50;
            combined += '\n';
            j++;
        }
    }

    return combined;
}
