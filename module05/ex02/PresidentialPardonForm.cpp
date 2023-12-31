#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", 25, 5), _name("default_name"){
    // std::cout << this->_name << "\n";
}
PresidentialPardonForm::PresidentialPardonForm(std::string name): AForm("PresidentialPardonForm", 25, 5), _name(name){
    // std::cout << this->_name << "\n";
}
PresidentialPardonForm::~PresidentialPardonForm(void){
    // std::cout << this->_name << " is deleted\n";
}

void PresidentialPardonForm::execute(Bureaucrat const &executer) const{
    if (this->getFormSign() == false){
        std::cout << "this form isn't signed\n";
        std::cout << "go sign first\n";
        return ;
    }

    if (executer.getGrade() < 5){
        std::cout << "you can execute the this form\n";
    }
    else{
        std::cout << "you can't execute the this form\n";
        return ;
    }
    std::cout << this->getNameFile() << " has been pardoned by Zaphod Beeblebrox.\n";
}

std::string PresidentialPardonForm::getNameFile(void) const{
    return (this->_name);
}

std::ostream &operator<<(std::ostream &oper, PresidentialPardonForm *pres){
    oper << "Form " << pres->getNameFile() << "\nSign or Not: " << pres->getFormSign()
    << "\nsign level: " << pres->getSignLevel() << "\nExec level: " << pres->getExecLevel() << "\n";
    return oper;
}