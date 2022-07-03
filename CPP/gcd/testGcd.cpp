#include	<fstream>
#include	<iostream>
#include	<cassert>

int gcd(int a, int b);
int is(char c, const char *str);
int my_atoi(const char *str);

void Test_Gcd()
{
	assert(gcd(10, 5) == 5);
	assert(gcd(99, 3) == 3);
	assert(gcd(8, 64) == 8);
	assert(gcd(2, 1) == 1);
	assert(gcd(121, 11) == 11);
}

void Test_My_atoi()
{
	assert(my_atoi("   -10") == -10);
	assert(my_atoi("-+30") == 0);
	assert(my_atoi("+44") == 44);
	assert(my_atoi("23") == 23);
	assert(my_atoi("5y6") == 5);
}

void Test_is()
{
	assert(is('k', "ahgk") == 1);
	assert(is(' ', "hgf  ") == 1);
	assert(is('8', "hhhh") == 0);
	assert(is('u', "u") == 1);
	assert(is('p', "ggttgg") == 0);
}
