//
//  main.cpp
//  hw3_2
//
//  Created by Tong Tian on 2017/10/27.
//  Copyright © 2017年 Tong Tian. All rights reserved.
//

#include <Rcpp.h>
#include <iostream>
#include <string>

using namespace Rcpp;
using namespace std;

//////////////////////////////////////////////////////////////////////////////
// editDistance() function
// - Note that this is not an Rcpp function, but a function
//   only called within C++
// - Arguments:
//   > s1 : The first (reference) string to align
//   > s2 : The second (alternative) string to align
//   > cost : A matrix to contain cost to each node (negative if not stored)
//   > move : A matrix to contain the optimal move to each node (negative if not stored)
//   > r  : row    index (0..s1.size()), indicating the position in s1
//   > c  : column index (0..s1.size()), indicating the position in s2
//   > mcost : cost of single letter mismatch
//   > icost : cost of single latter insertion/deletion
// - Return value:
//   > the optimal edit distance
// - Expected behavior:
//   > cost matrix will store the optimal cost from (0,0)...(r,c)
//   > move matrix will store the optimal previous move from (0,0)...(r,c)
//////////////////////////////////////////////////////////////////////////////
int editDistance(string& s1, string& s2, IntegerMatrix& cost, IntegerMatrix& move, int r, int c, int mcost, int icost) {
    ////////////////////////////////////////////////////////
    // TODO : FILL IN THE BLANK to satisfy the specs above
    ////////////////////////////////////////////////////////
    if (cost(r, c) < 0) {
        if (r == 0) {
            if (c == 0) {
                cost(r, c) = 0;
            }
            else {
                cost(r, c) = editDistance(s1, s2, cost, move, r, c-1, mcost, icost) + icost;
                move(r, c) = 1;
            }
        }
        else {
            if (c == 0) {
                cost(r, c) = editDistance(s1, s2, cost, move, r-1, c, mcost, icost) + icost;
                move(r, c) = 2;
            }
            else {
                int m = editDistance(s1, s2, cost, move, r-1, c-1, mcost, icost) + (s1[r-1] != s2[c-1]) * mcost;
                int i = editDistance(s1, s2, cost, move, r, c-1, mcost, icost) + icost;
                int d = editDistance(s1, s2, cost, move, r-1, c, mcost, icost) + icost;
                if (m > i) {
                    if (i < d) {
                        cost(r, c) = i;
                        move(r, c) = 1;
                    }
                    else {
                        cost(r, c) = d;
                        move(r, c) = 2;
                    }
                }
                else {
                    if (m < d) {
                        cost(r, c) = m;
                        move(r, c) = 3;
                    }
                    else {
                        cost(r, c) = d;
                        move(r, c) = 2;
                    }
                }
            }
        }
    }
    return cost(r, c);
}

/////////////////////////////////////////////////////////////////////////
// alignWords() function (Exported by Rcpp)
// - Arguments:
//   > s1 : The first (reference) string to align
//   > s2 : The second (alternative) string to align
//   > mcost : Cost of single letter mismatch
//   > icost : Cost of single latter insertion/deletion
// - Return values: A List containing the following attributes:
//   > distance  : Optimal edit distance between the string
//   > first     : A modified version of the first string to include gaps
//                 as '-' so that attributes have same length
//   > alignment : Alignment between letters
//   >             '.' indicates match,
//   >             '*' indicates mismatch,
//   >             'I' indicates insertion from first to second string
//   >             'D' indicates insertion from first to second string
//   > second    : A modified version of the first string to include gaps
//                 so that attributes have same length
//
//   For example, an example can be
//   distance  : 6
//   first     : ALGORI-THM
//   alignment : ..***.I.**
//   second    : ALTRUISTIC
//////////////////////////////////////////////////////////////////////////
// [[Rcpp::export]]
List alignWords(string s1, string s2, int mcost, int icost) {
    ////////////////////////////////////////////////////////
    // TODO : FILL IN THE BLANK to satisfy the specs above
    ////////////////////////////////////////////////////////
    int r = s1.size();
    int c = s2.size();
    IntegerMatrix cost(r+1, c+1);
    IntegerMatrix move(r+1, c+1);
    fill(cost.begin(), cost.end(), -1);
    fill(move.begin(), cost.end(), -1);
    int dist = editDistance(s1, s2, cost, move, r, c, mcost, icost);
    string first, alignment, second;
    while (r > 0 || c > 0) {
        if (move(r, c) == 1) {
            alignment = "I" + alignment;
            first = "-" + first;
            second = s2[c-1] + second;
            c--;
        }
        else if (move(r, c) == 2) {
            alignment = "D" + alignment;
            first = s1[r-1] + first;
            second = "-" + second;
            r--;
        }
        else {
            if (s1[r-1] == s2[c-1]) {
                alignment = "." + alignment;
            }
            else {
                alignment = "*" + alignment;
            }
            first = s1[r-1] + first;
            second = s2[c-1] + second;
            r--;
            c--;
        }
    }
    return List::create(Named("distance") = dist, Named("first") = first, Named("alignment") = alignment, Named("second") = second);
}

