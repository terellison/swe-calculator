#include <string>
#include "ButtonIDDefines.h"
#pragma once
class CalculatorProcessor
{
	static CalculatorProcessor* _instance;

protected:
	CalculatorProcessor();
	~CalculatorProcessor();
	float EvaluateExpression(const std::string& expression) const;
	float Process(const std::string left, const char mathOp, const std::string right) const;
public:
	static CalculatorProcessor* GetInstance();

	static void ResetInstance();

	float ParseExpression(std::string input) const;

	float EvaluateTrigFunction(const unsigned int id, const std::string text) const;

	CalculatorProcessor(CalculatorProcessor& other) = delete;

	void operator=(CalculatorProcessor& other) = delete;
};

