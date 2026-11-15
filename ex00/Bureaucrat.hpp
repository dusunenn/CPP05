#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(const std::string &name , int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	const std::string	&getName() const;
	int					getGrade() const;

	void	incrementGrade();	/* grade 3 -> grade 2 (closer to 1) */
	void	decrementGrade();	/* grade 3 -> grade 4 (closer to 150) */

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

private:
	static const int	HIGHEST_GRADE = 1;
	static const int	LOWEST_GRADE = 150;

	const std::string	_name;
	int					_grade;

	static int	checkedGrade(int grade);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
