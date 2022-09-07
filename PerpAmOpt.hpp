// PerpAmOpt.hpp
// Header file for the Perpetual American Option class, which is derived from the Option class.
// Yuguang Shen

#ifndef PERPAMOPT_HPP
#define PERPAMOPT_HPP

#include "Option.hpp"

namespace YShen
{
	namespace Derivatives
	{
		class PerpAmOpt : public Option
		{
		private:
			double m_b;
		public:
			// Default Constructor
			PerpAmOpt();
			// Parameter Constructor
			PerpAmOpt(double S, double K, double r, double sig, bool opt_type, double b);
			// Copy Constructor
			PerpAmOpt(const PerpAmOpt& s);
			// Destructor
			~PerpAmOpt();

			// operator =
			PerpAmOpt& operator = (const PerpAmOpt& other);

			// Setter and Getter
			double b() const;
			void b(double b_val);

			// Price() and overloaded Price(double U)
			double Price() const;
			double Price(double U) const;

			// Greeks. Exact formula not available.
			double Delta() const;
			double Gamma() const;

			// ToString()
			std::string ToString() const;

		};
	}
}
#endif // !PERPAMOPT_HPP

