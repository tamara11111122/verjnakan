#include	<fstream>
#include	<iostream>
#include	<string.h>

using namespace std;

void Test_Linear();
void Test_is();
void Test_My_atoi();

float linear(float a, float b)
{
	if (a == 0 || b == 0)
		return (0);
	else
		return (-b / a);
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

int file_len(fstream val)
{
	int len = 0;
	val.open("valueLinear.txt", ios::in);
	string str;
	if (val.is_open())
	{
		while(getline(val, str))
			len++;
	}
	return (len);
}
//values from valuesLinear.txt and puts result into resultLinear.txt
int main()
{
	char tox1[20];
	char tox2[20];
	int a, b;
	fstream val, res;
	val.open ("valueLinear.txt", ios::in);
	res.open("resultLinear.txt", ios::out);
	int len = 0;
	string str;
	if (val.is_open())
	{
		while(getline(val, str))
			len++;
	}
	val.close();
	val.open("valueLinear.txt", ios::in);
	while (len)
	{
		val >> tox1 >> tox2;
		a = my_atoi(tox1);	
		b = my_atoi(tox2);
		res << linear(a, b) << "\n";
		len--;
	}
	Test_Linear();
	Test_is();
	Test_My_atoi();
	val.close();
	res.close();
}
