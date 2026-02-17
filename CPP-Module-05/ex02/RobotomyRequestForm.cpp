#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & other)
	: AForm(other), _target(other._target)
{
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & other)
{
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "Drrrrrrr... BZZZZZ... *drilling noises*" << std::endl;
	std::srand(std::time(NULL));
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << _target << " robotomy failed!" << std::endl;
}
