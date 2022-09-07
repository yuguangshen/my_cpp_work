// Exceptions.hpp
// Header file for the Exception classes in this program.
// Yuguang Shen

#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <iostream>
#include <sstream>

// Base class. InvalidInput
class InvalidInput
{
public:
	// Default Constructor
	InvalidInput();
	// Destructor
	virtual ~InvalidInput();

	// What(). PVMF. The implementation is left to the derived class.
	virtual std::string What() const = 0;
};

// Derived class, InvalidParameter. It is thrown when the user inputs a parameter which does not belong to the data members of OptionData.
class InvalidParameter : public InvalidInput
{
private:
	std::string param;

public:
	// Parameter Constructor
	InvalidParameter(std::string msg);
	// Destructor
	~InvalidParameter();
	// What()
	std::string What() const;
};

// Derived class, InvalidOperation. It is thrown when the user asks the matrix pricer to call a function which does not belong. 
class InvalidOperation : public InvalidInput
{
private:
	std::string operation;

public:
	// Parameter Constructor
	InvalidOperation(std::string msg);
	// Destructor
	~InvalidOperation();
	// What()
	std::string What() const;
};

// Derived class, InvalidStyle. It is thrown when the user inputs an option style which is not implemented.
class InvalidStyle : public InvalidInput
{
private:
	std::string style;

public:
	// Parameter Constructor
	InvalidStyle(std::string msg);
	// Destructor
	~InvalidStyle();
	// What()
	std::string What() const;
};




#endif // !EXCEPTIONS_HPP

