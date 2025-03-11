# Tyrimai

## Pirmas tyrimas (Failų kūrimas ir jų uždarymas)
* Kiekvienas studentas turi po 10 namų darbų rezultatų + egzaminas
* Laiko matavimui naudoajam `chrono` biblioteka
* Matavimai atliekami penkis kartus ir iš jų išgaunami vidurkiai

| Studentu sk. | Laikas 1   | Laikas 2 | Laikas 3  | Laikas 4   | Laikas 5   | Vidurkiai  |
|--------------|------------|----------|-----------|------------|------------|------------|
| 1,000        | 866 μs     | 966 μs   | 877 μs    | 792 μs     | 936 μs     | 887 μs     |
| 10,000       | 6486 μs    | 6903 μs  | 6497 μs   | 6364 μs    | 6307 μs    | 6511 μs    |
| 100,000      | 68 ms      | 66 ms    | 65 ms     | 66 ms      | 67 ms      | 66 ms      |
| 1,000,000    | 594 ms     | 592 ms   | 587 ms    | 595 ms     | 608 ms     | 595 ms     |
| 10,000,000   | 5917 ms    | 5827 ms  | 5871 ms   | 5843 ms    | 5887 ms    | 5869 ms    |


## Antrasis tyrimas (Duomenų apdorojimas)
* Laiko matavimui naudoajam `chrono` biblioteka
* Duomenys sugeneruojami ir gaunami iš kursiokai.txt.
* Kursiokai.txt turi 1,000,000 studentų
* Kiekvienas studentas turi po 10 namų darbų rezultatų + egzaminas
* Matavimai atliekami penkis kartus ir iš jų išgaunami vidurkiai
* Kiekvienas matavimas vyko nuosekliai vienas po kito
* Matuojami:
  * nuskaitymas iš failo
  * studentų rūšiavimą į dvi grupes/kategorijas
  * surūšiuotų studentų išvedimą į du naujus failus
  * visos programos veikimo laikas

| Matavimas      | Laikas 1 | Laikas 2 | Laikas 3  | Laikas 4 | Laikas 5 | Vidurkiai |
|----------------|----------|----------|-----------|----------|----------|-----------|
| Nuskaitymas    | 440 ms   | 443 ms   | 443 ms    | 444 ms   | 444 ms   | 443 ms    |
| Rūšiavimas     | 51 ms    | 51 ms    | 53 ms     | 50 ms    | 52 ms    | 51 ms     |
| Išvedimas      | 270 ms   | 273 ms   | 275 ms    | 267 ms   | 268 ms   | 270 ms    |
| Veikimo laikas | 848 ms   | 855 ms   | 859 ms    | 849 ms   | 853 ms   | 853 ms    |

[//]: # (> Parinktys:)

[//]: # (![parinktys-1.png]&#40;parinktys-1.png&#41;)

[//]: # (> Failo generavimo parinktys:)

[//]: # (![paarinktys-2.png]&#40;paarinktys-2.png&#41;)