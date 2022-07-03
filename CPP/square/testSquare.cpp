#include	<cassert>

int Discriminant(int a, int b, int c);
int is(char c, const char *str);
int my_atoi(const char *str);

void Test_Discriminant()
{
	assert(Discriminant(1, 5, 4) == 9);
	assert(Discriminant(1, -5, 6) == 1);
	assert(Discriminant(6, 5, 3) == -47);
	assert(Discriminant(2, 2, 2) == -12);
	assert(Discriminant(0, 11, 0) == 121);
	assert(Discriminant(3,7,2) == 25);
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
