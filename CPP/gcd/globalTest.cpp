#include	<fstream>
#include	<string>

using namespace std;

int	f_strcmp(string rline, string gline)
{
	int i = 0;
	while (rline[i] && gline[i])
	{
		if (rline[i] != gline[i])
			return (-1);
		i++;
	}
	return (0);
}

int main()
{
	fstream res, gold, test;
	res.open("resultGcd.txt", ios::in);
	gold.open("goldenGcd.txt", ios::in);
	test.open("testresults.txt", ios::out);
	string rline, gline;
	while (getline(res, rline) && getline(gold, gline))
	{
		if (f_strcmp(rline, gline) == 0)
		{
			test << "Expected  " << gline << " :Result - " << rline;
			test << " -> Success\n";
		}
		else
		{
			test << "Expected  " << gline << " :Result - " << rline;
			test << " -> Fail\n";
		}
	}
}
