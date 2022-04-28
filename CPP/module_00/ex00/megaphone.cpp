#include <iostream>
#include <string>

int main(int ac, char **av)
{
	int i;
	int a;
	
	a = 0;
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (av[++a])
	{
		i = -1;
		while (av[a][++i])
			if (av[a][i] >= 'a' && av[a][i] <= 'z')
				av[a][i] -= 32;
		
		std::cout << av[a];
	}
	std::cout << std::endl;
	return (0);
}
