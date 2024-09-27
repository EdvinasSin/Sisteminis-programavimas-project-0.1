# SPPSD 1.0 1/5/2023

## Sisteminis-programavimas-pirmas-savarankiškas-darbas

Ši programa ,skirta apskaičiuoti studentu finalinius rezultatus atsižvelgiant į jumis patektus duomenys. Duomenys gali būti pateikti kaip rankiniu įvedimu , sugeneruoti ar pateikti testiniame faile. Po skaičiavimų rezultatai bus tvarkingai išvedami ekrane ar tekstiniame faile priklausomai nuo pasirinkto įvedimo būdo

## Releases

### [v0.1](https://github.com/KarIMarks/Sisteminis-programavimas-project-0.1/releases/tag/0.1)

-**Pridėta** Parašytas kodo pagrindas sudarytas iš main.cpp ,my_lyb.cpp ir my_lyb.h .
-**Pridėta** Rankinio įvedimo galimybė
-**Pridėta** Atsitiktinis studentų generavimas
-**Pridėta** Galimybė įvesti studentus iš tekstinio failo.
-**Pridėta** Rezultato išvedimas į ekraną
-**Pridėta** Rezultato išvedimo tvarkymas
-**Pridėta** Klaidų išvedimas naudojant try/catch metodus

### [v0.2](https://github.com/KarIMarks/Sisteminis-programavimas-project-0.1/releases/tag/0.2)

-**Pridėta** Studentų rūšiavimas pagal jų rezultatus
-**Pridėta** Rezultato išvedimas į skirtingus failus priklausomai nuo rezultatų
-**Pridėta** Pridėta programos darbo spartos matavimo funkcija
-**Pridėta** Rezultato išvedimas į ekraną
-**Pridėta** Rezultato išvedimo tvarkymas

### [v1.0](https://github.com/KarIMarks/Sisteminis-programavimas-project-0.1/releases/tag/0.2)

-**Pakeista** Studentų rūšiavimo realizacija
-**Pakeista** y mažų pakeitimų skirtų optimizacijai ar patogumui

## Komentarai apie Gautus Rezultatus

-Atlikus spartos matavimus su skirtingais konteineriais darau išvada jog mano programos realizacijoje vektorius greičiausiai įveda ir išveda duomenys į failą ,tačiau lėčiau rūšiuoja studentus.
-Atlikus atminties vartojimą priklausomai nuo strategijos ir konteinerio darau išvada ,kad pirma strategija vartoja vos ne 1,5 karto daugiau atminties.Efektyviausiu konteineriu buvo deque.
-Rūšiavimo strategija beveik ne kaip neįtakoja darbo spartai nevieno iš vektorių
-Visų atliktų matavimų rezultatai palikti žemiau faile ,bei programoje palikta galimybė spartai matuoti

## Naudojimosi Instrukcija

1. **Rankinis Įvedimas:**
- Pasirinkite '1' paleidus programą.
- Įveskite norimą studentų kiekį.
- Pasirinkite rezultatų skaičiavimo metodą ( v-vidurkiui arba m-medianai).
- Įveskite vardą.
- Įveskite pavardę.
- Įveskite namų darų kiekį (kiekvienam studentui individualiai).
- Įveskite pažymį (nuo 0 iki 10).
- Įveskite egzamino rezultatą (nuo 0 iki 10).

2. **Atsitiktinis Generavimas:**
- Pasirinkite '2' paleidus programą.
- Įveskite norimą studentų kiekį.
- Pasirinkite rezultatų skaičiavimo metodą ( v-vidurkiui arba m-medianai).

3. **Duomenys iš Tekstinio Failo:**
- Pasirinkite '3' paleidus programą.
- Pasirinkite rezultatų skaičiavimo metodą ( v-vidurkiui arba m-medianai).
- Įveskite tekstinio failo pavadinimą.

4. **Rezultatų Peržiūra:**
- Rezultatai išvesti į konsolę arba į failus, priklausomai nuo pasirinkimo.
- Failai išsaugoti projekto šaknies direktorijoje.

## Spartos ir atminties vartoimo matavimo rezultatai 

### Pirma strategija :

#### Vector : 

#####	10K : 12mb

Duomenu nuskaitymas is failu uztruko : 2.58216s
Studentu rusiavimas i dvi kategorijas uztruko : 0.0477973s
Surusiuotu studentu isvedimas i faila uztruko : 5.35703s

#####	100K: 116mb

Duomenu nuskaitymas is failu uztruko : 0.530151s
Studentu rusiavimas i dvi kategorijas uztruko : 0.0040856s
Surusiuotu studentu isvedimas i faila uztruko : 0.528774s

#####	1M  : 997mb

Duomenu nuskaitymas is failu uztruko : 32.3035s
Studentu rusiavimas i dvi kategorijas uztruko : 0.676686s
Surusiuotu studentu isvedimas i faila uztruko : 10.2742s

#### List : 

#####	10K : 2mb

Duomenu nuskaitymas is failu uztruko : 0.057428s
Studentu rusiavimas i dvi kategorijas uztruko : 0.010345s
Surusiuotu studentu isvedimas i faila uztruko : 0.0541808s

#####	100K: 177mb

Duomenu nuskaitymas is failu uztruko : 0.710323s
Studentu rusiavimas i dvi kategorijas uztruko : 0.248221s
Surusiuotu studentu isvedimas i faila uztruko : 0.533483s

#####	1M  : 820mb

Duomenu nuskaitymas is failu uztruko : 3.16655s
Studentu rusiavimas i dvi kategorijas uztruko : 1.5744s
Surusiuotu studentu isvedimas i faila uztruko : 5.32969s

#### Deque :

#####	10K : 2mb

Duomenu nuskaitymas is failu uztruko : 0.0492789s
Studentu rusiavimas i dvi kategorijas uztruko : 0.0046925s
Surusiuotu studentu isvedimas i faila uztruko : 0.0535696s

#####	100K: 51mb

Duomenu nuskaitymas is failu uztruko : 0.60709s
Studentu rusiavimas i dvi kategorijas uztruko : 0.071943s
Surusiuotu studentu isvedimas i faila uztruko : 0.530946s

#####	1M  : 647mb

Duomenu nuskaitymas is failu uztruko : 2.92572s
Studentu rusiavimas i dvi kategorijas uztruko : 0.551976s
Surusiuotu studentu isvedimas i faila uztruko : 5.32273s

### Antra strategija :

#### Vector : 

#####	10K : 8mb

Duomenu nuskaitymas is failu uztruko : 0.043108s
Studentu rusiavimas i dvi kategorijas uztruko : 0.0002555s
Surusiuotu studentu isvedimas i faila uztruko : 0.0533072s

#####	100K: 107mb

Duomenu nuskaitymas is failu uztruko : 0.529527s
Studentu rusiavimas i dvi kategorijas uztruko : 0.0042108s
Surusiuotu studentu isvedimas i faila uztruko : 0.536107s

#####	1M  : 738mb

Duomenu nuskaitymas is failu uztruko : 2.58841s
Studentu rusiavimas i dvi kategorijas uztruko : 0.0472116s
Surusiuotu studentu isvedimas i faila uztruko : 5.25462s

#### List : 

#####	10K : 11mb

Duomenu nuskaitymas is failu uztruko : 0.0602175s
Studentu rusiavimas i dvi kategorijas uztruko : 0.0043005s
Surusiuotu studentu isvedimas i faila uztruko : 0.0563326s

#####	100K: 126mb

Duomenu nuskaitymas is failu uztruko : 0.709876s
Studentu rusiavimas i dvi kategorijas uztruko : 0.10548s
Surusiuotu studentu isvedimas i faila uztruko : 0.528855s

#####	1M  : 583

Duomenu nuskaitymas is failu uztruko : 3.17363s
Studentu rusiavimas i dvi kategorijas uztruko : 0.68624s
Surusiuotu studentu isvedimas i faila uztruko : 5.30224s

#### Deque :

#####	10K : 5mb

Duomenu nuskaitymas is failu uztruko : 0.0492363s
Studentu rusiavimas i dvi kategorijas uztruko : 0.0018641s
Surusiuotu studentu isvedimas i faila uztruko : 0.0526124s

#####	100K: 54mb

Duomenu nuskaitymas is failu uztruko : 0.603609s
Studentu rusiavimas i dvi kategorijas uztruko : 0.0246295s
Surusiuotu studentu isvedimas i faila uztruko : 0.524417s

#####	1M  : 452mb

Duomenu nuskaitymas is failu uztruko : 2.93464s
Studentu rusiavimas i dvi kategorijas uztruko : 0.216142s
Surusiuotu studentu isvedimas i faila uztruko : 5.25167s