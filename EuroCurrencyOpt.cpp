// EuroCurrencyOpt.cpp
// Implementation of the Euro Currency Option class.
// Yuguang Shen

#include "EuroCurrencyOpt.hpp"
#include <iostream>
#include <sstream>

namespace YShen
{
	namespace Derivatives
	{
		// Default Constructor
		EuroCurrencyOpt::EuroCurrencyOpt() : EuroOpt(), m_R(0) {}

		// Parameter Constructor
		EuroCurrencyOpt::EuroCurrencyOpt(double S, double K, double r, double sig, bool opt_type, double T, double R) : EuroOpt(S, K, r, sig, opt_type, T), m_R(R) {}

		// Copy Constructor
		EuroCurrencyOpt::EuroCurrencyOpt(const EuroCurrencyOpt& s) : EuroOpt(s), m_R(s.m_R) {}

		// Destructor
		EuroCurrencyOpt::~EuroCurrencyOpt() {}

		// Operator =
		EuroCurrencyOpt& EuroCurrencyOpt::operator=(const EuroCurrencyOpt& other)
		{
			if (this == &other)
				return *this;
			else
			{
				EuroOpt::operator=(other);
				m_R = other.m_R;
				return *this;
			}
		}
		// Setter and Getter for R
		double EuroCurrencyOpt::R() const
		{
			return m_R;
		}
		void EuroCurrencyOpt::R(double R_val)
		{
			m_R = R_val;
		}

		// Cost of Carry
		double EuroCurrencyOpt::CoC() const
		{
			return (r() - m_R);
		}

		// ToString()
		std::string EuroCurrencyOpt::ToString() const
		{
			std::string result;
			std::stringstream my_string;
			my_string << "EuroCurrencyOpt ";
			if (IsCall())
				my_string << "Call: ";
			else
				my_string << "Put: ";
			my_string << "S = " << S() << "; K = " << K() << "; T = " << T() << "; r = " << r() << "; sig = " << sig() << "; R = "
				<< m_R;
			result = my_string.str();

			return result;
		}










	}
}