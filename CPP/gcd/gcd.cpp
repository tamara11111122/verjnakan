#include	<fstream>
#include	<iostream>
using namespace std;

void Test_Gcd();
void Test_is();
void Test_My_atoi();

int gcd(int a, int b)
{
	if (a > b)
	{
		return gcd(a - b, b);
	}
	else if (a == b)
		return (a);
	else
		return gcd(a, b - a);
}

int is(char c, const char *str)
{
	while (*str)
	{
		if(*str == c)
			return (1);
		str++;
	}
	return (0);
}

int my_atoi(const char *str)
{
	int num = 0;
	int sign = 1;
	char tabs[10] = "\t\n\v\f\r ";
	while (is(*str, tabs))
		str++;
	if(*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += *str - 48;
		str++;
	}
	return (sign * num);
}	

//gets the numbers from valuesGcd.txt and puts result into resultGcd.txt
int main()
{
	char tox1[20];
	char tox2[20];
	int a, b;
	string line;
	int count = 0;
	fstream val, res;
	val.open ("valueGcd.txt", ios::in);
	res.open("resultGcd.txt", ios::out);
	if (val.is_open())
	{
		while (getline(val, line))
			count++;
	}
	val.close();
	val.open("valueGcd.txt", ios::in);
	while (count)
	{
		val >> tox1 >> tox2;
		a = my_atoi(tox1);
		b = my_atoi(tox2);
		if (res.is_open())
		{
			res << gcd(a, b) << "\n";
		}
		count--;
	}

	Test_Gcd();
	Test_My_atoi();
	Test_is();
	val.close();
	res.close();
}
