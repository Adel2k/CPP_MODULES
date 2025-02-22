# include "AMateria.hpp"
# include "ICharacter.hpp"

using std::cout;
using std::endl;

//Orthodox
AMateria::AMateria() {
	cout << "\033[1;32mAMateria default constructor called.\033[0m" << endl;
}

AMateria::AMateria(const AMateria& other) {
	std::cout << "\033[1;34mAMateria copy constructor called.\033[0m" << std::endl;
	*this = other;
}

AMateria& AMateria::operator=(const AMateria& other) {
	std::cout << "\033[1;34mAMateria copy assignment called.\033[0m" << std::endl;
	this->type = other.type;
	return *this;
}

AMateria::~AMateria() {
	cout << "\033[1;31mAMateria destructor called.\033[0m" << endl;
}
//

AMateria::AMateria(std::string const& type) {
	cout << "\033[1;32mAMateria constructor with parametrs called.\033[0m" << endl;
	this->type = type;
}

void	AMateria::use(ICharacter& target) {
	cout << "\033[1;35mAMateria use called for " << target.getName() <<".\033[0m" << endl;
}

std::string const & AMateria::getType() const {
	return (type);
}


