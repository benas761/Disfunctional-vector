Vector

1. Vektorius veikia ne taip, kaip orginalus. 
  - Nesugebėta įgyvendyti emplace() funkcijų
  -  std::move funkcija vektorių tiesiog nukopijuoja
  - 8/22 testų neišlaikyti (3 dėl std::move, 2 dėl emplace, 1 dėl template apribojimų, 2 dėl kitko)
  - Neveikia su c++11 for ciklais kai vektorius atsiunčiamas kaip const.
2. Analyzė įvykdyta su time_test.cpp:
    - Su 10000:
        - std::vector: 0.000596235s
        - Vector.h: 0.000713018s
    - Su 100000:
        - std::vector: 0.00297857s
        - Vector.h: 0.0014574s
    - Su 1000000:
        - std::vector: 0.138447s
        - Vector.h: 0.161238s
    - Su 10000000:
        - std::vector: 0.138447s
        - Vector.h: 0.161238s
    - Su 100000000:
        - std::vector: 1.31019s
        - Vector.h: 1.50316s
3. Kadangi programa skaičiuoja 256 sekundes su 10^7, pamatuoti perrinkimų skaičių su 10^8 labai ilgai užtruktų. Skaičiuojant su 10^6 abu konteiniariai padarė 18 perrinkimų.
4. Vektorius tinkamai veikia su 3 užduotimi. Modifikuota užduotis yra aplanke "3 uzduotis". Isvestis su 50 studentu:
```
Vardas            Pavarde           Galutinis (Vid.) / Galutinis (Med.)
------------------------------------------------------------
Vardas1           Pavarde1          3.88               3.8
Vardas10          Pavarde10         4.19               3.2
Vardas11          Pavarde11         3.93               3.4
Vardas14          Pavarde14         2.49               2.2
Vardas26          Pavarde26         4.61               4.4
Vardas28          Pavarde28         4.17               4.2
Vardas31          Pavarde31         3.89               3.6
Vardas35          Pavarde35         2.97               3
Vardas37          Pavarde37         3.6                3.2
Vardas38          Pavarde38         4.73               4.2
Vardas39          Pavarde39         2.84               2.6
Vardas4           Pavarde4          3.19               3
Vardas40          Pavarde40         2.15               2.2
Vardas42          Pavarde42         4.17               3.8
Vardas43          Pavarde43         4.8                4
Vardas48          Pavarde48         2.49               2.2
Vardas49          Pavarde49         2.12               1.8
Vardas6           Pavarde6          3.65               3.2
Vardas8           Pavarde8          2.89               2.6

Patenkinami:
Vardas            Pavarde           Galutinis (Vid.) / Galutinis (Med.)
------------------------------------------------------------
Vardas12          Pavarde12         8.24               8.4 
Vardas13          Pavarde13         6.04               5.4 
Vardas15          Pavarde15         6.75               6 
Vardas16          Pavarde16         6.41               6.2 
Vardas17          Pavarde17         5.91               6.2 
Vardas18          Pavarde18         8.4                8.4 
Vardas19          Pavarde19         8.43               8.4 
Vardas2           Pavarde2          6.15               6.2
Vardas20          Pavarde20         7.87               7.6 
Vardas21          Pavarde21         7.36               7.2 
Vardas22          Pavarde22         6.47               6.6 
Vardas23          Pavarde23         6.83               6.8 
Vardas24          Pavarde24         6.04               5.4
Vardas25          Pavarde25         8.04               8.2 
Vardas27          Pavarde27         6.39               6.2
Vardas29          Pavarde29         5.23               5.2
Vardas3           Pavarde3          5.59               5.8 
Vardas30          Pavarde30         6.55               6.6
Vardas32          Pavarde32         5.09               5.2 
Vardas33          Pavarde33         6.25               5.8 
Vardas34          Pavarde34         5.36               4.8 
Vardas36          Pavarde36         8.91               9.2 
Vardas41          Pavarde41         6.6                6.2 
Vardas44          Pavarde44         6.4                6
Vardas45          Pavarde45         6.85               6.4 
Vardas46          Pavarde46         8.45               8.4 
Vardas47          Pavarde47         6.55               6.2 
Vardas5           Pavarde5          7.29               7.4
Vardas50          Pavarde50         5.05               4.6
Vardas7           Pavarde7          7.83               7.4 
Vardas9           Pavarde9          6.89               6.6 
```
