// Utilities.cpp
// Implementation for the functions in Utilities.hpp
// Yuguang Shen

#include "Utilities.hpp"
#include "EuroStockOpt.hpp"
#include "EuroFutureOpt.hpp"
#include "EuroCurrencyOpt.hpp"
#include "PerpAmOpt.hpp"
#include "Exceptions.hpp"
using namespace YShen::Derivatives;

// Mesher(), which generates a vector of double with step of h.
std::vector<double> Mesher(double start, double end, double h)
{
	std::vector<double> mesh;
	double temp = start;
	while (temp <= end)
	{
		mesh.push_back(temp);
		temp += h;
	}
	return mesh;
}

// StyleSelect()
int StyleSelect(std::string input)
{
	// This map named Styles contains all the available option styles and assigns an int to each of them.
	std::map<std::string, int> Styles = { {"EuroStock", 0}, {"EuroFuture", 1}, {"EuroCurrency", 2}, {"PerpAmerican", 3} };
	// Create an iterator for map Styles.
	std::map <std::string, int>::iterator it;
	for (it = Styles.begin(); it != Styles.end(); it++)  // Iterate through map.
	{
		if (it->first == input)
		{
			return it->second;
		}
	}

	throw InvalidStyle(input);          // Throw InvalidStyle exception when the user types in an invalid option style.
}

// MatrixFactory() ver 1.
// This function is implemented in two steps.
// Step 1: Expand the single OptionData data into a vector of OptionData, in which there is only one parameter changing as per the mesh input.
// Step 2: Transfer the OptionData vector above into a vector of smart pointers to correspongding options.

std::vector<OptionPtr> MatrixFactory(OptionData data, std::vector<double> mesh, std::string param)
{
	int size = mesh.size();
	std::vector<OptionData> data_vec(size);  // vector to store the OptionData objects
	std::vector<OptionPtr> result(size);   // vector to store the final OptionPtr

	// Step 1.
	if (param == "S")
	{
		for (int i = 0; i != size; i++)
		{
			data.S = mesh[i];
			data_vec[i] = data;
		}
	}
	
	else if (param == "K")
	{
		for (int i = 0; i != size; i++)
		{
			data.K = mesh[i];
			data_vec[i] = data;
		}
	}

	else if (param == "r")
	{
		for (int i = 0; i != size; i++)
		{
			data.r = mesh[i];
			data_vec[i] = data;
		}
	}

	else if (param == "sig")
	{
		for (int i = 0; i != size; i++)
		{
			data.sig = mesh[i];
			data_vec[i] = data;
		}
	}

	else if (param == "T")
	{
		for (int i = 0; i != size; i++)
		{
			data.T = mesh[i];
			data_vec[i] = data;
		}
	}

	else if (param == "q")
	{
		for (int i = 0; i != size; i++)
		{
			data.q = mesh[i];
			data_vec[i] = data;
		}
	}

	else if (param == "R")
	{
		for (int i = 0; i != size; i++)
		{
			data.R = mesh[i];
			data_vec[i] = data;
		}
	}

	else if (param == "b")
	{
		for (int i = 0; i != size; i++)
		{
			data.b = mesh[i];
			data_vec[i] = data;
		}
	}

	else
	{
		throw InvalidParameter(param);  // Throw InvalidParameter exception when the user assigns an invalid option parameter to change.
	}

	// Step 2.
	for (int i = 0; i != size; i++)
	{
		switch (data_vec[i].opt_style)
		{
		
		case 0:
		{
			result[i] =
				boost::make_shared<EuroStockOpt>(EuroStockOpt(data_vec[i].S, data_vec[i].K, data_vec[i].r, data_vec[i].sig, data_vec[i].isCall, data_vec[i].T, data_vec[i].q));
			break;
		}

		case 1:
		{
			result[i] =
				boost::make_shared<EuroFutureOpt>(EuroFutureOpt(data_vec[i].S, data_vec[i].K, data_vec[i].r, data_vec[i].sig, data_vec[i].isCall, data_vec[i].T));
			break;
		}

		case 2:
		{
			result[i] =
				boost::make_shared<EuroCurrencyOpt>(EuroCurrencyOpt(data_vec[i].S, data_vec[i].K, data_vec[i].r, data_vec[i].sig, data_vec[i].isCall, data_vec[i].T, data_vec[i].R));
			break;
		}

		case 3:
		{
			result[i] =
				boost::make_shared<PerpAmOpt>(PerpAmOpt(data_vec[i].S, data_vec[i].K, data_vec[i].r, data_vec[i].sig, data_vec[i].isCall, data_vec[i].b));
			break;
		}

		default:
		{
			throw InvalidStyle("Current Option Style");  // Throw InvalidStyle exception when an invalid option style is detected.
		}

		}
	}

	// Finish
	return result;

}



// MatrixFactory() ver 2. This overloaded version takes a vector of OptionData and return a vector of corresponding smart pointers to options.
// This is essentially just Step 2 in ver 1.
std::vector<OptionPtr> MatrixFactory(std::vector<OptionData> data_vec)
{
	int size = data_vec.size();
	std::vector<OptionPtr> result(size);   // vector to store the final OptionPtr

	// Step 2.
	for (int i = 0; i != size; i++)
	{
		switch (data_vec[i].opt_style)
		{

		case 0:
		{
			result[i] =
				boost::make_shared<EuroStockOpt>(EuroStockOpt(data_vec[i].S, data_vec[i].K, data_vec[i].r, data_vec[i].sig, data_vec[i].isCall, data_vec[i].T, data_vec[i].q));
			break;
		}

		case 1:
		{
			result[i] =
				boost::make_shared<EuroFutureOpt>(EuroFutureOpt(data_vec[i].S, data_vec[i].K, data_vec[i].r, data_vec[i].sig, data_vec[i].isCall, data_vec[i].T));
			break;
		}

		case 2:
		{
			result[i] =
				boost::make_shared<EuroCurrencyOpt>(EuroCurrencyOpt(data_vec[i].S, data_vec[i].K, data_vec[i].r, data_vec[i].sig, data_vec[i].isCall, data_vec[i].T, data_vec[i].R));
			break;
		}

		case 3:
		{
			result[i] =
				boost::make_shared<PerpAmOpt>(PerpAmOpt(data_vec[i].S, data_vec[i].K, data_vec[i].r, data_vec[i].sig, data_vec[i].isCall, data_vec[i].b));
			break;
		}

		default:
		{
			throw InvalidStyle("Current Option Style");  // Throw InvalidStyle exception when an invalid option style is detected.
		}

		}
	}

	// Finish
	return result;

}

