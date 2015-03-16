// Kelley Stoll
// Stack Project
// Test Driver
// Exercise: Implement infix, postfix, and evaluation through stack template.

#include "stack.h"
#include <iostream>
#include <fstream> // Used for file in/output
#include <string>

using namespace std;

int priority(char symbol) // Prioritizes symbols 
{
	switch (symbol)
	{
	case '(':
		return 3;
		break;

	case ')':
		return 3;
		break;

	case '%':
		return 1;
		break;

	case '+':
		return 2;
		break;

	case '-':
		return 2;
		break;

	case '*':
		return 1;
		break;

	case '/':
		return 1;
		break;

	default:
		return 0;

	}

}



int fakeevaluate(float a, char token, float b, StackType<float> &pink)
{

	int result;
	switch (token)
	{
	case '+':
		pink.two(pink, a, b);
		result = a + b;
		pink.Push(result);
		break;

	case '-':
		pink.two(pink, a, b);
		result = a - b;
		pink.Push(result);
		break;

	case '*':
		pink.two(pink, a, b);
		result = a * b;
		pink.Push(result);
		break;

	case '/':
		pink.two(pink, a, b);
		result = a / b;
		pink.Push(result);
		break;

	case '%':
		pink.two(pink, a, b);
		result = (int)a % (int)b;
		pink.Push(result);
		break;

	default:
		break;
	}
	return result;

}


float realevaluate(string & express)
{

	StackType <float> mason;

	float uno = 0;
	float dos = 0;

	for (int i = 0; i < express.length(); i++)
	{
		char c = express[i];

		if (isspace(c)) // If there is a space, continue the program.
			continue;

		else if (isdigit(c)) // If it is a digit...
		{

			int digit = 0;

			while (isdigit(express[i]))
			{
				digit = 10 * digit + (express[i] - '0'); // Converts from string to int
				i++;
			}

			mason.Push(digit);

		}

		else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%') // If it's one of these characters..
		{

			fakeevaluate(uno, c, dos, mason);


		}
	}

	float returnvalue = mason.Top();
	mason.Pop();
	return returnvalue;

}






int main()
{

	ifstream in_stream; // Input file
	ofstream out_stream; // Output file
	ifstream infinal;
	ofstream outfinal;

	in_stream.open("input.dat"); // Opens input text file.
	out_stream.open("output.dat"); // Opens output text file.

	if (in_stream.fail())
	{
		cout << "No file is provided. Opening failed.\n";
		exit(1); // Ends the program if the if statement is true.

	}

	string expression; // Declares string.
	StackType <char> express; // Declares StackType.




	while (!in_stream.eof()) // While it's not end of file.
	{

		getline(in_stream, expression); // Reads in first line of the text.

		for (int i = 0; i < expression.length(); i++)
		{
			char c = expression[i];

			if (isspace(c)) // If there is a space, continue the program.
				continue;

			else if (isdigit(c)) // If it is a digit...
			{

				//char digit = 0;
				int digit = 0;

				while (isdigit(expression[i]))
				{
					//digit = expression[i];
					digit = 10 * digit + (expression[i] - '0'); // Converts from string to int
					i++;
				}
				i--;
				out_stream << " ";
				out_stream << digit;

			}

			else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%') // If it's one of these characters..
			{
				int integer = priority(c);
				while (!express.IsEmpty() && integer >= priority(express.Top()))
				{
					out_stream << " ";
					out_stream << express.Top();
					express.Pop();
				}
				express.Push(c);

			}

			else if (c == '(')
			{

				express.Push(c);

			}

			else if (c == ')')
			{

				while (express.Top() != '(')
				{
					out_stream << " ";
					out_stream << express.Top();
					express.Pop();

				}
				express.Pop();
			}


		}

		while (!express.IsEmpty())
		{
			out_stream << " ";
			out_stream << express.Top();
			express.Pop();
		}

		out_stream << endl;

	}


	in_stream.close(); // Closes the input file.
	out_stream.close(); // Closes the output file.




	// Evaluation 
	infinal.open("output.dat");
	outfinal.open("finalanswer.dat");
	outfinal << "Your final answer is\n ";


	while (!infinal.eof())
	{
		getline(infinal, expression);

		if (!expression.empty())
		{

			outfinal << realevaluate(expression);

		}


	}

	infinal.close(); // Closes the input file.
	outfinal.close(); // Closes the output file.


	// No black screen because it outputs to a file.
	return 0;
}