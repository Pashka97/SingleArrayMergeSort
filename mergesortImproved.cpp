// --------------------------mergesortImproved.cpp----------------------------
// Pavel Samsonov CSS 342
// 01 May 2017
// ---------------------------------------------------------------------------
// Purpose - implement a non-recursive, 2 array solution to mergesort
// --------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions.
// O(n log n)
// improved mergesort as it does not have to create new arrays for every 
//																operation
// ---------------------------------------------------------------------------

#include <vector>
#include <math.h> // may need to use pow( )
using namespace std;

/*
precondition: pass in a valid array
postcondition: return a sorted array
Uses an improved mergesort to sort the array.
Does not sort recusrively, instead only uses one other temp array.
@param &a: a vector to be sorted
*/
template <class Comparable>
void mergesortImproved(vector<Comparable> &a) {

	int size = a.size();
	vector<Comparable> b(size);  // this is only one temporary array.     

	for (int i = 0; i < b.size();i++) { // initialize the second array.
		b[i] = a[i];					
	}

	//use variables to keep track of partitions and our location within 
	//each partition
	int right, rend;
	int i, j, m, t;

	//outerloop divides the array into partitions, how we immitate 
	//splitting the array into smaller pieces
	for (int k = 1; k < a.size(); k *= 2) { 
		//at each partition size, sort and merge
		for (int left = 0; left + k < a.size(); left += k*2) {
			//store the start of the right partition and its end
			right = left + k;
			rend = right + k;
			
			//if the partitions are uneven, readjust the end
			if (rend > a.size()) rend = a.size();
			m = left;
			i = left;
			j = right;

			//merge
			while (i < right && j < rend) {
				if (a[i] <= a[j]) {
					b[m] = a[i];
					i++;
				}
				else {
					b[m] = a[j];
					j++;
				}
				m++;
			}
			while (i < right) {
				b[m] = a[i];
				i++;
				m++;
			}
			while (j < rend) {
				b[m] = a[j];
				j++;
				m++;
			}
			//copy from temp array into initial array
			for (m = left; m < rend; m++) {
				a[m] = b[m];
			}
		}
	}
	
}
