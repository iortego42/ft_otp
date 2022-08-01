#include "ft_otp.hpp"

int	ft_flags(int argc, char **argv)
{
	if (argc == 3)
	{
		if (argv[1][0] == '-')
		{
			if (argv[1][1] == 'k')
				return ('k');
			else if (argv[1][1] == 'g')
				return ('g');
		}
	}
	return (0);	
}
bool ft_dataload(std::string &inputstr, char **argv)
{
	std::ifstream input;
	
	input.open(argv[2]);
	if (!input.is_open())
		return (false);
	input >> inputstr;
	return (true);
}
bool	ft_isxdigit(char digit)
{
	if ((unsigned) digit - '0' < 10 || (unsigned) digit - 'A' < 6)
		return (true);
	return (false);
}
bool	ft_ishex(std::string str)
{
	int i = 0;

	while (str[i] != 0)
		if (!ft_isxdigit(str[i]))
			return (false);
	return (true);
}

bool	ft_args(int flag, std::string arg)
{
	if (flag == 'k')
		if (ft_ishex(arg))
			return (true);
	else if (flag == 'g')
		return (true);
	return (false);
}
bool	ft_datacheck(int argc, char *argv[])
{
	int flag = ft_flags(argc, argv);

	if (flag)
		if (std::string fcontent; ft_dataload(fcontent, argv))
			if (ft_args(flag, fcontent))
				return (true);
			else
				std::cout << "ERROR. Los archivos no estan bien cifrados." << std::endl;
		else
			std::cout << "ERROR. No se ha podido cargar el archivo" << std::endl;
	else
		std::cout << "ERROR. No se han introducido las flags adecuadas." << std::endl;
	return (false);
}
