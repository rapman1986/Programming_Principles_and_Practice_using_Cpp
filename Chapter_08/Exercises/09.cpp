#include "std_lib_facilities.h"

double index(vector<double> price, vector<double> weight)
{
	try
	{
		double index = 0;
		for (int i = 0; i < price.size(); i++)
			index += (price[i] * weight[i]);
		return index;
	}
	catch (exception& e)
	{
		cerr << e.what();
		return -1;
	}

}