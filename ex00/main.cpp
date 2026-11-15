#include "Bureaucrat.hpp"

static void	printTitle(const std::string &title)
{
	std::cout << "\n----- " << title << " -----" << std::endl;
}

int main(void)
{
	printTitle("Valid bureaucrat");
	try
	{
		Bureaucrat alice("Alice", 2);
		std::cout << alice << std::endl;

		alice.incrementGrade();
		std::cout << "After increment: " << alice << std::endl;

		alice.decrementGrade();
		std::cout << "After decrement: " << alice << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	printTitle("Grade too high at construction (0)");
	try
	{
		Bureaucrat overachiever("Overachiever", 0);
		std::cout << overachiever << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	printTitle("Grade too low at construction (151)");
	try
	{
		Bureaucrat slacker("Slacker", 151);
		std::cout << slacker << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	printTitle("Increment past grade 1");
	try
	{
		Bureaucrat best("Best", 1);
		std::cout << best << std::endl;
		best.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	printTitle("Decrement past grade 150");
	try
	{
		Bureaucrat worst("Worst", 150);
		std::cout << worst << std::endl;
		worst.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	printTitle("Copy and assignment");
	{
		Bureaucrat original("Original", 42);
		Bureaucrat copy(original);
		Bureaucrat assigned("Assigned", 100);

		assigned = original;
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy:     " << copy << std::endl;
		std::cout << "Assigned (name is const, grade copied): "
				  << assigned << std::endl;
	}
	return (0);
}
