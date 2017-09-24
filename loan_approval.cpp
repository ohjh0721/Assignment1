#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "loan_application.h"

const int max_num_applications = 5000; 

void save_application(loan_application applicant, SortedArrayList <loan_application>* array);


void make_decisions(loan_application applicant, string decision_date, int budget,
		    SortedArrayList <loan_application>* array1,
		    SortedArrayList <loan_application>* array2,
                    SortedArrayList <loan_application>* array3);

void print_active_applications(loan_application applicant);

void print_approved_applications(loan_application applicant, string decision_date);

void print_denied_applications(loan_application applicant, string decision_date);

int main(int argc, char** argv)
{	
	ifstream inf;
	inf.open(argv[1]);
	
	SortedArrayList <loan_application> active_applications(max_num_applications);
	SortedArrayList <loan_application> approved_applications(max_num_applications);
	SortedArrayList <loan_application> denied_applications(max_num_applications);
 
	inf.close();
	return 0;
}
	
void save_application(loan_application applicant, SortedArrayList <loan_application>* array)
{		
	array->add(applicant);
}

void make_decisions(loan_application applicant, string decision_date, int budget,
		    SortedArrayList <loan_application>* array1,
		    SortedArrayList <loan_application>* array2,
                    SortedArrayList <loan_application>* array3)
{
	if( (applicant.getYearsEducation()+applicant.getYearsExperience()) < 10) {
		array1->removeFirst(applicant);		
		array2->add(applicant);
	}


	else {
		array1->removeFirst(applicant);
		int priority = 0;
		for(int i=0; i < sizeof(applicant.getProfits())/sizeof(int); i++) {
			priority = (1/(i+1)) * applicant.getProfits()[i];
		}		
		array3->add(applicant);
	}
		                    
}  

void print_active_applications(loan_application applicant) 
{
	cout << "(" << applicant.getName() << ",";
        cout << applicant.getLoanAmount() << ")\t";
}           
		
void print_approved_applications(loan_application applicant, string decision_date) 
{
	cout << "(" << applicant.getName() << ",";
        cout << applicant.getLoanAmount() <<  ",";
	cout << decision_date << ")\t";
}

void print_denied_applications(loan_application applicant, string decision_date) 
{
	cout << "(" << applicant.getName() << ",";
        cout << applicant.getLoanAmount() <<  ",";
	cout << decision_date << ")\t";
}               
