// EuroOpt.hpp
// Header file for the EuroOpt class.
// Yuguang Shen

#ifndef EUROOPT_HPP
#define EUROOPT_HPP

#include "Option.hpp"

namespace YShen
{
	namespace Derivatives
	{
		class EuroOpt : public Option
		{
		private:
			double m_T;

		public:
			// Default Constructor
			EuroOpt();

			// Parameter Constructor
			EuroOpt(double S, double K, double r, double sig, bool opt_type, double T);

			// Copy Constructor
			EuroOpt(const EuroOpt& s);

			// Destructor
			virtual ~EuroOpt();

			// Operator =
			EuroOpt& operator = (const EuroOpt& other);

			// Setter and Getter
			double T() const;
			void T(double T_val);

			// Cost of Carry
			virtual double CoC() const = 0;

			// Price() and overloaded Price(double U)
			double Price() const;
			double Price(double U) const;

			// Greeks

			double Delta() const;
			double Delta(double U) const;

			double Gamma() const;
			double Gamma(double U) const;

			// Put-Call Parity
			double Parity_Call(double put) const;
			double Parity_Put(double call) const;
			bool Parity_Satisfy(double call, double put) const;


		};
	}
}



#endif // !EUROOPT_HPP

