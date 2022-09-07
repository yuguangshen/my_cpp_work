// Exceptions.cpp
// Implementation for the exception classes in this program.
// Yuguang Shen

#include "Exceptions.hpp"
#include <iostream>
#include <sstream>

// Base class.
InvalidInput::InvalidInput() {}
InvalidInput::~InvalidInput() {}

// Derived class.
InvalidParameter::InvalidParameter(std::string msg) : InvalidInput(), param(msg) {}
InvalidParameter::~InvalidParameter() {}
std::string InvalidParameter::What() const
{
	std::string message;
	std::stringstream msg_stream;
	msg_stream << param << " is Not a Valid Option Parameter!";
	message = msg_stream.str();

	return message;
}

// Derived class.
InvalidOperation::InvalidOperation(std::string msg) : InvalidInput(), operation(msg) {}
InvalidOperation::~InvalidOperation() {}
std::string InvalidOperation::What() const
{
	std::string message;
	std::stringstream msg_stream;
	msg_stream << operation << " is Not a Valid Calculation for Matrix Pricer!";
	message = msg_stream.str();

	return message;
}

// Derived class
InvalidStyle::InvalidStyle(std::string msg) : InvalidInput(), style(msg) {}
InvalidStyle::~InvalidStyle() {}
std::string InvalidStyle::What() const
{
	std::string message;
	std::stringstream msg_stream;
	msg_stream << style << " is Not a Valid Option Style!";
	message = msg_stream.str();

	return message;
}