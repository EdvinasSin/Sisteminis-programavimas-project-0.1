// Porjektas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "My_Lyb.h"

int main()
{
    vector<Student> Grupe;

    char inputMethod;
    cout << "Iveskite 'm' rankiniam ivedimui ir 'r' atsitiktiniam : ";
    cin >> inputMethod;
    

    for (int i = 0; i < 3; i++)
    {
        Student Laikinas(inputMethod);
        string laikS;
        Grupe.push_back(Laikinas);
        Laikinas. ~Student();

    }
    cout << setw(12) << std::left << "Vardas" << setw(12) << std::left << "Pavarde" << setw(65) << std::right << "Galutinis (Vid.)" << endl;
    cout << setw(90) << std::setfill('-') << "-" << std::setfill(' ') << endl;
    for (auto& duom : Grupe) cout<<duom;

    system("pause");

}
