# AlgoritmicaGrafurilor
Proiectul reazila in cadrul materiei AlgoritmicaGrafurilor sustinut de Maniu George Constantin -ULBS


# Proiect Algoritmica Grafurilor

## Descriere generală
Acest proiect implementează o aplicație în C++ pentru analiza unei rețele de transport rutier, folosind algoritmi fundamentali pe grafuri.

## Structura aplicației
- **main.cpp** – conține meniul interactiv și apelează funcțiile din clasa `Graph`.
- **Graph.cpp / Graph.h** – definesc clasa `Graph` și implementează:
  - DFS și verificare de conexitate
  - Algoritmul Dijkstra
  - Arbore de acoperire minimă (Prim)
  - Verificare și construire ciclu Eulerian (Hierholzer)
- **graf.txt** – fișierul de intrare care definește graful.

## Cum se compilează
1. Deschide `Developer Command Prompt for Visual Studio`.
2. Navighează în folderul proiectului:
```
cd "C:\Users\maniu\OneDrive\Desktop\ULBS\Anul 2\Semestrul2\Modul1\AlgoritmicaGrafurilor\Proiect"
```
3. Compilează proiectul:
```
cl src\main.cpp src\Graph.cpp /EHsc /std:c++17
```
4. Rulează aplicația:
```
main.exe
```

## Meniul aplicației
```
===== MENIU ALG. GRAFURI =====
1. Afiseaza lista de adiacenta
2. Verifica daca graful este tare conex
3. Ruleaza algoritmul Dijkstra (de la nodul 0)
4. Ruleaza algoritmul MST (Prim)
5. Verifica si afiseaza ciclu Eulerian
0. Iesire
```

## Fișier de intrare (data/graf.txt)
Fiecare linie conține: nod_start nod_sfârșit cost
Exemplu:
```
0 1 7
0 3 4
1 2 5
```

## Observații
- Este necesar Visual Studio 2022 sau compilator `cl.exe`.
- Este important ca standardul C++17 să fie activat (vezi `/std:c++17`).




📋 Ce este meniul?
Meniul este o secțiune de cod care se repetă și îți permite să alegi ce funcție să rulezi din proiectul tău.
Se află în fișierul main.cpp și arată așa:

cpp
Copy
Edit
===== MENIU ALG. GRAFURI =====
1. Afiseaza lista de adiacenta
2. Verifica daca graful este tare conex
3. Ruleaza algoritmul Dijkstra (de la nodul 0)
4. Ruleaza algoritmul MST (Prim)
5. Verifica si afiseaza ciclu Eulerian
0. Iesire
Alege optiunea:
🔁 Cum funcționează meniul – PAS CU PAS
🔹 PASUL 1: Programul se compilează și pornește
Tu scrii în terminal:

bash
Copy
Edit
cl src\\main.cpp src\\Graph.cpp /EHsc /std:c++17
main.exe
🔄 Acest cod execută funcția main(), unde se află bucla de meniu.

🔹 PASUL 2: Este afișat meniul
Imediat ce programul rulează, cout << afișează textul cu opțiunile din meniu:

cpp
Copy
Edit
cout << "\n===== MENIU ALG. GRAFURI =====\n";
cout << "1. Afiseaza lista de adiacenta\n";
...
cout << "Alege optiunea: ";
🔹 PASUL 3: Programul așteaptă o alegere
Asta se întâmplă la linia:

cpp
Copy
Edit
cin >> opt;
Aici utilizatorul scrie un număr (de la 0 la 5) și apasă Enter.

🔹 PASUL 4: Se execută funcția aleasă
Această parte e realizată cu switch(opt), care verifică valoarea introdusă:

cpp
Copy
Edit
switch (opt) {
    case 1: g.print(); break;
    case 2: g.isSC(); break;
    case 3: g.dijkstra(0); break;
    ...
}
Fiecare case corespunde unei opțiuni din meniu.

🔹 PASUL 5: Meniul se reafișează
Datorită buclei do { ... } while (opt != 0);, după fiecare execuție, meniul reapare automat.

🎯 Exercițiu rapid (exemplu real)
bash
Copy
Edit
===== MENIU ALG. GRAFURI =====
1. Afiseaza lista de adiacenta
2. Verifica daca graful este tare conex
3. Ruleaza algoritmul Dijkstra (de la nodul 0)
4. Ruleaza algoritmul MST (Prim)
5. Verifica si afiseaza ciclu Eulerian
0. Iesire
Alege optiunea: 3
🔽 Programul va executa:

cpp
Copy
Edit
g.dijkstra(0);
Apoi va afișa din nou meniul.

Proiect realizat de Gabriela Florescu, ULBS 2025
