// Option.hpp
// The header file for the Option class, which is an Abstract Base Class (ABC).
// The Option class has no data members, which are left to the derived classes to implement.
// The Option class has the following functions: CallPrice(), PutPrice() and ToString(), which are all PVMF. Thus, the Option class is an interface.
// Yuguang Shen

#ifndef OPTION_HPP
#define OPTION_HPP

#include <iostream>

namespace YShen
{
	namespace Derivatives
	{
		class Option
		{
			// Common data members for an Option
		private:
			double m_S;
			double m_K;
			double m_r;
			double m_sig;
			bool isCall;

		public:
			// Default Constructor, all parameters are set to 0 and isCall = 1.
			Option();
			// Parameter Constructor
			Option(double S, double K, double r, double sig, bool opt_type);
			// Copy Constructor
			Option(const Option& s);
			// Destructor
			virtual ~Option();

			// Operator =
			Option& operator = (const Option& other);

			// Setter and Getter

			double S() const;
			void S(double S_val);

			double K() const;
			void K(double K_val);

			double r() const;
			void r(double r_val);

			double sig() const;
			void sig(double sig_val);

			void Toggle();
			bool IsCall() const;
			
			// Price() function. Overload it to take a different underlying asset price to calculate new price.
			virtual double Price() const = 0;
			virtual double Price(double U) const = 0;

			// Use divided difference to approximate option sensitivities. They are available for all option styles.
			double Approx_Delta(double h) const;
			double Approx_Gamma(double h) const;

			// Exact Delta and Gamma. The implementation is left to dericed classes. If exact Greeks are not available for certain classes, 
			// they will just return the approximate Greeks instead.
			virtual double Delta() const = 0;
			virtual double Gamma() const = 0;

			// Show the Option info on the screen.
			virtual std::string ToString() const = 0;
		};
	}
}
#endif // !OPTION_HPP

