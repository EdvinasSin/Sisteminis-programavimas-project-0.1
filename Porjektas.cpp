#include "My_Lyb.h"
#include "Read_Txt.h"

int main()
{
    int choose, stkiek;
    char inputMethod, outputMethod;
    cout << " Rankiniam ivedimui  '1'\n ";
    cout << "Atsitiktinis generavimas '2'\n ";
    cout << "Ivedimas is tekstinio failo '3'\n ";
    cin >> choose;
    vector<Student> Grupe;

    cout << "Iveskite 'v' rezultatu vidurkiui apskaicioti ir 'm' medianai : ";
    cin >> outputMethod;
    Student::OutputMethod = outputMethod;

    bool performPartitioning = false; 

    try {
        switch (choose)
        {
            // Rankinis ivedimas
        case 1: {
            cout << "Kiek norite sugeneruoti studentu ? ";
            cin >> stkiek;
            Student::InputMethod = 'm';

            Student::OutputMethod = outputMethod;

            for (int i = 0; i < stkiek; i++)
            {
                Student Laikinas;
                Grupe.push_back(Laikinas);
            }
            break;
        }

              // Atsitiktinis generavimas
        case 2: {
            cout << "Kiek norite sugeneruoti studentu ? ";
            cin >> stkiek;

            Student::OutputMethod = outputMethod;

            Student::InputMethod = 'r';

            for (int i = 0; i < stkiek; i++)
            {
                Student Laikinas;
                Grupe.push_back(Laikinas);
            }
            
            break;
        }

              // Duomenys is tekstinio failo
        case 3: {
            cout << "Iveskite failo pavadinima: ";
            string FileName;
            cin >> FileName;

            std::ifstream inputFile(FileName);

            if (!inputFile.is_open()) {
                throw std::ios_base::failure("Nepavyko atidaryti failo");
            }

            Timer t;
            Student Laikinas;
            Laikinas.ReadFromFile(inputFile, Grupe);
            inputFile.close();
            cout << "Duomenu nuskaitymas is failu uztruko : " << t.elapsed() << "s\n";

            performPartitioning = true; 
            break;
        }

        default: {
            cout << "Ivestas netinkamas kintamasis!!!";
            return 1;
        }
        }

        // Studentu rusiavimas pagal rezultata
        sort(Grupe.begin(), Grupe.end(), [](const Student& a, const Student& b) {
            return a.GetRez() > b.GetRez();
            });

        vector<Student> blogi;

        Timer t;
        if (performPartitioning) {
            auto partition_iter = std::partition(Grupe.begin(), Grupe.end(), [](const Student& a) {
                return a.GetRez() > 5.0;
                });

            blogi.insert(blogi.end(), partition_iter, Grupe.end());

            Grupe.erase(partition_iter, Grupe.end());

            cout << "Studentu rusiavimas i dvi kategorijas uztruko : " << t.elapsed() << "s\n";
        }
       

        t.reset();

        if (choose == 1 || choose == 2) {
            // Spausdinami rezultatai i console
            if (outputMethod == 'v')
                cout << setw(16) << std::left << "Vardas" << setw(16) << std::left << "Pavarde" << setw(20) << std::right << "Galutinis (Vid.)" << endl;
            else
                cout << setw(16) << std::left << "Vardas" << setw(16) << std::left << "Pavarde" << setw(20) << std::right << "Galutinis (Med.)" << endl;
            cout << setw(48) << std::setfill('-') << "-" << std::setfill(' ') << endl;

            for (auto& duom : Grupe)
                cout << duom;
        }
        else if (choose == 3) {
            // Rezultatu spausdinimas i failus
            std::ofstream out_f_blogi("Blogi_rez.txt");
            out_f_blogi << setw(16) << std::left << "Vardas :" << setw(16) << std::left << "Pavarde :" << std::fixed << std::right << "Galutinis (" << (outputMethod == 'v' ? "Vid." : "Med.") << ")\n" << endl;

            for (const auto& duom : blogi) {
                out_f_blogi << duom << endl;
            }
            out_f_blogi.close();

            std::ofstream out_f_geri("Geri_rez.txt");
            out_f_geri << setw(16) << std::left << "Vardas :" << setw(16) << std::left << "Pavarde :" << std::fixed << std::right << "Galutinis (" << (outputMethod == 'v' ? "Vid." : "Med.") << ")\n" << endl;

            for (const auto& duom : Grupe) {
                out_f_geri << duom << endl;
            }
            out_f_geri.close();

            cout << "Surusiuotu studentu isvedimas i faila uztruko : " << t.elapsed() << "s\n";
        }
        system("pause");
        return 0;
    }
    catch (const std::ios_base::failure& ex) {
        cout << ex.what() << endl;
        cout << "Failo atidarymo/skaitymo klaida" << endl;
        return 1;
    }
    catch (const std::exception& ex) {
        cout << ex.what() << endl;
        return 1;
    }
    catch (...) {
        cout << "Neapdorota klaida" << endl;
        return 1;
    }
    
}
