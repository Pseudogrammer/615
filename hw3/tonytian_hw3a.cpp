//
//  main.cpp
//  hw3a
//
//  Created by Tong Tian on 2017/10/27.
//

#include <Rcpp.h>
#include <map>
#include <algorithm>

using namespace Rcpp;
using namespace std;

///////////////////////////////////////
// Skeleton code for Homework 3A
///////////////////////////////////////

// function to calculate factorial
int fac(int n) {
    if ( n < 2 ) return 1; // return 1 when n=0,1
    int ret = 1;
    for(int i=2; i <= n; ++i)
        ret *= i;  // calculate factorial
    return ret;
}

// compute choose(n,k) using factorial
// [[Rcpp::export]]
int choose_fac(int n, int k) {
    return fac(n)/fac(k)/fac(n-k);
}

int dp(int n, int k, NumericMatrix& M) {
    if ( M(n, k) < 0 )  {
        if ( ( k==0 ) || ( k==n ) ) {
            M(n, k) = 1;
        }
        else {
            M(n, k) = dp(n-1, k, M) + dp(n-1, k-1, M);
        }
    }
    return M(n, k);
}

// compute choose(n,k) using dynamic programming
// [[Rcpp::export]]
int choose_dp(int n, int k) {
    ///////////////////////////////////////////////////
    // TODO: FILL IN THE BLANK to return choose_dp(n,k)
    // following the dynamic programming algorithm.
    // You may define an additional function.
    //////////////////////////////////////////////////
    if ( k > n ) {
        return 0;
    }
    NumericMatrix M(n+1, k+1);
    fill(M.begin(), M.end(), -1);
    return dp(n, k, M);
}

