#include <iostream>
#include <stdlib.h>
#include "SortedArrayList.h"

using namespace std;

class loan_application {

	public:
		loan_application();		
		loan_application(string applicant_full_name, int years_of_relevant_education,
	                         int years_of_relevant_experience, int loan_amount,
				 double priority);
		string getName();
		int getYearsEducation();
		int getYearsExperience();		
		int getLoanAmount();
		double getPriority();
		
		bool operator< (const loan_application& rhs) const;

		bool operator== (const loan_application& rhs) const;

		bool operator> (const loan_application& rhs) const;

		bool operator>= (const loan_application& rhs) const;

		bool operator<= (const loan_application& rhs) const;

		bool operator!= (const loan_application& rhs) const;

		friend ostream &operator<<( ostream &output, const loan_application &application );
		
	private:
		string full_name;
		int years_of_education;
		int years_of_exprience;
		int loanAmount;
		double priority_;							
};
