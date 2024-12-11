#include <string>
#include "ButtonIDDefines.h"
#pragma once

/// <summary>
/// Singleton that handles the processing for the Calculator
/// </summary>
class CalculatorProcessor
{
	static CalculatorProcessor* _instance;

protected:
	CalculatorProcessor();
	~CalculatorProcessor();
	float EvaluateExpression(const std::string& expression) const;
	float Process(const std::string left, const char mathOp, const std::string right) const;
public:
	/// <summary>
	/// Returns a reference to the processor
	/// </summary>
	/// <returns></returns>
	static CalculatorProcessor* GetInstance();
	/// <summary>
	/// Releases control of the reference to the processor
	/// </summary>
	static void ResetInstance();
	/// <summary>
	/// Parses an expression and returns its numerical value
	/// </summary>
	/// <param name="input"></param>
	/// <returns></returns>
	float ParseExpression(std::string input) const;
	
	float EvaluateTrigFunction(const unsigned int id, const std::string text) const;

	CalculatorProcessor(CalculatorProcessor& other) = delete;

	void operator=(CalculatorProcessor& other) = delete;
};

