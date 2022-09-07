// EuroStockOpt.hpp
// Header file for the EuroStockOpt class, which is derived from EuroOpt class.
// Yuguang Shen

#ifndef EUROSTOCKOPT_HPP
#define EUROSTOCKOPT_HPP

#include "EuroOpt.hpp"

namespace YShen
{
	namespace Derivatives
	{
		class EuroStockOpt : public EuroOpt
		{
		private: 
			double m_q;

		public:
			// Default Constructor
			EuroStockOpt();
			// Parameter Constructor
			EuroStockOpt(double S, double K, double r, double sig, bool opt_type, double T, double q);
			// Copy Constructor
			EuroStockOpt(const EuroStockOpt& s);
			// Destructor
			virtual ~EuroStockOpt();

			// Operator =
			EuroStockOpt& operator = (const EuroStockOpt& other);

			// Setter and Getter
			double q() const;
			void q(double q_val);

			// Cost of Carry
			double CoC() const;

			// ToString()
			std::string ToString() const;
		};
	}
}
#endif // !EUROSTOCKOPT_HPP

