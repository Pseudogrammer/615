////////////////////////////////////////////////////////////// // below is the skeleton of [your_uniqname]_hw1a.cpp file ////////////////////////////////////////////////////////////// #include <Rcpp.h>
#include <Rcpp.h>
#include <iostream>
#include <algorithm>
using namespace Rcpp;
using namespace std;
// [[Rcpp::export]]
NumericVector insertion_sort(NumericVector x) {
/*
Using insertion sort algorithm,
make x sorted and return it.
You may use the lecture slides or pseudo-code in the URL: https://www.toptal.com/developers/sorting-algorithms/insertion-sort to implement this function
*/
	int n = x.size();
	for (int i=1; i < n; i++){
		for (int j = i; x[j-1]>x[j] && j>=1; j--)
		{
			swap(x[j], x[j-1]);
		}
	}
	return x; 
}
// [[Rcpp::export]]
NumericVector bubble_sort(NumericVector x) {
/*
Using bubble sort algorithm,
make x sorted and return it.
You may use the pseudo-code in the URL: https://www.toptal.com/developers/sorting-algorithms/bubble-sort to implement this function
*/
	int n=x.size();
	for (int i=1; i<n; i++){
		bool truth=false;
		for (int j = n-1; i <= j; j--){
			if (x[j]<x[j-1]){
				swap(x[j],x[j-1]);
				truth=true;
			}
		}
		if (truth==false){
			break;
		}
	}
	return x; 
}

void merge_sort(NumericVector x, int l, int r) {
/*
Using merge sort algorithm, make x sorted between indicies l ... (r-1) Do not attempt to return it (as oppsed to other functions)
you may use the lecture slides or pseudo-code in the URL: https://www.toptal.com/developers/sorting-algorithms/merge-sort
to implement this function
*/
	if (r-l <=1)
	{
		return;
	}
	int middle= l+(r-l)/2;
	merge_sort(x, l, middle);
	merge_sort(x, middle, r);

	NumericVector y(x.begin()+l, x.begin()+middle);

	int left=0;
	int right=middle;
	int k=l;
	int ny=y.size();

	while(left<ny && right<r){
		if (y[left]<x[right]){
			x[k++]=y[left++];
		}
		else{
			x[k++]=x[right++];
		}
	}
	while(left<ny){
		x[k++]=y[left++];
	}
	while(right<r){
		x[k++]=x[right++];
	}
	return;
}
// [[Rcpp::export]]
NumericVector merge_sort(NumericVector x) {
// Do not modify this function.
// This function simply calls the merge_sort function above // that uses divide-and-conquer algorithm
	merge_sort(x, 0, (int)x.size());
	return x;
}
// [[Rcpp::export]]
NumericVector std_sort(NumericVector x) {
// Do not modify this function.
// This function uses std::sort() function to perform sorting sort(x.begin(), x.end());
	sort(x.begin(), x.end());
	return x;
}
//////////////////////////////////////////////////////////////////////////// // end of [your_uniqname]_hw1a.cpp file ////////////////////////////////////////////////////////////////////////////