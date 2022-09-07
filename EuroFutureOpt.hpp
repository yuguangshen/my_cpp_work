// EuroFutureOpt.hpp
// The header file for the EuroFutureOpt class, which is derived from the EuroOpt class.
// Yuguang Shen

#ifndef EUROFUTUREOPT_HPP
#define EUROFUTUREOPT_HPP

#include "EuroOpt.hpp"

namespace YShen
{
	namespace Derivatives
	{
		class EuroFutureOpt : public EuroOpt
		{
		public:
			// Default COnstructor
			EuroFutureOpt();
			// Parameter Constructor
			EuroFutureOpt(double S, double K, double r, double sig, bool opt_type, double T);
			// Copy Constructor
			EuroFutureOpt(const EuroFutureOpt& s);
			// Destructor
			~EuroFutureOpt();

			// operator =
			EuroFutureOpt& operator = (const EuroFutureOpt& other);

			// Cost of Carry
			double CoC() const;

			// ToString()
			std::string ToString() const;
		};
	}
}
#endif // !EUROFUTUREOPT_HPP
