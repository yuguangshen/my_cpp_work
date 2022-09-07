// OptionData.hpp
// The header file for the OptionData, which is a struct containing all the necessary parameters for any option.
// Yuguang Shen

#ifndef OPTIONDATA_HPP
#define OPTIONDATA_HPP

#include <iostream>

struct OptionData
{
	int opt_style;  // Use an int to store option style. 
	                // 0 = EuroStockOption, 1 = EuroFutureOption, 2 = EuroCurrencyOption, 3 = PerpAmOption. This will be implemented by std::map.
	bool isCall;    // 1 = call, 0 = put.
	double S;
	double K;
	double T;
	double sig;
	double r;
	double b;
	double q;
	double R;
};

#endif // !OPTIONDATA_HPP
