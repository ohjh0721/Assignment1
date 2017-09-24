#include <iostream>
#include <stdlib.h>
#include "SortedArrayList.h"

using namespace std;

class loan_application {

	public:
		loan_application();		
		loan_application(string applicant_full_name, int years_of_relevant_education,
	                         int years_of_relevant_experience, int loan_amount,
				 int* estimated_yearly_profits);
		string getName();
		int getYearsEducation();
		int getYearsExperience();		
		int getLoanAmount();
		int* getProfits();

		bool operator< (const loan_application& rhs) const;

		bool operator== (const loan_application& rhs) const;

		bool operator> (const loan_application& rhs) const;

		bool operator>= (const loan_application& rhs) const;

		bool operator<= (const loan_application& rhs) const;

		bool operator!= (const loan_application& rhs) const;

		int& operator[] (unsigned i);	

		friend ostream &operator<<( ostream &output, const loan_application &p );

	private:
		string full_name;
		int years_of_education;
		int years_of_exprience;
		int loanAmount;
		int* profits;
		int* list_integer_array;
		int n;
		int a[5000];							
};
