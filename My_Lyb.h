#pragma once

#include "Read_Txt.h"
#include "Timer.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <chrono>
#include <random>
#include <iomanip>
#include <fstream>
#include <string>



using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::mt19937;
using std::setw;

using hrClock = std::chrono::high_resolution_clock;
typedef std::uniform_int_distribution<int> int_distribution;

int minimum(int a, int b);

class Student {
	string Name, Surname;
	vector <int> HW;
	int Exam;
	float Rez;
public:
	
	static char InputMethod , OutputMethod;
	
	//Konstruktoriai,destruktoriai
	Student();
	Student(string N, string S , vector <int> H ,int E); 
	Student(const Student &A);
	Student& operator = (const Student& A);
	~Student();
	
	//Getteris
	string GetName() const { return Name; };
	float GetRez() const { return Rez; };

	//Rezultato skaicevimo funkcijos
	float Vid();
	float Med();
	void Rezult(char pas);

	//Txt file skaitykle
	void ReadFromFile(std::istream& in, std::vector<Student>& Grupe);
	
	//Setteriai
	inline void SetName(string N) { Name = N; };
	inline void SetSurname(string S) { Surname = S; };
	inline void SetHW(vector <int> Vec) { HW = Vec; };
	inline void SetExam(int n) { Exam = n; };

	//Operatoriu '<<' ir '>>' perkrovimas
	friend std::ostream& operator<<(std::ostream& out, const Student& A);
	friend std::istream& operator>>(std::istream& in ,Student& a);
	
	
};