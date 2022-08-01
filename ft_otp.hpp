#ifndef FT_OTP_H
#define FT_OTP_H
//
//---------------DEFINICIONES----------------
//
//
// ---------------LIBRERIAS------------------
//
#include <iostream>
#include <ctime>
#include <fstream>
#include "bits-stdc++.h"
#include "cpp-sha256-hmac.hpp"
// #include "cryptopp/rijndael.h"
//
// -----------------TIPOS--------------------
//
// typedef std::string bytearray;
//
// ----------------OBJETOS-------------------
//
// class	tools
// {
// 	public:
// 		void cifrado::prueba();
// 		void tools::p();
// };
class	cifrado //IMPORTATNE: multiplos de 4
{
	int	key;

	std::string	fname;
	std::string hash; //HEX siempre
	std::string bin = "";//BIN siempre
	char	c;
	public:
		void	cifrado::encrypt(std::string str);
		void	cifrado::decrypt(std::string str);
		void	cifrado::getfile(std::string file);
		
		void	cifrado::addbegining(std::string add);
		void	cifrado::addend(std::string add);
		
		void	cifrado::xor_(std::string a, std::string b);
		void	cifrado::permute(const int nmbofmoves);
		void	cifrado::rotl(int shift);//definir a donde va el resultado de la asignación
		void	cifrado::rotr(int shift);//definir a donde va el resultado de la asignación
		std::string	cifrado::hex2bin();
		std::string cifrado::bin2hex();
};
// ------------------------------------------
using namespace YukiWorkshop::Crypto;
// ------------------------------------------
//
// ----------------FUNCIONES-----------------
//
int	ft_flags(int argc, char **argv);
bool	ft_isxdigit(char digit);
bool	ft_dataload(std::string &inputstr, char **argv);
bool	ft_ishex(std::string str);
bool	ft_args(int flag, std::string arg);
bool	ft_datacheck(int argc, char *argv[]);

#endif
