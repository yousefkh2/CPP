#include <iostream>


int main(int argc, char **argv)
{
	if (argc == 1) // no args
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	} else {
		int i = 1;
		while (i < argc)
		{
			int j = 0;
			while (argv[i][j])
			{
				
				j++;
			}
			i++;
		}
	}
}