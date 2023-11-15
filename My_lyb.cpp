#include "My_Lyb.h"

int minimum(int a, int b) { return a < b ? a : b;}

// Studento klasės konstruktorius, leidžiantis pasirinkti duomenų įvedimo būdą

Student::Student(char inputMethod) {
	

	mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
	int_distribution dist(0, 9);

	if (inputMethod == 'r') {
		string vardai[10] = { "Nojus", "Linas", "Matas", "Lukas", "Jonas", "Erika", "Laura", "Greta", "Diana", "Inesa" };
		string pavardes_m[10] = { "Kazlauskaite", "Jankauskaite", "Stankeviciute", "Petrauskaite", "Vasiliauskaite", "Butkute", "Pociute", "Lukoseviciute", "Balciunaite", "Kavaliauskaite" };
		string pavardes_v[10] = { "Kazlauskas", "Jankauskas", "Stankevicius", "Petrauskas", "Vasiliauskas", "Butkus", "Pocius", "Lukosevicius", "Balciunas", "Kavaliauskas" };

		Name = vardai[dist(mt)];
		switch (*Name.rbegin()) {
		case 's':
			Surname = pavardes_v[dist(mt)];
			break;
		default:
			Surname = pavardes_m[dist(mt)];
			break;
		};
		for (int i = 0; i < 5; i++) {
			HW.push_back(dist(mt) + 1);
		}
		Exam = dist(mt) + 1;
		Rezult('v');
	}
	else if (inputMethod == 'm') {
		cin >> *this;  
	}

	

}
	// Studento klasės konstruktorius su rankiniu duomenų įvedimu
	Student::Student(string N, string S, vector<int> H, int E) {
		Name = N;
		Surname = S;
		HW = H;
		Exam = E;
		Rezult('v');
	}

  // Kopijavimo konstruktorius
  Student::Student(const Student& A) {
		Name = A.Name;
		Surname = A.Surname;
		HW = A.HW;
		Exam = A.Exam;
		Rez = A.Rez;
	}
    // Kopijavimo operatorius
	Student& Student::operator = (const Student& A) {
		if (this == &A) return *this;
		Name = A.Name;
		Surname = A.Surname;
		HW = A.HW;
		Exam = A.Exam;
		Rez = A.Rez;
		return *this;
	}
	// Dekonstruktorius
	Student::~Student() {
		Name.clear();
		Surname.clear();
		HW.clear();
		Exam = 0;
		Rez = 0;
	}

	// Vidurkio skaičiavimo funkcija
	float Student::Vid() {
		return std::accumulate(HW.begin(), HW.end(), 0.0) / HW.size() * 1.0;
	}

	// Medianos skaičiavimo funkcija
	float Student::Med() {
		std::sort(HW.begin(), HW.end());
		int n = HW.size() / 2;
		return
			(n % 2 == 1) ? HW[n] / 1.0 : (HW[n] + HW[n + 1]) / 2.0;
	}

	// Rezultato skaičiavimo funkcija
	void Student::Rezult(char pas) {
		(pas == 'v') ? Rez = 0.4 * Vid() + 0.6 * Exam : Rez = 0.4 * Med() + 0.6 * Exam;
	}

	// << operatoriaus perkrovimo funkcija, skirta išvesti Studento objektą į srautą
	std::ostream& operator<<(std::ostream& out, const Student& A) {
		cout << std::setw(16) << std::left << A.Name << std::setw(16) << std::left << A.Surname << " | ";

		for (auto& i : A.HW) {
			cout << std::setw(3) << i << " | ";
		}

		cout << setw(5) << A.Exam << " | ";
		cout << std::fixed << std::setprecision(2) << "Rezultatas = " << A.Rez << endl;

		return out;
	}

	// >> operatoriaus perkrovimo funkcija, skirta įvesti duomenis į Studento objektą iš srauto
	std::istream& operator>>(std::istream& in, Student& a) {
		int n;
		cout << "Iveskite Varda: ";
		in >> a.Name;
		cout << "Iveskite Pavarde: ";
		in >> a.Surname;
		cout << "Iveskite namu darbu kieki: ";
		in >> n;
		for (int i = 0; i < n; i++) {
			cout << "Koks pazymis buvo uz " << i+1 << " namu darba: ";
			int k;
			in >> k; a.HW.push_back(k);
		}
		cout << "Koks buvo egzamino rezultatas: ";
		in >> a.Exam;
		a.Rezult('v');
		return in;
	}