// EuroFutureOpt.cpp
// Implementation of the EuroFutureOpt class.
// Yuguang Shen

#include "EuroFutureOpt.hpp"
#include <iostream>
#include <sstream>

namespace YShen
{
	namespace Derivatives
	{
		// Default Constructor
		EuroFutureOpt::EuroFutureOpt() : EuroOpt() {}

		// Parameter Constructor
		EuroFutureOpt::EuroFutureOpt(double S, double K, double r, double sig, bool opt_type, double T) : EuroOpt(S,K,r,sig,opt_type,T) {}

		// Copy Constructor
		EuroFutureOpt::EuroFutureOpt(const EuroFutureOpt& s) : EuroOpt(s) {}

		// Destructor
		EuroFutureOpt::~EuroFutureOpt() {}

		// Operator =
		EuroFutureOpt& EuroFutureOpt::operator=(const EuroFutureOpt& other)
		{
			if (this == &other)
				return *this;
			else
			{
				EuroOpt::operator=(other);
				return *this;
			}
		}
		// Cost of Carry
		double EuroFutureOpt::CoC() const
		{
			return 0;
		}

		// ToString()
		std::string EuroFutureOpt::ToString() const
		{
			std::string result;
			std::stringstream my_string;
			my_string << "EuroFutureOpt ";
			if (IsCall())
				my_string << "Call: ";
			else
				my_string << "Put: ";
			my_string << "S = " << S() << "; K = " << K() << "; T = " << T() << "; r = " << r() << "; sig = " << sig();
			result = my_string.str();

			return result;
		}

	}
}