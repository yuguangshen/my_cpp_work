// Option.cpp
// The implementation of the Option class (ABC)
// Yuguang Shen

#include "Option.hpp"

namespace YShen
{
	namespace Derivatives
	{
		// Default Constructor
		Option::Option() : m_S(0), m_K(0), m_r(0), m_sig(0), isCall(1)
		{
			//std::cout << "Option Created by Default......" << std::endl;
		}

		// Parameter Constructor
		Option::Option(double S, double K, double r, double sig, bool opt_type) : m_S(S), m_K(K), m_r(r), m_sig(sig), isCall(opt_type)
		{
			//std::cout << "Option Created by Parameter......" << std::endl;
		}

		// Copy Constructor
		Option::Option(const Option& s) : m_S(s.m_S), m_K(s.m_K), m_r(s.m_r), m_sig(s.m_sig), isCall(s.isCall)
		{
			//std::cout << "Option Created by Copy......" << std::endl;
		}

		// Destructor
		Option::~Option()
		{
			//std::cout << "Option destroyed......" << std::endl;
		}

		// Operator =
		Option& Option::operator=(const Option& other)
		{
			if (this == &other)
				return *this;
			else
			{
				m_S = other.m_S;
				m_K = other.m_K;
				m_r = other.m_r;
				m_sig = other.m_sig;
				isCall = other.isCall;
				return *this;
			}
		}

		// Setter and Getter
		double Option::S() const
		{
			return m_S;
		}
		void Option::S(double S_val)
		{
			m_S = S_val;
		}

		double Option::K() const
		{
			return m_K;
		}
		void Option::K(double K_val)
		{
			m_K = K_val;
		}

		double Option::r() const
		{
			return m_r;
		}
		void Option::r(double r_val)
		{
			m_r = r_val;
		}

		double Option::sig() const
		{
			return m_sig;
		}
		void Option::sig(double sig_val)
		{
			m_sig = sig_val;
		}

		void Option::Toggle()
		{
			if (isCall)
				isCall = 0;
			else
				isCall = 1;
		}

		bool Option::IsCall() const
		{
			if (isCall)
				return 1;
			else
				return 0;
		}
		// Approximate Delta
		double Option::Approx_Delta(double h) const
		{
			double result;
			result = (Price(m_S + h) - Price(m_S - h)) / (2 * h);
			
			return result;
		}

		// Approximate Gamma
		double Option::Approx_Gamma(double h) const
		{
			double result;
			result = (Price(m_S + h) - 2 * Price() + Price(m_S - h)) / (h * h);

			return result;
		}




	}
}