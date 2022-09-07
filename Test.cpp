// Test.cpp
// This program tests the functionalities of all styles of options.
// Yuguang Shen

#include "OptionData.hpp"
#include "EuroStockOpt.hpp"
#include "EuroFutureOpt.hpp"
#include "EuroCurrencyOpt.hpp"
#include "PerpAmOpt.hpp"
#include "Utilities.hpp"
#include "Exceptions.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
using namespace YShen::Derivatives;

typedef boost::shared_ptr<Option> OptionPtr;

// MatrixPricer()
std::vector<double> MatrixPricer(std::vector<OptionPtr> matrix, std::string cmd)
{
	std::vector<double> result(matrix.size());  // vector to store the final result.

	if (cmd == "price")
	{
		for (int i = 0; i != matrix.size(); i++)
		{
			result[i] = matrix[i]->Price();
			std::cout << matrix[i]->ToString() << "; Price = " << result[i] << std::endl;
		}
	}

	else if (cmd == "delta")
	{
		for (int i = 0; i != matrix.size(); i++)
		{
			result[i] = matrix[i]->Delta();
			std::cout << matrix[i]->ToString() << "; Delta = " << result[i] << std::endl;
		}
	}

	else if (cmd == "gamma")
	{
		for (int i = 0; i != matrix.size(); i++)
		{
			result[i] = matrix[i]->Gamma();
			std::cout << matrix[i]->ToString() << "; Gamma = " << result[i] << std::endl;
		}
	}

	else if (cmd == "approx delta")
	{
		for (int i = 0; i != matrix.size(); i++)
		{
			result[i] = matrix[i]->Approx_Delta(0.01);
			std::cout << matrix[i]->ToString() << "; Approximate Delta = " << result[i] << std::endl;
		}
	}

	else if (cmd == "approx gamma")
	{
		for (int i = 0; i != matrix.size(); i++)
		{
			result[i] = matrix[i]->Approx_Gamma(0.01);
			std::cout << matrix[i]->ToString() << "; Approximate Gamma = " << result[i] << std::endl;
		}
	}

	else
	{
		throw InvalidOperation(cmd);   // Throw exception if an invalid calculation command is given.
	}

	return result;
}


int main()
{
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Part 1: Test EuroStockOpt class. Batch 1~4.
	std::cout << "\nPart 1: Test EuroStockOpt class. Batch 1~4. ***********************************************" << std::endl;
	std::cout << "\n1.1 Test calculations for Batch 1~4." << std::endl;
	EuroStockOpt Batch_1(60, 65, 0.08, 0.30, 1, 0.25, 0); // Test Parameter Constructor. Create Batch 1, call option.

	std::cout << "\nTest Batch 1 Call Option:" << std::endl;
	std::cout << "Batch 1 Call Price: " << Batch_1.Price() << std::endl;
	double Batch_1_call = Batch_1.Price();
	std::cout << "Batch 1 BS Delta: " << Batch_1.Delta() << std::endl;  // Test exact Delta.
	std::cout << "Batch 1 BS Gamma: " << Batch_1.Gamma() << std::endl;  // Test exact Gamma.
	std::cout << "Batch 1 Approximate Delta (h=0.01): " << Batch_1.Approx_Delta(0.01) << std::endl;  // Test Approximate Delta.
	std::cout << "Batch 1 Approximate Gamma (h=0.01): " << Batch_1.Approx_Gamma(0.01) << std::endl;  // Test Approximate Gamma.
	std::cout << Batch_1.ToString() << std::endl;  // Expected output: Batch 1 parameters and type is call

	Batch_1.Toggle();  // Change Batch 1 to put
	std::cout << "\nTest Batch 1 Put Option:" << std::endl;
	std::cout << "Batch 1 Put Price: " << Batch_1.Price() << std::endl;
	double Batch_1_put = Batch_1.Price();
	std::cout << "Batch 1 BS Delta: " << Batch_1.Delta() << std::endl;
	std::cout << "Batch 1 BS Gamma: " << Batch_1.Gamma() << std::endl;
	std::cout << "Batch 1 Approximate Delta (h=0.01): " << Batch_1.Approx_Delta(0.01) << std::endl;
	std::cout << "Batch 1 Approximate Gamma (h=0.01): " << Batch_1.Approx_Gamma(0.01) << std::endl;
	std::cout << Batch_1.ToString() << std::endl; // Expected output: Batch 1 parameters and type is put

	// Test Copy Constructor and operator =
	std::cout << "\nTest Copy Constructor and operator =:\n";
	EuroStockOpt temp1 = Batch_1;         // Test operator =. Assign Batch 1 to temp 1 using operator =
	std::cout << "EuroStockOpt temp1: " << std::endl;
	std::cout << temp1.ToString() << std::endl;  // Expected output: same parameters with Batch 1 and type is put

	EuroStockOpt temp2(Batch_1);         // Test Copy Constructor for EuroStockOpt class.
	std::cout << "EuroStockOpt temp2: " << std::endl;
	std::cout << temp2.ToString() << std::endl;  // Expected output: same parameters with Batch 1 and type is put.
	
	

	EuroStockOpt Batch_2;   // Test Default Constructor for EuroStockOpt class.
	std::cout << "Batch_2 by Default Constructor: " << std::endl << Batch_2.ToString() << std::endl; // Expected output: All parameters are 0, call option.

	// Test Setter and Getter on Batch_2. Input parameters of Batch_2.
	Batch_2.S(100.0);
	Batch_2.K(100.0);
	Batch_2.T(1.0);
	Batch_2.sig(0.2);
	Batch_2.r(0.0);
	std::cout << "Batch_2 after applying Setters: " << std::endl << Batch_2.ToString() << std::endl; // Expected output: Batch 2 parameters, call option.

	std::cout << "\nTest Batch 2 Call Option:" << std::endl;
	std::cout << "Batch 2 Call Price: " << Batch_2.Price() << std::endl;
	double Batch_2_call = Batch_2.Price();
	std::cout << "Batch 2 BS Delta: " << Batch_2.Delta() << std::endl;  // Test exact Delta.
	std::cout << "Batch 2 BS Gamma: " << Batch_2.Gamma() << std::endl;  // Test exact Gamma.
	std::cout << "Batch 2 Approximate Delta (h=0.01): " << Batch_2.Approx_Delta(0.01) << std::endl;  // Test Approximate Delta.
	std::cout << "Batch 2 Approximate Gamma (h=0.01): " << Batch_2.Approx_Gamma(0.01) << std::endl;  // Test Approximate Gamma.
	std::cout << Batch_2.ToString() << std::endl;  // Expected output: Batch 2 parameters and type is call

	Batch_2.Toggle();  // Change Batch 2 to put
	std::cout << "\nTest Batch 2 Put Option:" << std::endl;
	std::cout << "Batch 2 Put Price: " << Batch_2.Price() << std::endl;
	double Batch_2_put = Batch_2.Price();
	std::cout << "Batch 2 BS Delta: " << Batch_2.Delta() << std::endl;
	std::cout << "Batch 2 BS Gamma: " << Batch_2.Gamma() << std::endl;
	std::cout << "Batch 2 Approximate Delta (h=0.01): " << Batch_2.Approx_Delta(0.01) << std::endl;
	std::cout << "Batch 2 Approximate Gamma (h=0.01): " << Batch_2.Approx_Gamma(0.01) << std::endl;
	std::cout << Batch_2.ToString() << std::endl; // Expected output: Batch 2 parameters and type is put

	// Test Batch 3.
	EuroStockOpt Batch_3(5, 10, 0.12, 0.50, 1, 1.0, 0);  // Create EuroStockOpt object Batch_3 by Parameter Constructor
	std::cout << "\nTest Batch 3 Call Option:" << std::endl;
	std::cout << Batch_3.ToString() << std::endl;        // Expected output: Batch 3 parameters, call option.
	std::cout << "Batch 3 Call Price: " << Batch_3.Price() << std::endl;
	double Batch_3_call = Batch_3.Price();
	std::cout << "Batch 3 BS Delta: " << Batch_3.Delta() << std::endl;  // Test exact Delta.
	std::cout << "Batch 3 BS Gamma: " << Batch_3.Gamma() << std::endl;  // Test exact Gamma.
	std::cout << "Batch 3 Approximate Delta (h=0.01): " << Batch_3.Approx_Delta(0.01) << std::endl;  // Test Approximate Delta.
	std::cout << "Batch 3 Approximate Gamma (h=0.01): " << Batch_3.Approx_Gamma(0.01) << std::endl;  // Test Approximate Gamma.
	std::cout << Batch_3.ToString() << std::endl;  // Expected output: Batch 3 parameters and type is call

	Batch_3.Toggle();  // Change Batch 3 to put
	std::cout << "\nTest Batch 3 Put Option:" << std::endl;
	std::cout << "Batch 3 Put Price: " << Batch_3.Price() << std::endl;
	double Batch_3_put = Batch_3.Price();
	std::cout << "Batch 3 BS Delta: " << Batch_3.Delta() << std::endl;
	std::cout << "Batch 3 BS Gamma: " << Batch_3.Gamma() << std::endl;
	std::cout << "Batch 3 Approximate Delta (h=0.01): " << Batch_3.Approx_Delta(0.01) << std::endl;
	std::cout << "Batch 3 Approximate Gamma (h=0.01): " << Batch_3.Approx_Gamma(0.01) << std::endl;
	std::cout << Batch_3.ToString() << std::endl; // Expected output: Batch 3 parameters and type is put

	// Test Batch 4
	EuroStockOpt Batch_4(100.0, 100.0, 0.08, 0.30, 1, 30.0, 0);  // Create EuroStockOpt object Batch_4 by Parameter Constructor.
	std::cout << "\nTest Batch 4 Call Option:" << std::endl;
	std::cout << Batch_4.ToString() << std::endl;        // Expected output: Batch 4 parameters, call option.
	std::cout << "Batch 4 Call Price: " << Batch_4.Price() << std::endl;
	double Batch_4_call = Batch_4.Price();
	std::cout << "Batch 4 BS Delta: " << Batch_4.Delta() << std::endl;  // Test exact Delta.
	std::cout << "Batch 4 BS Gamma: " << Batch_4.Gamma() << std::endl;  // Test exact Gamma.
	std::cout << "Batch 4 Approximate Delta (h=0.01): " << Batch_4.Approx_Delta(0.01) << std::endl;  // Test Approximate Delta.
	std::cout << "Batch 4 Approximate Gamma (h=0.01): " << Batch_4.Approx_Gamma(0.01) << std::endl;  // Test Approximate Gamma.
	std::cout << Batch_4.ToString() << std::endl;  // Expected output: Batch 4 parameters and type is call

	Batch_4.Toggle();  // Change Batch 4 to put
	std::cout << "\nTest Batch 4 Put Option:" << std::endl;
	std::cout << "Batch 4 Put Price: " << Batch_4.Price() << std::endl;
	double Batch_4_put = Batch_4.Price();
	std::cout << "Batch 4 BS Delta: " << Batch_4.Delta() << std::endl;
	std::cout << "Batch 4 BS Gamma: " << Batch_4.Gamma() << std::endl;
	std::cout << "Batch 4 Approximate Delta (h=0.01): " << Batch_4.Approx_Delta(0.01) << std::endl;
	std::cout << "Batch 4 Approximate Gamma (h=0.01): " << Batch_4.Approx_Gamma(0.01) << std::endl;
	std::cout << Batch_4.ToString() << std::endl; // Expected output: Batch 4 parameters and type is put

	// Test Put-Call Parity related functions on Batch 1~4.
	std::cout << "\n1.2 Test Put-Call Parity related functions on Batch 1~4." << std::endl << std::endl;

	std::cout << "Batch 1 Parity Call price: " << Batch_1.Parity_Call(Batch_1_put) << std::endl;  // Expected output: 2.13337
	std::cout << "Batch 1 Parity Put price: " << Batch_1.Parity_Put(Batch_1_call) << std::endl;    // Expected output: 5.84628
	if (Batch_1.Parity_Satisfy(Batch_1_call, Batch_1_put))                                             // Expected output: Put-Call Parity Match!
	{
		std::cout << "Put-Call Parity Match!" << std::endl;
	}
	else
	{
		std::cout << "Parity Not Match!" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Batch 2 Parity Call price: " << Batch_2.Parity_Call(Batch_2_put) << std::endl;  
	std::cout << "Batch 2 Parity Put price: " << Batch_2.Parity_Put(Batch_2_call) << std::endl;    
	if (Batch_2.Parity_Satisfy(Batch_2_call, Batch_2_put))                                             // Expected output: Put-Call Parity Match!
	{
		std::cout << "Put-Call Parity Match!" << std::endl;
	}
	else
	{
		std::cout << "Parity Not Match!" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Batch 3 Parity Call price: " << Batch_3.Parity_Call(Batch_3_put) << std::endl;  
	std::cout << "Batch 3 Parity Put price: " << Batch_3.Parity_Put(Batch_3_call) << std::endl;    
	if (Batch_3.Parity_Satisfy(Batch_3_call, Batch_3_put))                                             // Expected output: Put-Call Parity Match!
	{
		std::cout << "Put-Call Parity Match!" << std::endl;
	}
	else
	{
		std::cout << "Parity Not Match!" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Batch 4 Parity Call price: " << Batch_4.Parity_Call(Batch_4_put) << std::endl;  
	std::cout << "Batch 4 Parity Put price: " << Batch_4.Parity_Put(Batch_4_call) << std::endl;    
	if (Batch_4.Parity_Satisfy(Batch_4_call, Batch_4_put))                                             // Expected output: Put-Call Parity Match!
	{
		std::cout << "Put-Call Parity Match!" << std::endl;
	}
	else
	{
		std::cout << "Parity Not Match!" << std::endl;
	}
	std::cout << std::endl;

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Part 2: Test MatrixPricer() for EuroStockOpt price calculation.
	std::cout << "\nPart 2: Test MatrixPricer() for EuroStockOpt price calculation.******************************************************" << std::endl;
	std::cout << "\n2.1 Test option price calculation using Batch_1 call and put option, let S change from 30 to 60:\n" << std::endl;
	try
	{
		OptionData batch1_data = { StyleSelect("EuroStock"), 1, 60, 65, 0.25, 0.3, 0.08, 0, 0, 0 }; // Create an OptionData obj using Batch_1 call parameters.
		std::vector<double> S_mesh = Mesher(30, 60, 1);      // Generate mesh of S using Mesher function.
		// Calling MatrixFactory() to generate a option matrix, then use it as argument of MatrixPricer() 
		std::vector<double> Batch_1_mtx_price_call = MatrixPricer(MatrixFactory(batch1_data, S_mesh, "S"), "price");
		batch1_data.isCall = 0;   // Change batch_1 OptionData to put.
		std::cout << std::endl;
		std::vector<double> Batch_1_mtx_price_put = MatrixPricer(MatrixFactory(batch1_data, S_mesh, "S"), "price");
	}
	catch (InvalidInput& err)
	{
		std::cout << err.What() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unhandled Exception Occured!" << std::endl;
	}

	std::cout << "\n2.2 Test Exception Handling for StyleSelect() function. An invalid option style is given on purpose:\n" << std::endl;
	try
	{
		OptionData batch1_data = { StyleSelect("A Cool Option"), 1, 60, 65, 0.25, 0.3, 0.08, 0, 0, 0 }; // "A Cool Option" is invalid. Will throw exception.
		std::vector<double> S_mesh = Mesher(10, 60, 1);      // Generate mesh of S using Mesher function.
		std::vector<double> Batch_1_mtx_price = MatrixPricer(MatrixFactory(batch1_data, S_mesh, "S"), "price");
	}
	catch (InvalidInput& err)
	{
		std::cout << err.What() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unhandled Exception Occured!" << std::endl;
	}

	std::cout << "\n2.3 Test Exception Handling for MatrixPricer() function. An invalid calculation command is given on purpose:\n" << std::endl;
	try
	{
		OptionData batch1_data = { StyleSelect("EuroStock"), 1, 60, 65, 0.25, 0.3, 0.08, 0, 0, 0 }; // Create an OptionData obj using Batch_1 call parameters.
		std::vector<double> S_mesh = Mesher(10, 60, 1);      // Generate mesh of S using Mesher function.
		std::vector<double> Batch_1_mtx_price = MatrixPricer(MatrixFactory(batch1_data, S_mesh, "S"), "vega");  // vega is not implemented. Will throw exception.
	}
	catch (InvalidInput& err)
	{
		std::cout << err.What() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unhandled Exception Occured!" << std::endl;
	}

	std::cout << "\n2.4 Test MatrixPricer() function. Let any parameter change. Let K of Batch_1 change from 40 to 65:\n" << std::endl;
	try
	{
		OptionData batch1_data = { StyleSelect("EuroStock"), 1, 60, 65, 0.25, 0.3, 0.08, 0, 0, 0 }; // Create an OptionData obj using Batch_1 call parameters.
		std::vector<double> K_mesh = Mesher(40, 65, 1);      // Generate mesh of K using Mesher function.
		// Calling MatrixFactory() to generate a option matrix, then use it as argument of MatrixPricer() 
		std::vector<double> Batch_1_mtx_price = MatrixPricer(MatrixFactory(batch1_data, K_mesh, "K"), "price");  // 
	}
	catch (InvalidInput& err)
	{
		std::cout << err.What() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unhandled Exception Occured!" << std::endl;
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Part 3: Test EuroFutureOpt class
	std::cout << "\nPart 3: Test Euro Future Option class.*********************************************************************" << std::endl;
	EuroFutureOpt future_opt(105, 100, 0.1, 0.36, 1, 0.5);  // Create an EuroFutureOpt object with parameters.

	std::cout << "\n3.1 Test Future Option Call Option:" << std::endl;
	std::cout << "Future Option Call Price: " << future_opt.Price() << std::endl;
	std::cout << "Future Call Option BS Delta: " << future_opt.Delta() << std::endl;  // Test exact Delta.
	std::cout << "Future Call Option BS Gamma: " << future_opt.Gamma() << std::endl;  // Test exact Gamma.
	std::cout << "Future Call Approximate Delta (h=0.01): " << future_opt.Approx_Delta(0.01) << std::endl;  // Test Approximate Delta.
	std::cout << "Future Call Approximate Gamma (h=0.01): " << future_opt.Approx_Gamma(0.01) << std::endl;  // Test Approximate Gamma.
	std::cout << future_opt.ToString() << std::endl;  // Expected output: future_opt parameters and type is call

	future_opt.Toggle();  // Change to put
	std::cout << "\n3.2 Test Future Option Put Option:" << std::endl;
	std::cout << "Future Option Put Price: " << future_opt.Price() << std::endl;
	std::cout << "Future Put Option BS Delta: " << future_opt.Delta() << std::endl;  // Test exact Delta.
	std::cout << "Future Put Option BS Gamma: " << future_opt.Gamma() << std::endl;  // Test exact Gamma.
	std::cout << "Future Put Approximate Delta (h=0.01): " << future_opt.Approx_Delta(0.01) << std::endl;  // Test Approximate Delta.
	std::cout << "Future Put Approximate Gamma (h=0.01): " << future_opt.Approx_Gamma(0.01) << std::endl;  // Test Approximate Gamma.
	std::cout << future_opt.ToString() << std::endl;  // Expected output: future_opt parameters and type is put

	std::cout << "\n3.3 Test MatrixPricer(). Compute Call Delta and Gamma for range of S from 80 to 105 for the above Euro Future Option:" << std::endl;
	try
	{
		OptionData future_opt_data = { StyleSelect("EuroFuture"), 1, 105, 100, 0.5, 0.36, 0.1, 0, 0, 0 }; // Create an OptionData obj using the above parameters.
		std::vector<double> S_mesh = Mesher(80, 105, 1);      // Generate mesh of S using Mesher function.
		// Calling MatrixFactory() to generate a option matrix, then use it as argument of MatrixPricer() 
		std::vector<double> future_opt_mtx_delta = MatrixPricer(MatrixFactory(future_opt_data, S_mesh, "S"), "delta");
		std::cout << std::endl;
		std::vector<double> future_opt_mtx_gamma = MatrixPricer(MatrixFactory(future_opt_data, S_mesh, "S"), "gamma");
	}
	catch (InvalidInput& err)
	{
		std::cout << err.What() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unhandled Exception Occured!" << std::endl;
	}

	std::cout << "\n3.4 Test MatrixPricer(). Compute approximate Call Delta and Gamma (h=0.01) for range of S from 80 to 105 for the above Euro Future Option:" << std::endl;
	try
	{
		OptionData future_opt_data = { StyleSelect("EuroFuture"), 1, 105, 100, 0.5, 0.36, 0.1, 0, 0, 0 }; // Create an OptionData obj using the above parameters.
		std::vector<double> S_mesh = Mesher(80, 105, 1);      // Generate mesh of S using Mesher function.
		// Calling MatrixFactory() to generate a option matrix, then use it as argument of MatrixPricer() 
		std::vector<double> future_opt_mtx_delta = MatrixPricer(MatrixFactory(future_opt_data, S_mesh, "S"), "approx delta");
		std::cout << std::endl;
		std::vector<double> future_opt_mtx_gamma = MatrixPricer(MatrixFactory(future_opt_data, S_mesh, "S"), "approx gamma");
	}
	catch (InvalidInput& err)
	{
		std::cout << err.What() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unhandled Exception Occured!" << std::endl;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Part 4: Test Perpetual American Option class.
	std::cout << "\nPart 4: Test Perpetual American Option class.*************************************************" << std::endl;
	PerpAmOpt perpam_opt(110, 100, 0.1, 0.1, 1, 0.02);  // Create a PerpAmOption object with paraeters.

	std::cout << "\n4.1 Test Perpetual American Option Call Option:" << std::endl;
	std::cout << "Perpetual American Call Price: " << perpam_opt.Price() << std::endl;
	std::cout << "Perpetual American Call Approximate Delta (h=0.01): " << perpam_opt.Approx_Delta(0.01) << std::endl;  // Test Approximate Delta.
	std::cout << "Perpetual American Call Approximate Gamma (h=0.01): " << perpam_opt.Approx_Gamma(0.01) << std::endl;  // Test Approximate Gamma.
	std::cout << perpam_opt.ToString() << std::endl;  // Expected output: perpam_opt parameters and type is call

	perpam_opt.Toggle();  // Change to put
	std::cout << "\n4.2 Test Perpetual American Option Put Option:" << std::endl;
	std::cout << "Perpetual American Option Put Price: " << perpam_opt.Price() << std::endl;
	std::cout << "Perpetual American Put Approximate Delta (h=0.01): " << perpam_opt.Approx_Delta(0.01) << std::endl;  // Test Approximate Delta.
	std::cout << "Perpetual American Put Approximate Gamma (h=0.01): " << perpam_opt.Approx_Gamma(0.01) << std::endl;  // Test Approximate Gamma.
	std::cout << perpam_opt.ToString() << std::endl;  // Expected output: future_opt parameters and type is put

	std::cout << "\n4.3 Test MatrixPricer(). Compute Call and Put price for range of S from 90 to 110 for the above Perp American Option:" << std::endl;
	try
	{
		OptionData perpam_opt_call_data = { StyleSelect("PerpAmerican"), 1, 110, 100, 0, 0.1, 0.1, 0.02, 0, 0 }; // OptionData for the above Perp Am call
		OptionData perpam_opt_put_data = { StyleSelect("PerpAmerican"), 0, 110, 100, 0, 0.1, 0.1, 0.02, 0, 0 }; // OptionData for the above Perp Am put
		std::vector<double> S_mesh = Mesher(90, 110, 1);  // Generate mesh for S.
		std::vector<double> perpam_opt_mtx_call = MatrixPricer(MatrixFactory(perpam_opt_call_data, S_mesh, "S"), "price");
		std::cout << std::endl;
		std::vector<double> perpam_opt_mtx_put = MatrixPricer(MatrixFactory(perpam_opt_put_data, S_mesh, "S"), "price");

	}
	catch (InvalidInput& err)
	{
		std::cout << err.What() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unhandled Exception Occured!" << std::endl;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Part 5: Experiment divided difference approximation with different h. 
	std::cout << "\nPart 5: Experiment divided difference approximation with different h.*************************************************" << std::endl;
	std::cout << "\nUse the Euro Future Option in Part 3 as the example:\n" << std::endl;
	std::cout << future_opt.ToString() << std::endl;
	std::cout << "Future Option BS Delta: " << future_opt.Delta() << std::endl;  // Test exact Delta.
	std::cout << "Future Option BS Gamma: " << future_opt.Gamma() << std::endl;  // Test exact Gamma.
	std::cout << "Future Approximate Delta (h=10): " << future_opt.Approx_Delta(10) << std::endl;  // Test Approximate Delta.
	std::cout << "Future Approximate Gamma (h=10): " << future_opt.Approx_Gamma(10) << std::endl;  // Test Approximate Gamma.
	std::cout << "Future Approximate Delta (h=1): " << future_opt.Approx_Delta(1) << std::endl;  // Test Approximate Delta.
	std::cout << "Future Approximate Gamma (h=1): " << future_opt.Approx_Gamma(1) << std::endl;  // Test Approximate Gamma.
	std::cout << "Future Approximate Delta (h=0.1): " << future_opt.Approx_Delta(0.1) << std::endl;  // Test Approximate Delta.
	std::cout << "Future Approximate Gamma (h=0.1): " << future_opt.Approx_Gamma(0.1) << std::endl;  // Test Approximate Gamma.
	std::cout << "Future Approximate Delta (h=0.01): " << future_opt.Approx_Delta(0.01) << std::endl;  // Test Approximate Delta.
	std::cout << "Future Approximate Gamma (h=0.01): " << future_opt.Approx_Gamma(0.01) << std::endl;  // Test Approximate Gamma.
	std::cout << "Future Approximate Delta (h=0.0001): " << future_opt.Approx_Delta(0.0001) << std::endl;  // Test Approximate Delta.
	std::cout << "Future Approximate Gamma (h=0.0001): " << future_opt.Approx_Gamma(0.0001) << std::endl;  // Test Approximate Gamma.
	std::cout << "Future Approximate Delta (h=0.000001): " << future_opt.Approx_Delta(0.000001) << std::endl;  // Test Approximate Delta.
	std::cout << "Future Approximate Gamma (h=0.000001): " << future_opt.Approx_Gamma(0.000001) << std::endl;  // Test Approximate Gamma.
	std::cout << "Future Approximate Delta (h=0.0000000000001): " << future_opt.Approx_Delta(0.0000000000001) << std::endl;  // Test Approximate Delta.
	std::cout << "Future Approximate Gamma (h=0.0000000000001): " << future_opt.Approx_Gamma(0.0000000000001) << std::endl;  // Test Approximate Gamma.

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Part 6: Test the MatrixPricer(). Input a matrix of all different kinds of OptionData and then calculate Price, Delta and Gamma.
	std::cout << "\nPart 6: Test MatrixPricer(). Input a matrix of different kinds of OptionData and then perform calculations.***********" << std::endl;

	// Create the matrix. 
	// The user will agree to input the parameters exactly as the order of variables being declared in OptionData.
	// Option style input is through a function called SelectStyle(), which takes a string as input.
	// "EuroStock" = EuroStockOpt; "EuroFuture" = EuroFutureOpt; "EuroCurrency" = EuroCurrencyOpt; "PerpAmerican" = PerpAmOpt
	// If certain parameters are not available for certain options, just type 0.
	// Batch 1-4, the future option, and the Perpetual American option from this HW will be used.
	try
	{
		std::vector<OptionData> mtx =
		{
			{StyleSelect("EuroStock"), 1, 60, 65, 0.25, 0.3, 0.08, 0, 0, 0},
			{StyleSelect("EuroStock"), 0, 60, 65, 0.25, 0.3, 0.08, 0, 0, 0},
			{StyleSelect("EuroStock"), 1, 100, 100, 1.0, 0.2, 0.0, 0, 0, 0},
			{StyleSelect("EuroStock"), 0, 100, 100, 1.0, 0.2, 0.0, 0, 0, 0},
			{StyleSelect("EuroStock"), 1, 5, 10, 1.0, 0.5, 0.12, 0, 0, 0},
			{StyleSelect("EuroStock"), 0, 5, 10, 1.0, 0.5, 0.12, 0, 0, 0},
			{StyleSelect("EuroStock"), 1, 100, 100, 30.0, 0.3, 0.08, 0, 0, 0},
			{StyleSelect("EuroStock"), 0, 100, 100, 30.0, 0.3, 0.08, 0, 0, 0},
			{StyleSelect("PerpAmerican"), 1, 110, 100, 0, 0.1, 0.1, 0.02, 0, 0},
			{StyleSelect("PerpAmerican"), 0, 110, 100, 0, 0.1, 0.1, 0.02, 0, 0},
			{StyleSelect("EuroFuture"), 1, 105, 100, 0.5, 0.36, 0.1, 0, 0, 0},
			{StyleSelect("EuroFuture"), 0, 105, 100, 0.5, 0.36, 0.1, 0, 0, 0},
		};
		std::cout << "\nCalculate Price:" << std::endl;
		std::vector<double> mtx_price = MatrixPricer(MatrixFactory(mtx), "price");
		std::cout << "\nCalculate Delta:" << std::endl;
		std::vector<double> mtx_delta = MatrixPricer(MatrixFactory(mtx), "delta");
		std::cout << "\nCalculate Gamma:" << std::endl;
		std::vector<double> mtx_gamma = MatrixPricer(MatrixFactory(mtx), "gamma");
	}
	catch (InvalidInput& err)
	{
		std::cout << err.What() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unhandled Exception Occured!" << std::endl;
	}

	return 0;
}