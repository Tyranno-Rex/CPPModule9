#include "Form.hpp"


Form::Form(void): _name("default_name"), _sign_lvl(150), _exec_lvl(150), _sign(false){
    // std::cout << this->_name << " is created\n" << "access level is " << this->_sign_lvl;
    // if (this->_sign == false)
    //     std::cout << "it is not signed\n";
    // else 
    //     std::cout << "it is signed\n";
}

Form::Form(const Form &src): _name(src.getFormName()), _sign_lvl(src.getSignLevel()), _exec_lvl(src.getExecLevel()), _sign(false){
    // std::cout << this->_name << " is created\n" << "access level is " << this->_sign_lvl;
    // if (this->_sign == false)
    //     std::cout << "it is not signed\n";
    // else 
    //     std::cout << "it is signed\n";
}

Form::Form(std::string name): _name(name), _sign_lvl(150), _exec_lvl(150), _sign(false){
    // std::cout << this->_name << " is created\n" << "access level is " << this->_sign_lvl;
    // if (this->_sign == false)
    //     std::cout << "it is not signed\n";
    // else 
    //     std::cout << "it is signed\n";
}

Form::Form(std::string name, int access_lvl, int exec_lvl): _name(name), _sign_lvl(access_lvl), _exec_lvl(exec_lvl), _sign(false){
    // std::cout << this->_name << " is created\n" << "access level is " << this->_sign_lvl;
    // if (this->_sign == false)
    //     std::cout << "it is not signed\n";
    // else 
    //     std::cout << "it is signed\n";
}


Form::~Form(void){
    // std::cout << "Form is deleted\n";
}

std::string Form::getFormName(void) const{
    return (this->_name);
}

int Form::getSignLevel(void) const {
    return (this->_sign_lvl);
}

int Form::getExecLevel(void) const {
    return (this->_exec_lvl);
}

bool Form::getFormSign(void) const{
    return (this->_sign);
}

void Form::beSigned(Bureaucrat agent){
    std::cout << "!CHECK!\n[";
    try
    {
        if (this->_sign_lvl >= agent.getGrade()){
            std::cout << "you can access this "<< this->getFormName() << " Form]\n";
            this->_sign = true;
        }
        else{
            std::cout << "you can't access this "<< this->getFormName() << " Form]\n";
            throw Form::GradeTooLowException();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

std::ostream &operator<<(std::ostream &oper, Form *form)
{
    oper 
    << "Form Name:          " << form->getFormName() << "\n"
    << "Form Sign Level:    " << form->getSignLevel() << "\n"
    << "Form Exec Level:    " << form->getExecLevel() << "\n";
	return (oper);
}

const char* Form::GradeTooHighException::what() const throw(){
    return "Grade is too High";
}

const char* Form::GradeTooLowException::what() const throw(){
    return "Grade is too Low";
}