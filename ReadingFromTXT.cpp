#include "Read_Txt.h"
#include "My_Lyb.h"


void Student::ReadFromFile(std::istream& in, std::vector<Student>& Grupe) {
	
	std::string header1, header2;
	std::getline(in, header1);
	std::getline(in, header2);

	std::string line;
	while (std::getline(in, line)) {
		std::istringstream iss(line);

		
		if (!(iss >> Name >> Surname)) break;  
		
		HW.clear(); 
		
		for (int i = 0; i < 5; ++i) {
			int grade;
			
			if (!(iss >> grade)) break;
			HW.push_back(grade);
		}

		
		if (!(iss >> Exam)) break; 
		

		
		Grupe.emplace_back(Name, Surname, HW, Exam);
	}
}