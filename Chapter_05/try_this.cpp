#include "D:\Develop Projects\Programming_Principles_and_Practice_using_Cpp\std_lib_facilities.h"

//int area(int, int);
//int framed_area(int, int);

//class Bad_area{};

int main()
{
	// Try This 3
	vector<double> temps;

	for (double temp; cin >> temp;)
		temps.push_back(temp);

	constexpr double MAX_TEMP = 136;
	constexpr double MIN_TEMP = -126;

	double sum = 0;
	double high_temp = MIN_TEMP;
	double low_temp = MAX_TEMP;

	for (double x : temps)
	{
		if (x > high_temp) high_temp = x;
		if (x < low_temp) low_temp = x;
		sum += x;
	}

	cout << "High temperature: " << high_temp << endl;
	cout << "Low temperature: " << low_temp << endl;
	cout << "Average temperature: " << sum / temps.size() << endl;

	// Exceptions
	//try
	//{
	//	int x = -1;
	//	int y = 2;
	//	int z = 4;
	//	//.....
	//	int area1 = area(x, y);
	//	int area2 = framed_area(1, z);
	//	int area3 = framed_area(y, z);
	//	double ratio = double(area1) / area3;
	//}
	//catch (Bad_area)
	//{
	//	cout << "oops! Bad argumetns to area()\n";
	//}

	// Try this 2
	/*int x0 = arena(7);
	int x1 = area(7);
	int x2 = area("seven", 7);
	int x0 = area(1, 2);*/

	// Try this 1
	/*int s1 = area(7;
	int s2 = area(7)
	Int s3 = area(7);
	int s4 = area('7);*/
}

//int area(int length, int width)
//{
//	if (length <= 0 || width <= 0) throw Bad_area{};
//	return length*width;
//}
//
//int framed_area(int x, int y)
//{
//	constexpr int FRAME_WIDTH = 2;
//	return area(x - FRAME_WIDTH, y - FRAME_WIDTH);
//}
