## Sort VIsualizer _by Mateusz Kisiel_

### Opis projektu:
Jest to program symulujący różne sposoby sortowań. Wiele takich animacji jest na youtube, stąd też poszła inspiracja. 

#### Sterowanie
* Strzałkami góra/doł można przyśpieszyć/zwolnić
* Lewy Ctrl ustawie prędkość na maksymalną

#### Szczegóły implementacyjne
Zamysł jest taki, by móc wykonać zwykłą funcję sortująca skopiowaną z internetu, na bieżąco wyświetlając w oknie porównywane elementy. 
W tym celu stworzyłem klasę IntWrapper, który przy każdym porównaniu/modyfikacji aktualizuje kolor w oknie. Wystarczy zatem zmienić tylko typ int na IntWrapper i nowa funkcja będzie wyświetlana.

Okno sfml działa w osobnym wątku i zmiana kolorów z wątka głównego następuje poprzez dispatcher. Projekt napisałem kilka lat temu w C++ z użyciem SFML. Dziś pewnie zrobił bym go trochę inaczej.

### Nagranie:

https://user-images.githubusercontent.com/25119453/175793581-4fbe4565-3f5c-42a8-b0b8-7b2906ba47bf.mp4


### Jak uruchomić:
1) Pobierz SFML w wersji 2.5.1 dla kompilatora GCC 7.3.0 MinGW (SEH) - 64-bit (w przypadku Windowsa). https://www.sfml-dev.org/download/sfml/2.5.1/
2) Wybierz odpowiedni kompilator w Clion(jak nie masz to pobierz z powyszego linku)
3) Ustaw w CMakeLists.txt odpowiednie ścieżki do SFML
4Skompiluj

