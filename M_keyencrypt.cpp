#include "ft_otp.hpp"

void	cifrado::getfile(std::string file)
{
	fname = file;
}

std::string cifrado::hex2bin()
{
	std::unordered_map<char, std::string> mp;
	mp['0'] = "0000";
	mp['1'] = "0001";
	mp['2'] = "0010";
	mp['3'] = "0011";
	mp['4'] = "0100";
	mp['5'] = "0101";
	mp['6'] = "0110";
	mp['7'] = "0111";
	mp['8'] = "1000";
	mp['9'] = "1001";
	mp['A'] = "1010";
	mp['B'] = "1011";
	mp['C'] = "1100";
	mp['D'] = "1101";
	mp['E'] = "1110";
	mp['F'] = "1111";

	for (int a = 0; a < hash.length(); a++)
	{
		bin += mp[hash[a]];
		//hash[a] += mp[hash[a]];
	}
	return (hash);
}

std::string cifrado::bin2hex()
{
	std::string hex = "";
	std::unordered_map<std::string, char> mp;
	mp["0000"] = '0';
	mp["0001"] = '1';
	mp["0010"] = '2';
	mp["0011"] = '3';
	mp["0100"] = '4';
	mp["0101"] = '5';
	mp["0110"] = '6';
	mp["0111"] = '7';
	mp["1000"] = '8';
	mp["1001"] = '9';
	mp["1010"] = 'A';
	mp["1011"] = 'B';
	mp["1100"] = 'C';
	mp["1101"] = 'D';
	mp["1110"] = 'E';
	mp["1111"] = 'F';

	for (int a = 0; a < bin.length(); a += 4)
	{
		std::string binblock = "";
		binblock += bin[a];
		binblock += bin[a + 1];
		binblock += bin[a + 2];
		binblock += bin[a + 3];
		hex += mp[binblock];
	}
	return (hash = hex, hex);
}

void	cifrado::xor_(std::string a, std::string b)
{
	std::string ret = "";

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == b[i])
			ret += '0';
		else 
			ret += '1';
	}
	hash = ret;
}

void	cifrado::permute(const int nmbofmoves)
{
	int	n = 64 - nmbofmoves;
	std::string perm = "";

	for (int i = 0; i < 64; i++)
	{
		if (n < nmbofmoves)
			n = n + 64 - nmbofmoves;
		perm += hash[n];
		n -= nmbofmoves;
	}
	perm = hash;
}

void	cifrado::addbegining(std::string add)
{
	std::string aux = hash;
	hash = add;
	hash += aux;
}

void	cifrado::addend(std::string add)
{
	hash += add;
}

void	cifrado::encrypt(std::string str)
{
	std::fstream file;
	file.open(str);

	while (file >> std::noskipws >> c)		
	{
		
	}
}

void	cifrado::rotl(int shift)
{
	std::string	ret = "";

	for (int i = 63; i > 0; ret += bin[64 - i], i--);
	ret += bin[0];
}

void	cifrado::rotr(int shift)
{
	std::string	ret = "";

	for (int i = 63; i > 0; ret += bin[i], i--);
}