#include "D:\Develop Projects\Programming_Principles_and_Practice_using_Cpp\std_lib_facilities.h"

int main()
{
	cout << "Enter the name of the person you want to write to \n";
	string first_name;
	cin >> first_name;

	int age = 0;
	cout << "Enter person`s age\n";
	cin >> age;

	cout << "Enter the name of friend \n";
	string friend_name;
	cin >> friend_name;

	char friend_sex = 0;
	cout << "What is your friend`s sex? Enter m for male, and f for female\n";
	cin >> friend_sex;

	cout << "\nDear, " << first_name << ", " << endl;
	cout << "How are you? I am fine. I miss you." << endl;
	cout << "Have you seen " << friend_name << " lately?" << endl;

	if (friend_sex == 'm') cout << "If you see " << friend_name << " please ask him to call me.\n";
	else cout << "If you see " << friend_name << " please ask her to call me.\n";

	if (age <= 0 || age >= 110)
		simple_error("you`re kidding!");
	else cout << "I hear you just had a birthday and you are " << age << " years old." << endl;

	if (age < 12) cout << "Next year you will be " << age + 1 << ".\n";
	else if (age == 17) cout << "Next year you will be able to vote.\n";
	else if (age > 70) cout << "I hope you are enjoying retirement\n";

	cout << "Yours sincerely,\n\nSalomandro\n\n";

	return 0;
}