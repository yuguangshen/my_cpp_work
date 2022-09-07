// EuroCurrencyOpt.hpp
// Header file for the EuroCurrencyOpt class, which is derived from the EuroOpt class.
// Yuguang Shen

#ifndef EUROCURRENCYOPT_HPP
#define EUROCURRENCYOPT_HPP

#include "EuroOpt.hpp"

namespace YShen
{
	namespace Derivatives
	{
		class EuroCurrencyOpt : public EuroOpt
		{
		private: 
			double m_R;
		public:
			// Default Constructor
			EuroCurrencyOpt();
			// Parameter constructor
			EuroCurrencyOpt(double S, double K, double r, double sig, bool opt_type, double T, double R);
			// Copy Constructor
			EuroCurrencyOpt(const EuroCurrencyOpt& s);
			// Destructor
			~EuroCurrencyOpt();

			// Operator =
			EuroCurrencyOpt& operator = (const EuroCurrencyOpt& other);

			// Setter and Getter
			double R() const;
			void R(double R_val);

			// Cost of Carry
			double CoC() const;

			// ToString()
			std::string ToString() const;
		};
	}
}
#endif // !EUROCURRENCYOPT_HPP


