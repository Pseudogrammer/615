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
}
