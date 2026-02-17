#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & other)
	: AForm(other), _target(other._target)
{
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & other)
{
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::executeAction() const
{
	std::string filename = _target + "_shrubbery";
	std::ofstream ofs(filename.c_str());
	if (!ofs.is_open())
		throw std::runtime_error("Could not open file: " + filename);

	ofs << "        *        " << std::endl;
	ofs << "       ***       " << std::endl;
	ofs << "      *****      " << std::endl;
	ofs << "     *******     " << std::endl;
	ofs << "    *********    " << std::endl;
	ofs << "   ***********   " << std::endl;
	ofs << "        |        " << std::endl;
	ofs << "        |        " << std::endl;
	ofs << "        *        " << std::endl;
	ofs << "       ***       " << std::endl;
	ofs << "      *****      " << std::endl;
	ofs << "     *******     " << std::endl;
	ofs << "    *********    " << std::endl;
	ofs << "   ***********   " << std::endl;
	ofs << "        |        " << std::endl;
	ofs << "        |        " << std::endl;
	ofs.close();
	std::cout << "Shrubbery created at " << filename << std::endl;
}
