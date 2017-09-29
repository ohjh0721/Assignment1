#include "loan_application.h"

	loan_application::loan_application()
	{
	}

	loan_application::loan_application (string applicant_full_name, 
				            int years_of_relevant_education,
                 			    int years_of_relevant_experience, 
                                            int loan_amount,
	                                    double priority)
	{
		full_name = applicant_full_name;
		years_of_education = years_of_relevant_education;
		years_of_exprience = years_of_relevant_experience;
		loanAmount = loan_amount;
		priority_ = priority;
	}


	string loan_application::getName() 
	{
		return full_name;
	}

	int loan_application::getYearsEducation()
	{
		return years_of_education;
	}

	int loan_application::getYearsExperience()
	{
		return years_of_exprience;
	}
	
	int loan_application::getLoanAmount()
	{
		return loanAmount;
	}

	double loan_application::getPriority()
	{
		return priority_;
	}

	bool loan_application::operator< (const loan_application& rhs) const{
		return (priority_ > rhs.priority_);
	}

	bool loan_application::operator== (const loan_application& rhs) const{
		return (priority_ == rhs.priority_);
	}

	bool loan_application::operator> (const loan_application& rhs) const {
		return !(((*this) < rhs) || ((*this == rhs)));
	}

	bool loan_application::operator>= (const loan_application& rhs) const {
		return !((*this) < rhs);
	}

	bool loan_application::operator<= (const loan_application& rhs) const {
                return !((*this) > rhs);
        }

	bool loan_application::operator!= (const loan_application& rhs) const {
                return !((*this) == rhs);
        }
	
	ostream &operator<<( ostream &output, const loan_application &application ) { 
        	output << application.full_name << "," << application.loanAmount;
        	return output;            
      	}
	
