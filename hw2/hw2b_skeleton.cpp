///////////////////////////////////////////////////////////////////////
// below is the skeleton of [your_uniqname]_hw2b.cpp file
// Note that this is a standalone C++ program, not an R/Rcpp program
// So, make sure that the program compiles and runs by logging in 
// [your_uniqname]@scs.dsc.umich.edu via SSH before submission. 
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

void merge_sort_array(int* v, int l, int r) {
/*
  Given :
  - v : an unsorted array (as integer pointer)
  - l : the index of the leftmost element to sort
  - r : the index right after the rightmost element to sort
  Result:
  - v[l]...v[r-1] will be sorted
  Return:
  - None
*/
}

// Make sure that this function returns something.
// Also, the function does not use indices as arguments.
vector<int> merge_sort_value(vector<int> v) {
  /*
    Given :
    - v : 
    Result:
    - None
    Returns:
    - A sorted permutation of v 
  */  
}

void merge_sort_ref(vector<int>& v, int l, int r) {
/*
  Given :
  - v : an unsorted array (as integer pointer)
  - l : the index of the leftmost element to sort
  - r : the index right after the rightmost element to sort
  Result:
  - v[l]...v[r-1] will be sorted 
  Return:
  - None 
*/
}

void merge_sort_ref_tmp(vector<int>& v, int l, int r, vector<int>& tmp) {
/*
  Given :
  - v : an unsorted array (as integer pointer)
  - l : the index of the leftmost element to sort
  - r : the index right after the rightmost element to sort
  - tmp: a vector to use as a temporary storage om the function
        (it is assumed to be at least as large as v)
  Result:
  - v[l]...v[r-1] will be sorted
  Return:
  - None
*/  
}

int main(int argc, char** argv) {
  // setting a random seed (details will be covered later in class)
  srand(time(NULL)); 
  
  // print out headers
  cout << "Size\tMethod\tMin\tMax\tTicks\tSecs" << endl;

  for(int argi = 1; argi < argc; ++argi) {
    // parse the first input argument as a decimal number
    int sz = strtol(argv[argi],NULL,10);


    int* v1 = new int[sz]; // array for merge_sort_array
    vector<int> v2(sz);    // vector for merge_sort_value
    vector<int> v3(sz);    // vector for merge_sort_ref
    vector<int> v4(sz);    // vector for merge_sort_ref_tmp
    vector<int> tmp(sz);
    // assign same values for all arrays/vectors    
    for(int i=0; i < sz; ++i)
      v1[i] = v2[i] = v3[i] = v4[i] = rand();

    // sorting int* array    
    clock_t t = clock();          // store current clock
    merge_sort_array(v1, 0, sz);
    t = clock() - t;              // evaluate the number of clocks spent
    cout << sz << "\tArray\t" << v1[0] << "\t" << v1[sz-1] << "\t" << t << "\t" << (double)t/CLOCKS_PER_SEC << endl;

    // sorting vector<int> using pass-by-value    
    t = clock();
    v2 = merge_sort_value(v2);  // beware that no extra arguments exist, and it returns a vector (because it is call by value) 
    t = clock() - t;
    cout << sz << "\tValue\t"<< v2[0] << "\t" << v2[sz-1] << "\t" << t << "\t" << (double)t/CLOCKS_PER_SEC << endl;

    // sorting vector<int> using pass-by-reference    
    t = clock();
    merge_sort_ref(v3, 0, sz);
    t = clock() - t;
    cout << sz << "\tRef\t"<< v3[0] << "\t" << v3[sz-1] << "\t" << t << "\t" << (double)t/CLOCKS_PER_SEC << endl;

    // sorting vector<int> using pass-by-reference + temporary space    
    t = clock();
    merge_sort_ref_tmp(v4, 0, sz, tmp);
    t = clock() - t;
    cout << sz << "\tRef+Tmp\t" << v4[0] << "\t" << v4[sz-1] << "\t" << t << "\t" << (double)t/CLOCKS_PER_SEC << endl;
  }

  return 0;
}

////////////////////////////////////////////////////////////////////////////
// end of [your_uniqname]_hw2b.cpp file
////////////////////////////////////////////////////////////////////////////
