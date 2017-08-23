#include "std_lib_facilities.h";

struct vector_data
{
	double max;
	double min;
	double mean;
	double median;
};

vector_data comput_data(vector<double> v)
{
	vector_data v_data;
	v_data.max = v[0];
	v_data.min = v[0];
	v_data.median = 0;
	v_data.mean = 0;

	double sum = 0;

	//compute max, min and mean values
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > v_data.max) v_data.max = v[i];
		if (v[i] < v_data.min) v_data.min = v[i];
		sum += v[i];
	}
	v_data.mean = sum / v.size();

	// compute median
	sort(v.begin(), v.end());
	if (v.size() % 2 == 0)	// the size of v is even
		v_data.median = (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2;
	else
		v_data.median = v[v.size() / 2];

	return v_data;
}

int main()
{
	vector<double> v = { 5.6, 3, 7.8, 2.4, 1, 4, 2, 7, 8, 4.2 };

	vector_data vd = comput_data(v);

	cout << "Max " << vd.max << ";\tMin " << vd.min << endl;
	cout << "Mean " << vd.mean << ";\tMedian " << vd.median << endl;

	return 0;
}