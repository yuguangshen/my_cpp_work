// PerpAmOpt.cpp
// Implementation of the Perp American Option class, which is derived from the Option class.
// Yuguang Shen

#include "PerpAmOpt.hpp"
#include <iostream>
#include <sstream>

namespace YShen
{
	namespace Derivatives
	{
		// Default Constructor
		PerpAmOpt::PerpAmOpt() : Option(), m_b(0) {}

		// Parameter Constructor
		PerpAmOpt::PerpAmOpt(double S, double K, double r, double sig, bool opt_type, double b) : Option(S,K,r,sig,opt_type), m_b(b) {}

		// Copy Constructor
		PerpAmOpt::PerpAmOpt(const PerpAmOpt& s) : Option(s), m_b(s.m_b) {}

		// Destructor
		PerpAmOpt::~PerpAmOpt() {}

		// Operator =
		PerpAmOpt& PerpAmOpt::operator=(const PerpAmOpt& other)
		{
			if (this == &other)
				return *this;
			else
			{
				Option::operator=(other);
				m_b = other.m_b;
				return *this;
			}
		}

		// Setter and Getter for b
		double PerpAmOpt::b() const
		{
			return m_b;
		}
		void PerpAmOpt::b(double b_val)
		{
			m_b = b_val;
		}

		// Price() and overloaded Price(double U)
		double PerpAmOpt::Price() const
		{
			double sig2 = sig() * sig();
			double fac = m_b / sig2 - 0.5; fac *= fac;
			double y1 = 0.5 - m_b / sig2 + sqrt(fac + 2.0 * r() / sig2);
			double y2 = 0.5 - m_b / sig2 - sqrt(fac + 2.0 * r() / sig2);

			if (IsCall())
			{
				if (1.0 == y1)
					return S();

				double fac2 = ((y1 - 1.0) * S()) / (y1 * K());
				double c = K() * pow(fac2, y1) / (y1 - 1.0);

				return c;
			}

			else
			{
				if (0.0 == y2)
					return S();

				double fac2 = ((y2 - 1.0) * S()) / (y2 * K());
				double p = K() * pow(fac2, y2) / (1.0 - y2);

				return p;
			}
		}

		double PerpAmOpt::Price(double U) const
		{
			double sig2 = sig() * sig();
			double fac = m_b / sig2 - 0.5; fac *= fac;
			double y1 = 0.5 - m_b / sig2 + sqrt(fac + 2.0 * r() / sig2);
			double y2 = 0.5 - m_b / sig2 - sqrt(fac + 2.0 * r() / sig2);

			if (IsCall())
			{
				if (1.0 == y1)
					return U;

				double fac2 = ((y1 - 1.0) * U) / (y1 * K());
				double c = K() * pow(fac2, y1) / (y1 - 1.0);

				return c;
			}

			else
			{
				if (0.0 == y2)
					return U;

				double fac2 = ((y2 - 1.0) * U) / (y2 * K());
				double p = K() * pow(fac2, y2) / (1.0 - y2);

				return p;
			}
		}

		// ToString()
		std::string PerpAmOpt::ToString() const
		{
			std::string result;
			std::stringstream my_string;
			my_string << "PerpAmOpt ";
			if (IsCall())
				my_string << "Call: ";
			else
				my_string << "Put: ";
			my_string << "S = " << S() << "; K = " << K() << "; r = " << r() << "; sig = " << sig() << "; b = "
				<< m_b;
			result = my_string.str();

			return result;
		}

		// Greeks. Exact formula not available. Approximate ones will be returned instead.
		double PerpAmOpt::Delta() const
		{
			return Approx_Delta(0.01);
		}

		double PerpAmOpt::Gamma() const
		{
			return Approx_Gamma(0.01);
		}


	}
}