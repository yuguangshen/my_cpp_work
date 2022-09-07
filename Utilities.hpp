// Utilities.hpp
// The header file for Utilities, which includs Mesher(), StyleSelect(), and MatrixFactory().
// Mesher() takes start, end and step as arguments, returns a vector of double.
// StyleSelect() is provided to the users for selecting option styles when creating OptionData objects.
// MatrixFactory() returns a vector of OptionPtr, which will be fed to MatrixCalculator. 

#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <iostream>
#include <vector>
#include <map>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include "OptionData.hpp"
#include "Option.hpp"

typedef boost::shared_ptr<YShen::Derivatives::Option> OptionPtr;

// Mesher(). Generate a vector of double with intervals of h.
std::vector<double> Mesher(double start, double end, double h);

// StyleSelect(). Serve as the interface for the user to select option style when inputting parameters. 
int StyleSelect(std::string input);

// MatrixFactory(). Change user-input option parameters into vector of smart pointers to options. Prepare for matrix calculation. 
std::vector<OptionPtr> MatrixFactory(OptionData data, std::vector<double> mesh, std::string param);

std::vector<OptionPtr> MatrixFactory(std::vector<OptionData> data_vec);


#endif // !UTILITIES_HPP

