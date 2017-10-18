#pragma once

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

struct INT //struct for ints
{


	int *data;
	INT() { data = NULL; }
	INT(int x) { data = new int(x); }
	~INT() {  }

	//overloaded operators
	bool operator>(const INT &rhsobj) ; //overloaded > operator
	bool operator<(const INT &rhsobj) ; //overloaded < operator
	bool operator==(const INT &rhsobj) ; //overloaded == operator
	bool operator!=(const INT &rhsobj) ; //overloaded != operator
	INT operator=(const INT &rhsobj); //overloaded = operator
	//std::ostream& dump(std::ostream &o, const INT& p);


};

std::istream& operator >> (std::istream &i, INT &a) //overloaded stream extraction operator
{
	int input;
	i >> input;

	a.data = new int(input);

	return i;
}


std::ostream& operator << (std::ostream &o, const INT &a) //overloaded stream insertion operator
{
	o << *(a.data);
	return o;
}


bool INT::operator>(const INT & rhsobj)  //overloaded > operator
{
	if (*data > *(rhsobj.data))
		return true;
	else
		return false;
}
bool INT::operator<(const INT & rhsobj)  //overloaded < operator
{
	if (*data < *(rhsobj.data))
		return true;
	else
		return false;
}
bool INT::operator==(const INT & rhsobj)  //overloaded == operator
{
	if (*data == *(rhsobj.data))
		return true;
	else
		return false;
}
bool INT::operator!=(const INT & rhsobj) //overloaded != operator
{
	if (*data != *(rhsobj.data))
		return true;
	else
		return false;
}
INT INT::operator=(const INT & rhsobj) //overloadd = operator
{

	if (this == &rhsobj)
	{
		return *this;
		
	}
	else
	{

		data = new int(*(rhsobj.data));
		return *this;
	}
	
}

struct CHAR //struct for c style strings
{
	char *data;
	int dataSize;
	CHAR() { data = NULL; dataSize = 0; }
	CHAR(std::string);
	~CHAR() {  }

	//overloaded operators
	bool operator>(const CHAR &rhsobj); //overloaded > operator
	bool operator<(const CHAR &rhsobj); //overloaded < operator
	bool operator==(const CHAR &rhsobj); //overloaded == operator
	bool operator!=(const CHAR &rhsobj); //overloaded != operator
	CHAR operator=(const CHAR &rhsobj); //overloaded = operator


};

std::istream& operator >> (std::istream &i, CHAR &a) //overloaded stream extraction operator
{
	std::string str = "";
	i >> str;

	a.data = new char[str.length() + 2];
	int j = 0;
	for (j= 0; j < str.length(); j++)
	{
		a.data[j] = str[j];
	}
	a.data[j + 1] = '\0';

	return i;
}

 CHAR::CHAR(std::string str) //overloaded constructor
{
	data = new char[str.length()+2];
	dataSize = str.length();
	int i = 0;
	for (i = 0; i < str.length(); i++)
	{
		data[i] = str[i];
	}
	data[i + 1] = '\0';
}



std::ostream& operator << (std::ostream &o, const CHAR &a) //overloaded stream insertion operator
{
	int i = 0;
	while (a.data[i+1] != '\0')
	{
		o << a.data[i];
		i++;
	}


	return o;
}

bool CHAR::operator>(const CHAR & rhsobj) //overloaded > operator
{
	if (strcmp(data, rhsobj.data) == 1)
		return true;
	else
		return false;
}
bool CHAR::operator<(const CHAR & rhsobj) //overloaded < operator
{
	if (strcmp(data, rhsobj.data) == -1)
		return true;
	else
		return false;
}
bool CHAR::operator==(const CHAR & rhsobj) //overloaded == operator
{
	if (strcmp(data, rhsobj.data) == 0)
		return true;
	else
		return false;
}
bool CHAR::operator!=(const CHAR & rhsobj) //overloaded != operator
{
	if (strcmp(data, rhsobj.data) != 0)
		return true;
	else
		return false;
}
CHAR CHAR::operator=(const CHAR & rhsobj) //overloaded = operator
{

	if (this == &rhsobj)
	{
		return *this;

	}
	else
	{
		delete data;
		data = rhsobj.data;
		
		return *this;
	}

}