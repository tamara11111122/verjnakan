#include	<cassert>

float linear(float a, float b);
int is(char c, const char *str);
int my_atoi(const char *str);

void Test_Linear()
{
	assert(linear(10, 5) == -0.5);
	assert(linear(2, 34) == -17);
	assert(linear(8, 64) == -8.0);
	assert(linear(2, 2) == -1.0);
	assert(linear(0, 11) == 0);
	assert(linear(6, 0) == 0);
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
