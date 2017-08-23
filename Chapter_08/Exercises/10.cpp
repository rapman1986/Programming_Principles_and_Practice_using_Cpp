#include "std_lib_facilities.h";

double maxv(vector<double> v)
{
	double max = v[0];
	for (int i = 1; i < v.size(); i++)
		if (v[i] > max)
			max = v[i];
	return max;
}