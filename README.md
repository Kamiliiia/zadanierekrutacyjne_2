# zadanierekrutacyjne_2
Oto mój tok rozumowania: 
Każdy punkt w układzie współrzędnych ma 4 życia. Potrzebujemy tylko te punkty, które są krawędziami figury, która otoczy resztę punktów.
Dlatego jest funkcja, która porównuje jeden punkt z całą resztą wprowadzonych punktów.
I jeżeli znajdzie się x, który jest bardziej na prawo od obranego punktu to wtedy wybrany punkt traci jedno życie.
Jeżeli znajdzie się x, który jest bardziej na lewo obranego punktu to wtedy traci kolejne życie.
Analogicznie jest z y, jeśli znajdzie się punkt który ma wyżej y to traci kolejne, albo jak znajdzie sie punkt który ma niżej y to znowu traci życie.
I w taki sposób eliminujemy punkty wewnętrzne. I wtedy zostają punkty krawędziowe, którym zostało conajmniej jedno życie.
Na samym końcu zostają wyświetlone tylko te punkty którym zostały jakieś życia. Czyli powyżej 0. 
