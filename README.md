# Tyrimai

## Pirmas tyrimas (Failų kūrimas ir jų uždarymas)
* Kiekvienas studentas turi po 10 namų darbų rezultatų + egzaminas
* Laiko matavimui naudoajam `chrono` biblioteka
* Matavimai atliekami penkis kartus ir iš jų išgaunami vidurkiai
* Kodas buvo sukompiliuotas naudojant -O3 gaire

| Studentu sk. | Laikas 1   | Laikas 2 | Laikas 3  | Laikas 4   | Laikas 5   | Vidurkiai  |
|--------------|------------|----------|-----------|------------|------------|------------|
| 1,000        | 866 μs     | 966 μs   | 877 μs    | 792 μs     | 936 μs     | 887 μs     |
| 10,000       | 6486 μs    | 6903 μs  | 6497 μs   | 6364 μs    | 6307 μs    | 6511 μs    |
| 100,000      | 68 ms      | 66 ms    | 65 ms     | 66 ms      | 67 ms      | 66 ms      |
| 1,000,000    | 594 ms     | 592 ms   | 587 ms    | 595 ms     | 608 ms     | 595 ms     |
| 10,000,000   | 5917 ms    | 5827 ms  | 5871 ms   | 5843 ms    | 5887 ms    | 5869 ms    |

>Failo kūrimo pavizdys: </br> 
![img.png](img.png)

## Antrasis tyrimas (Duomenų apdorojimas)
* Laiko matavimui naudoajam `chrono` biblioteka
* Duomenys gaunaumi iš ankščiau sugeneruotų failų
* Kiekvienas studentas turi po 10 namų darbų rezultatų + egzaminas
* Matavimai atliekami penkis kartus ir iš jų išgaunami vidurkiai
* Matuojami vykdomi su penkiais skirtingais matavimo dydžiais
* Kodas buvo sukompiliuotas naudojant -O3 gaire
* Matuojami:
  * nuskaitymas iš failo
  * studentų rūšiavimą į dvi grupes/kategorijas
  * surūšiuotų studentų išvedimą į du naujus failus
  * visos programos veikimo laikas

### 1,000 studentų

| Matavimas      | Laikas 1 | Laikas 2   | Laikas 3  | Laikas 4  | Laikas 5 | Vidurkiai  |
|----------------|----------|------------|-----------|-----------|----------|------------|
| Nuskaitymas    | 545 μs   | 639 μs     | 518 μs    | 509 μs    | 485 μs   | 539 μs     |
| Rūšiavimas     | 101 μs   | 134 μs     | 100 μs    | 101 μs    | 101 μs   | 107 μs     |
| Išvedimas      | 340 μs   | 435 μs     | 394 μs    | 362 μs    | 369 μs   | 380 μs     |
| Veikimo laikas | 1092 μs  | 1334 μs    | 1113 μs   | 1076 μs   | 1056 μs  | 1134 μs    |

### 10,000 studentų

| Matavimas      | Laikas 1  | Laikas 2    | Laikas 3   | Laikas 4  | Laikas 5  | Vidurkiai |
|----------------|-----------|-------------|------------|-----------|-----------|-----------|
| Nuskaitymas    | 5524 μs   | 5118 μs     | 5430 μs    | 5809 μs   | 5024 μs   | 5381 μs   |
| Rūšiavimas     | 1043 μs   | 1129 μs     | 1133 μs    | 1107 μs   | 1106 μs   | 1104 μs   |
| Išvedimas      | 2795 μs   | 2835 μs     | 2870 μs    | 2859 μs   | 2770 μs   | 2826 μs   |
| Veikimo laikas | 10321 μs  | 10053 μs    | 10386 μs   | 10760 μs  | 9873 μs   | 10279 μs  |

### 100,000 studentų

| Matavimas      | Laikas 1 | Laikas 2  | Laikas 3  | Laikas 4 | Laikas 5 | Vidurkiai |
|----------------|----------|-----------|-----------|----------|----------|-----------|
| Nuskaitymas    | 47 ms    | 48 ms     | 46 ms     | 49 ms    | 47 ms    | 47 ms     |
| Rūšiavimas     | 7 ms     | 7 ms      | 6 ms      | 6 ms     | 6 ms     | 6 ms      |
| Išvedimas      | 27 ms    | 27 ms     | 25 ms     | 32 ms    | 33 ms    | 29 ms     |
| Veikimo laikas | 90 ms    | 92 ms     | 88 ms     | 98 ms    | 97 ms    | 93 ms     |

### 1,000,000 studentų

| Matavimas      | Laikas 1 | Laikas 2 | Laikas 3  | Laikas 4 | Laikas 5 | Vidurkiai |
|----------------|----------|----------|-----------|----------|----------|-----------|
| Nuskaitymas    | 440 ms   | 443 ms   | 443 ms    | 444 ms   | 444 ms   | 443 ms    |
| Rūšiavimas     | 51 ms    | 51 ms    | 53 ms     | 50 ms    | 52 ms    | 51 ms     |
| Išvedimas      | 270 ms   | 273 ms   | 275 ms    | 267 ms   | 268 ms   | 270 ms    |
| Veikimo laikas | 848 ms   | 855 ms   | 859 ms    | 849 ms   | 853 ms   | 853 ms    |

### 10,000,000 studentų

| Matavimas      | Laikas 1  | Laikas 2   | Laikas 3   | Laikas 4  | Laikas 5   | Vidurkiai |
|----------------|-----------|------------|------------|-----------|------------|-----------|
| Nuskaitymas    | 4476 ms   | 4483 ms    | 4502 ms    | 4465 ms   | 4491 ms    | 4483 ms   |
| Rūšiavimas     | 668 ms    | 677 ms     | 685 ms     | 670 ms    | 679 ms     | 676 ms    |
| Išvedimas      | 2602 ms   | 2628 ms    | 2586 ms    | 2640 ms   | 2665 ms    | 2624 ms   |
| Veikimo laikas | 8686 ms   | 8750 ms    | 8730 ms    | 8727 ms   | 8781 ms    | 8735 ms   |