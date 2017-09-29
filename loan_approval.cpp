#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include "loan_application.h"

const int max_num_applications = 5000; 

void save_application(loan_application application, SortedArrayList <loan_application>* active);

void make_decisions(string date, int budget, SortedArrayList <loan_application>* active,
		    SortedArrayList <loan_application>* denied, 
		    SortedArrayList <loan_application>* approved,
		    ArrayList <string>* denied_date, 
		    ArrayList <string>* approved_date);

void print_active_applications(SortedArrayList <loan_application>* active);

void print_approved_applications(SortedArrayList <loan_application>* approved, 
				 ArrayList <string>* approved_date); 

void print_denied_applications(SortedArrayList <loan_application>* denied,
			       ArrayList <string>* denied_date);

int main(int argc, char** argv)
{	
	string command;
	string full_name;
	int years_education; 
	int years_experience;
	int loan_amount;
	int yearly_profits;
	string date;
	int budget;
	SortedArrayList <loan_application> active_applications(max_num_applications);
	SortedArrayList <loan_application> approved_applications(max_num_applications);
	SortedArrayList <loan_application> denied_applications(max_num_applications);
	ArrayList <string> denied_date(max_num_applications);
	ArrayList <string> approved_date(max_num_applications);
	
	ifstream inf;
	inf.open(argv[1]);

	if(inf.is_open()) {
		string line;	
		string temp;	
		while (getline(inf, line)) {	
			int i = 0;
			double priority = 0;
			istringstream element(line);
			string entry;
			element >> command;

			if(command == "save_application") {
				getline(getline(element, temp, '"'), full_name, '"');
				element >> entry;
				years_education = atoi(entry.c_str());	
				element >> entry;
				years_experience = atoi(entry.c_str());
				element >> entry;
				loan_amount = atoi(entry.c_str());
				while(element >> entry) {
					yearly_profits = atoi(entry.c_str()); 
					priority += 1/(double(i)+1) * double(yearly_profits);
					i++;
				}
				loan_application application(full_name, years_education, 
					                     years_experience, loan_amount, 
							     priority);                      
				save_application(application, &active_applications);
			}

			else if(command == "make_decisions") {
				getline(getline(element, temp, '"'), date, '"');
				element >> entry;
				budget = atoi(entry.c_str());
				make_decisions(date, budget, &active_applications,
					       &denied_applications, &approved_applications,
					       &denied_date, &approved_date);	
			}

			else if(command == "print") {
				print_active_applications(&active_applications);
				cout << endl;	
				print_approved_applications(&approved_applications, 
							    &approved_date);
				cout << endl;
				print_denied_applications(&denied_applications, 
							  &denied_date);
				cout << endl;
			}		
		}
	}
	
	inf.close();
	return 0;
}
	
void save_application(loan_application application, SortedArrayList <loan_application>* active)
{		
	(*active).add(application);
}

void make_decisions(string date, int budget, SortedArrayList <loan_application>* active, 
		    SortedArrayList <loan_application>* denied,
                    SortedArrayList <loan_application>* approved,
		    ArrayList <string>* denied_date,
		    ArrayList <string>* approved_date)
{		
	for(int i=0; i < (*active).count(); i++) {
		loan_application my_app = (*active)[i];
		if( my_app.getYearsEducation() + my_app.getYearsExperience() < 10) { 		
			(*denied_date).add(date);                        
			(*denied).add(my_app);			
			(*active).removeFirst(my_app);	
			i--;	
		}

		else if ( my_app.getLoanAmount() <= budget) {
			(*approved_date).add(date); 			
			(*approved).add(my_app);			
			(*active).removeFirst(my_app);		
			budget = budget - my_app.getLoanAmount();
			i--;	
		}
	}	                    
}  

void print_active_applications(SortedArrayList <loan_application>* active) 
{	
	cout << "active_applications\t";	
	for(int i=0; i < (*active).count(); i++) {	
		loan_application my_app = (*active)[i];
		cout << "(\"" << my_app.getName() << "\",";
		cout << my_app.getLoanAmount() << ")\t";
	}
}           
		
void print_approved_applications(SortedArrayList <loan_application>* approved, 
				 ArrayList <string>* approved_date)

{
	cout << "approved_applications\t";	
	for(int i=0; i < (*approved).count(); i++) {	
		loan_application my_app = (*approved)[i];
		cout << "(\"" << my_app.getName() << "\",";
		cout << my_app.getLoanAmount() <<  ",\"";
		cout << (*approved_date)[i] << "\")\t";
	}
}


void print_denied_applications(SortedArrayList <loan_application>* denied, 
			       ArrayList <string>* denied_date)

{	
	cout << "denied_applications\t";	
	for(int i=0; i < (*denied).count(); i++) {	
		loan_application my_app = (*denied)[i];
		cout << "(\"" << my_app.getName() << "\",";
		cout << my_app.getLoanAmount() <<  ",\"";
		cout << (*denied_date)[i] << "\")\t";
	}
}
