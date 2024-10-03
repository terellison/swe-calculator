#include "CalculatorProcessor.h"
#include <list>
#include <cmath>

CalculatorProcessor* CalculatorProcessor::_instance = nullptr;

CalculatorProcessor::CalculatorProcessor()
{
}

CalculatorProcessor::~CalculatorProcessor()
{

}

CalculatorProcessor* CalculatorProcessor::GetInstance()
{
	if (_instance == nullptr)
	{
		_instance = new CalculatorProcessor();
	}

	return _instance;
}

void CalculatorProcessor::ResetInstance()
{
	delete _instance;
	_instance = nullptr;
}

float CalculatorProcessor::EvaluateExpression(const std::string& expression) const
{
	std::list<std::string> stack;
	int num = 0;
	for (auto token = expression.begin(); token != expression.end(); ++token)
	{
		while (std::isdigit(*token))
		{
			num = (num * 10) + (*token - '0');
			++token;

			if (*token == '|')
			{
				stack.push_front(std::to_string(num));
				++token;
				num = 0;
			}
		}
		
		auto right = stack.front();
		stack.pop_front();
		auto left = stack.front();
		stack.pop_front();
		stack.push_front(std::to_string(this->Process(left, *token, right)));
		
	}
	return std::stof(stack.front());
}

float CalculatorProcessor::ParseExpression(std::string expression) const
{
	auto temp = expression.begin();
	std::list<char> opStack;
	std::string postFix{};
	int num = 0;
	bool parsedNum = false;
	while (temp != expression.end())
	{
		if (std::isdigit(*temp))
		{
			num = (num * 10) + (*temp - '0');
			parsedNum = true;
		}
		else
		{
			if (parsedNum)
			{
				postFix += std::to_string(num) + '|';
				parsedNum = false;
				num = 0;
			}

			if (*temp == ')')
			{
				char op = opStack.front();

				while (op != '(')
				{
					postFix += op;
					opStack.pop_front();
					op = opStack.front();
				}

				opStack.pop_front();
				++temp;
				continue;
			}

			char top = opStack.empty() ? ' ' : opStack.front();

			if ((top == '*' || top == '/') && (*temp == '+' || *temp == '-'))
			{
				postFix += top;
				opStack.pop_front();
			}

			opStack.push_front(*temp);
		}
		++temp;
	}

	if (parsedNum)
	{
		postFix += std::to_string(num) + '|';
	}

 	while (!opStack.empty())
	{
		postFix += opStack.front();
		opStack.pop_front();
	}

	return EvaluateExpression(postFix);
}

float CalculatorProcessor::EvaluateTrigFunction(const unsigned int id, const std::string text) const
{
	float num;
	if (
		text.find('+') != std::string::npos
		|| text.find('-') != std::string::npos
		|| text.find('*') != std::string::npos
		|| text.find('/') != std::string::npos
		|| text.find('%') != std::string::npos
		)
	{
		num = ParseExpression(text);
	}
	else
	{
		num = std::stoi(text);
	}

	switch (id)
	{
	case SIN_BUTTON_ID:
		return sin(num);
		break;
	case COSINE_BUTTON_ID:
		return cos(num);
		break;
	default:
		return tan(num);
	}
}

float CalculatorProcessor::Process(const std::string left, const char mathOp, const std::string right) const
{
	switch (mathOp)
	{
	case '+':
		return std::stof(left) + std::stof(right);
	case '-':
		return std::stof(left) - std::stof(right);
	case '*':
		return std::stof(left) * std::stof(right);
	case '/':
		return std::stof(left) / std::stof(right);
	case '^':
		return std::powf(std::stof(left), std::stof(right));
	default:
		return std::stoi(left) % std::stoi(right);
	}
}