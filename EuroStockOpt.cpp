// EuroStockOpt.cpp
// The implementation of the EuroStockOpt class.
// Yuguang Shen

#include "EuroStockOpt.hpp"
#include <iostream>
#include <sstream>

namespace YShen
{
	namespace Derivatives
	{
		// Default Constructor
		EuroStockOpt::EuroStockOpt() : EuroOpt(), m_q(0)
		{
			//std::cout << "EuroStockOpt Created by Default......" << std::endl;
		}

		// Parameter Constructor
		EuroStockOpt::EuroStockOpt(double S, double K, double r, double sig, bool opt_type, double T, double q) :
			EuroOpt(S, K, r, sig, opt_type, T), m_q(q)
		{
			//std::cout << "EuroStockOpt Created by Parameter......" << std::endl;
		}

		// Copy Constructor
		EuroStockOpt::EuroStockOpt(const EuroStockOpt& s) : EuroOpt(s), m_q(s.m_q)
		{
			//std::cout << "EuroStockOpt Created by Copy......" << std::endl;
		}

		// Destructor
		EuroStockOpt::~EuroStockOpt()
		{
			//std::cout << "EuroStockOpt Destroyed......" << std::endl;
		}
		// Operator =
		EuroStockOpt& EuroStockOpt::operator=(const EuroStockOpt& other)
		{
			if (this == &other)
				return *this;
			else
			{
				EuroOpt::operator=(other);
				m_q = other.m_q;
				return *this;
			}
		}

		// Setter and Getter
		double EuroStockOpt::q() const
		{
			return m_q;
		}
		void EuroStockOpt::q(double q_val)
		{
			m_q = q_val;
		}
		// Cost of Carry
		double EuroStockOpt::CoC() const
		{
			return (r() - m_q);
		}

		// ToString()
		std::string EuroStockOpt::ToString() const
		{
		
			std::string result;
			std::stringstream my_string;
			my_string << "EuroStockOpt ";
			if (IsCall())
				my_string << "Call: ";
			else
				my_string << "Put: ";
			my_string<< "S = " << S() << "; K = " << K() << "; T = " << T() << "; r = " << r() << "; sig = " << sig() << "; q = "
				<< m_q;
			result = my_string.str();

			return result;

		}

	}
}