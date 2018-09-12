#include <bits/stdc++.h>

using namespace std;

// Calculates the cost at the given point
// Must be a parabolic function matching the desired extreme (min or max)
// of the ternary search function
double calc(double m) {
	// TODO: to be implemented
	return 1;
}

// Ternary search on to find a real (floating) local minimum
double ternarySearchDouble() {
	double l = 0, r = 1e18;

	for (int i = 0; i < 1000; ++i) {
		double mid1 = l + (r - l) / 3;
		double mid2 = r - (r - l) / 3;

		if (calc(mid1) < calc(mid2))
			r = mid2;
		else
			l = mid1;
	}

	return l;
}

// Ternary search to find an interger local minimum
int ternarySearchInt() {
	int l = 0, r = 1e6;

	while (r - l > 10) {
		int mid1 = l + (r - l) / 3;
		int mid2 = r - (r - l) / 3;

		if (calc(mid1) < calc(mid2))
			r = mid2;
		else
			l = mid1;
	}

	int pos, val = 1e9;

	for (int i = l; i <= r; ++i) {
		int tmp = calc(i);

		if (val > tmp) {
			val = tmp;
			pos = i;
		}
	}

	return pos;
}