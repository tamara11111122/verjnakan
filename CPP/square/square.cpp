#include	<fstream>
#include	<cmath>
#include	<string.h>

using namespace std;
void Test_Discriminant();
void Test_is();
void Test_My_atoi();

//Discriminant 
int Discriminant(int a, int b, int c)
{
	return (b * b - 4 * a * c);
}

//Function for atoi, checks if the character exists in str
int is(char c,const char *str)
{
	while (*str)
	{
		if(*str == c)
			return (1);
		str++;
	}
	return (0);
}

//Convert string to int
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

//gets values for Square expression from file valueSquare.txt, and puts the result into resultSquare.txt
int main()
{
	char tox1[20];
	char tox2[20];
	char tox3[20];
	int len = 0;
	int a, b, c;
	fstream val, res;
	val.open ("valueSquare.txt", ios::in);
	res.open("resultSquare.txt", ios::out);
	string str;
	if (val.is_open())
	{
		while(getline(val, str))
			len++;
	}
	val.close();
	val.open("valueSquare.txt", ios::in);
	while (len)
		{
			val >> tox1 >> tox2 >> tox3;
			a = my_atoi(tox1);
			b = my_atoi(tox2);
			c = my_atoi(tox3);
			int D = Discriminant(a, b, c);
			if (D > 0)
			{
				float x1 = (-b + sqrt(D)) / 2 * a;
				float x2 = (-b - sqrt(D)) / 2 * a;
				if (res.is_open())
					res << x1 << " " << x2 << "\n";
			}
			else if (D == 0)
			{
				float x = -b / 2 * a;
				if (res.is_open())
					res << x << "\n";
			}
			else
			{
				char str[25] = "no real solution";
				if (res.is_open())
					res << str << "\n";
			}
			len--;
		}
	Test_Discriminant();
	Test_is();
	Test_My_atoi(); 
	res.close();
	val.close();
}

