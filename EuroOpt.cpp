// EuroOpt.cpp
// Implementation of the EuroOpt class.
// Yuguang Shen

#include "EuroOpt.hpp"
#include <iostream>
#include <cmath>
#include <boost/math/distributions/normal.hpp>


namespace YShen
{
	namespace Derivatives
	{
		// Default Constructor
		EuroOpt::EuroOpt() : Option(), m_T(0)
		{
			//std::cout << "EuroOpt Created by Default......" << std::endl;
		}

		// Parameter Constructor
		EuroOpt::EuroOpt(double S, double K, double r, double sig, bool opt_type, double T) : Option(S, K, r, sig, opt_type), m_T(T)
		{
			//std::cout << "EuroOpt Created by Parameter......" << std::endl;
		}

		// Copy Constructor
		EuroOpt::EuroOpt(const EuroOpt& s) : Option(s), m_T(s.m_T)
		{
			//std::cout << "EuroOpt Created by Copy......" << std::endl;
		}

		// Destructor
		EuroOpt::~EuroOpt()
		{
			//std::cout << "EuroOpt destroyed......" << std::endl;
		}

		// Operator =
		EuroOpt& EuroOpt::operator = (const EuroOpt& other)
		{
			if (this == &other)
				return *this;
			else
			{
				Option::operator=(other);
				m_T = other.m_T;
				return *this;
			}
		}

		// Setter and Getter
		double EuroOpt::T() const
		{
			return m_T;
		}
		void EuroOpt::T(double T_val)
		{
			m_T = T_val;
		}
		double EuroOpt::Price()const
		{
			double tmp = sig() * sqrt(m_T);
			double d1 = (log(S() / K()) + (CoC() + (sig() * sig()) * 0.5) * m_T) / tmp;
			double d2 = d1 - tmp;
			boost::math::normal_distribution<double> StdNormal;
			if (IsCall())
			{
				return (S() * exp((CoC() - r()) * m_T) * cdf(StdNormal, d1)) - (K() * exp(-r() * m_T) * cdf(StdNormal, d2));
			}
			else
			{
				return (K() * exp(-r() * m_T) * cdf(StdNormal, -d2)) - (S() * exp((CoC() - r()) * m_T) * cdf(StdNormal, -d1));
			}
		}

		double EuroOpt::Price(double U) const
		{
			double tmp = sig() * sqrt(m_T);
			double d1 = (log(U / K()) + (CoC() + (sig() * sig()) * 0.5) * m_T) / tmp;
			double d2 = d1 - tmp;
			boost::math::normal_distribution<double> StdNormal;
			if (IsCall())
			{
				return (U * exp((CoC() - r()) * m_T) * cdf(StdNormal, d1)) - (K() * exp(-r() * m_T) * cdf(StdNormal, d2));
			}
			else
			{
				return (K() * exp(-r() * m_T) * cdf(StdNormal, -d2)) - (U * exp((CoC() - r()) * m_T) * cdf(StdNormal, -d1));
			}
		}

		// Greeks

		// Delta
		double EuroOpt::Delta() const
		{
			double tmp = sig() * sqrt(m_T);
			double d1 = (log(S() / K()) + (CoC() + (sig() * sig()) * 0.5) * m_T) / tmp;
			boost::math::normal_distribution<double> StdNormal;

			if(IsCall())
				return exp((CoC() - r()) * m_T) * cdf(StdNormal, d1);
			else
				return exp((CoC() - r()) * m_T) * (cdf(StdNormal, d1) - 1.0);
		}
		double EuroOpt::Delta(double U) const
		{
			double tmp = sig() * sqrt(m_T);
			double d1 = (log(U / K()) + (CoC() + (sig() * sig()) * 0.5) * m_T) / tmp;
			boost::math::normal_distribution<double> StdNormal;

			if (IsCall())
				return exp((CoC() - r()) * m_T) * cdf(StdNormal, d1);
			else
				return exp((CoC() - r()) * m_T) * (cdf(StdNormal, d1) - 1.0);
		}

		// Gamma
		double EuroOpt::Gamma() const
		{
			double tmp = sig() * sqrt(m_T);
			double d1 = (log(S() / K()) + (CoC() + (sig() * sig()) * 0.5) * m_T) / tmp;
			double d2 = d1 - tmp;
			boost::math::normal_distribution<double> StdNormal;

			return (pdf(StdNormal, d1) * exp((CoC() - r()) * m_T)) / (S() * tmp);
		}
		double EuroOpt::Gamma(double U) const
		{
			double tmp = sig() * sqrt(m_T);
			double d1 = (log(U / K()) + (CoC() + (sig() * sig()) * 0.5) * m_T) / tmp;
			double d2 = d1 - tmp;
			boost::math::normal_distribution<double> StdNormal;

			return (pdf(StdNormal, d1) * exp((CoC() - r()) * m_T)) / (U * tmp);
		}
		// Put-Call Parity related functions
		double EuroOpt::Parity_Call(double put) const
		{
			return put + S() * exp((CoC() - r()) * m_T) - K() * exp(-r() * m_T);
		}
		double EuroOpt::Parity_Put(double call) const
		{
			return call + K() * exp(-r() * m_T) - S() * exp((CoC() - r()) * m_T);
		}
		bool EuroOpt::Parity_Satisfy(double call, double put) const
		{
			double tol = 1.0 / 100000.0;
			double LHS = call + K() * exp(-r() * m_T);
			double RHS = put + S() * exp((CoC() - r()) * m_T);
			
			if (abs(LHS - RHS) < tol)
			{
				return true;
			}
			else
			{
				return false;
			}
		}



	}
}