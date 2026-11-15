#include "Bureaucrat.hpp"

/* ------------------------------------------------------------------ */
/*  Orthodox Canonical Form                                           */
/* ------------------------------------------------------------------ */

Bureaucrat::Bureaucrat() : _name("Default"), _grade(LOWEST_GRADE)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: _name(name), _grade(checkedGrade(grade))
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: _name(other._name), _grade(other._grade)
{
}

/* The name is const, so only the grade can be assigned. */
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

/* ------------------------------------------------------------------ */
/*  Accessors                                                         */
/* ------------------------------------------------------------------ */

const std::string &Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

/* ------------------------------------------------------------------ */
/*  Grade management                                                  */
/* ------------------------------------------------------------------ */

/* Validates a grade and returns it, or throws the matching exception. */
int Bureaucrat::checkedGrade(int grade)
{
	if (grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	if (grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	return (grade);
}

void Bureaucrat::incrementGrade()
{
	this->_grade = checkedGrade(this->_grade - 1);
}

void Bureaucrat::decrementGrade()
{
	this->_grade = checkedGrade(this->_grade + 1);
}

/* ------------------------------------------------------------------ */
/*  Exceptions                                                        */
/* ------------------------------------------------------------------ */

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade is too high (highest possible grade is 1)");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade is too low (lowest possible grade is 150)");
}

/* ------------------------------------------------------------------ */
/*  Insertion operator                                                */
/* ------------------------------------------------------------------ */

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade "
		<< bureaucrat.getGrade() << ".";
	return (out);
}
