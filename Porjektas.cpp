#include "My_Lyb.h"
#include "Read_Txt.h"

int main()
{
    int choose, stkiek;
    char inputMethod, outputMethod;
    cout << "Rankiniam ivedimui arba generavimui spauskite '1' ,duomenyms gauti is tekstinio failo spauskite '2' : ";
    cin >> choose;
    vector<Student> Grupe;

    cout << "Iveskite 'v' rezultatu vidurkiui apskaicioti ir 'm' medianai : ";
    cin >> outputMethod;
    Student::OutputMethod = outputMethod;

   
    try {
        switch (choose)
        {
            //Rankinis arba atsitiktinis duomenu ivedimas
        case 1: {

            cout << "Kiek norite sugeneruoti studentu ? ";
            cin >> stkiek;

            cout << "Iveskite 'm' rankiniam ivedimui ir 'r' atsitiktiniam : ";
            cin >> inputMethod;
            Student::InputMethod = inputMethod;

            for (int i = 0; i < stkiek; i++)
            {
                Student Laikinas;
                Grupe.push_back(Laikinas);
            }
            break;
        }
             //Duomenu ivedimas is textinio failo
        case 2: {

            cout << "Iveskite failo pavadinima: ";
            string FileName;
            cin >> FileName;
          
            std::ifstream inputFile(FileName);

           // cout << "Failo atverymas uztruko : " << t.elapsed() << "s\n";
           
           //Tikrinama ar failas atidarytas sekmingai
            if (!inputFile.is_open()) {
                throw std::ios_base::failure("Nepavyko atidaryti failo");
            }

            //Duomenu nuskaitymas
            Timer t;
            Student Laikinas;
            Laikinas.ReadFromFile(inputFile, Grupe);
            inputFile.close();
            cout << "Duomenu nuskaitymas is failu uztruko : " << t.elapsed() << "s\n";
            break;
        }
        default: {
            cout << "Ivestas netinkamas kintamasis!!!";
            return 1;
        }
        }
        //Studentu rusiavimas pagal rezultata
        sort(Grupe.begin(), Grupe.end(), [](const Student& a, const Student& b) {
            return a.GetRez() > b.GetRez();
            });
         
        

        vector<Student> geri;
        vector<Student> blogi;
        
        Timer t;
        
        
        auto partition_iter = std::partition(Grupe.begin(), Grupe.end(), [](const Student& a) {
            return a.GetRez() > 5.0;
            });

       
        blogi.insert(blogi.end(), partition_iter, Grupe.end());
        geri.insert(geri.end(), Grupe.begin(), partition_iter);

        
        Grupe.clear();

         cout << "Studentu rusiavimas i dvi kategorijas uztruko : " << t.elapsed() << "s\n";       

        t.reset();

        //Rezultatu spausdinimas i du skirtingus failus
        std::ofstream out_f("Blogi_rez.txt");
        for (const auto& duom : blogi) {
            out_f << duom << endl;  
        }
        out_f.close();

        std::ofstream out_f2("Geri_rez.txt");
        for (const auto& duom : geri) {
            out_f2 << duom << endl;  
        }
        out_f2.close();
        
        cout << "Surusiuotu studentu isvedimas i faila uztruko : " << t.elapsed() << "s\n";

        return 0;
    }

        //Klaidu perdengimo metodai
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

//Spausdinamas rezultato antraste
//if (outputMethod == 'v') cout << setw(16) << std::left << "Vardas" << setw(12) << std::left << "Pavarde" << setw(20) << std::right << "Galutinis (Vid.)" << endl;
// else cout << setw(16) << std::left << "Vardas" << setw(12) << std::left << "Pavarde" << setw(20) << std::right << "Galutinis (Med.)" << endl;
 //cout << setw(48) << std::setfill('-') << "-" << std::setfill(' ') << endl;

 