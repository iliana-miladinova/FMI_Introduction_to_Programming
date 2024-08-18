// seminar 02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    //task 01
    /*int num;
    std::cin >> num;
	switch (num)
	{
	case 1: std::cout << "Monday" << std::endl;
		break;
	case 2: std::cout << "Tuesday" << std::endl;
		break;
	case 3: std::cout << "Wednesday" << std::endl;
		break;
	case 4: std::cout << "Thursday" << std::endl;
		break;
	case 5: std::cout << "Friday" << std::endl;
		break;
	case 6: std::cout << "Saturday" << std::endl;
		break;
	case 7: std::cout << "Sunday" << std::endl;
		break;
	default: std::cout << "Invalid day!" << std::endl;
		break;
	}*/

	//task 02
	/*int num;
	std::cin >> num;
	if (num<100)
	{
		std::cout << "Less than 100" << std::endl;
	}
	else if (num<=200)
	{
		std::cout << "Between 100 and 200" << std::endl;
	}
	else
	{
		std::cout << "Greater than 200" << std::endl;
	}*/

	//task 03
	/*double speed;
	std::cin >> speed;
	if (speed<=10)
	{
		std::cout << "slow" << std::endl;
	}
	else if (speed < 50)
	{
		std::cout << "average" << std::endl;
	}
	else if (speed<150)
	{
		std::cout << "fast" << std::endl;
	}
	else if (speed<1000)
	{
		std::cout << "ultra fast" << std::endl;
	}
	else
	{
		std::cout << "extremely fast" << std::endl;
	}*/

	//task 04
	/*constexpr double PI = 3.14;
	char f;
	std::cin >> f;
	switch (f)
	{
	case 's':
		double s;
		std::cin >> s;
		std::cout << s * s << std::endl;
		break;
	case 't':
		double side, h;
		std::cin >> side >> h;
		std::cout << side * h / 2 << std::endl;
		break;
	case 'r':
		double sideA, sideB;
		std::cin >> sideA >> sideB;
		std::cout << sideA * sideB << std::endl; 
		break;
	case 'c':
		double r;
		std::cin >> r;
		std::cout << PI * r * r << std::endl;
		break;

	default:
		std::cout << "Error";
		break;
	}*/

	//task 05
	//int hours, mins;
	//std::cin >> hours >> mins;
	//mins += 15;
	//if (mins>59)
	//{
	//	hours++;
	//	mins -= 60;
	//}
	//if (hours>23)
	//{
	//	hours -= 24;
	//}
	///*if (hours % 10 == hours)
	//{
	//	std::cout << "0" << hours << ":";
	//}
	//else
	//{
	//	std::cout << hours << ":";
	//}
	//if (mins%10==mins)
	//{
	//	std::cout << "0" << mins << std::endl;
	//}
	//else
	//{
	//	std::cout << mins << std::endl;
	//}*/
	//if (hours<=9)
	//{
	//	std::cout << "0";
	//}
	//std::cout << hours << ":";
	//if (mins<=9)
	//{
	//	std::cout << "0";
	//}
	//std::cout << mins << std::endl;

	//nachina ot github
	//int hours, mins;
	//std::cin >> hours >> mins;
	//(mins += 15) %= 60;
	//if (mins<15)
	//{
	//	(hours += 1) %= 24;
	//}
	//if (hours<=9)
	//{
	//	std::cout << "0";
	//}
	//std::cout << hours << ":";
	//if (mins<=9)
	//{
	//	std::cout << '0';
	//}
	//std::cout << mins << std::endl;

	//task 06
	//int n1, n2, n3, n4, n5;
	//std::cin >> n1 >> n2 >> n3 >> n4 >> n5;
	//if ((n2<=n1&&n2<=n3&&n4<=n3&&n4<=n5)||(n2>=n1&&n2>=n3&&n4>=n3&&n4>=n5))
	//{
	//	std::cout << "yes";
	//}
	//else
	//{
	//	std::cout << "no";
	//}

	//task 07
	/*int r, x, y;
	std::cin >> r >> x >> y;
	int dist = x * x + y * y;
	if (dist==r*r)
	{
		std::cout << "On the circle" << std::endl;
	}
	else if (dist<r*r)
	{
		std::cout << "In the circle" << std::endl;
	}
	else
	{
		std::cout << "Out of the circle" << std::endl;
	}*/

	//prime digit
	int digit;
	std::cin >> digit;
	switch (digit)
	{
	case 2:
	case 3:
	case 5:
	case 7:
		std::cout << "Prime" << std::endl;
		break;
	case 0:
	case 1:
	case 4:
	case 6:
	case 8:
	case 9:
		std::cout << "Not prime" << std::endl;
		break;

	default: std::cout << "Not a digit" << std::endl;
		break;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
