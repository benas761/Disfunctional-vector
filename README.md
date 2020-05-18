disfunctional vector

1. Vektorius veikia ne taip, kaip orginalus. 
  - Nesugebėta įgyvendyti emplace() funkcijų
  -  std::move funkcija vektorių tiesiog nukopijuoja
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



