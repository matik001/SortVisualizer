#include <iostream>
#include <vector>
#include "SortVisualizer.h"
#include "Sorts.h"

#ifdef _WIN32 /// chcemy ukryc konsole
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

int main() {

    srand(time(nullptr));
    int maxVal = 10000;

    std::cout << "Liczba elementow: ";
    int count;
    std::cin >> count;
    std::cout << std::endl;

    std::vector<int> tab(count);
    for (int i = 0; i < tab.size(); i++)
        tab[i] = (rand() % maxVal) + 1;

    SortVisualizer visualizer(1000, maxVal);
    std::vector<IntWrapper> array = visualizer.init_values(tab);
    visualizer.show_window();

    std::cout << "Wybierz typ sortowania:" << std::endl
              << "1) BubbleSort" << std::endl
              << "2) InsertionSort" << std::endl
              << "3) QuickSort" << std::endl
              << "4) HeapSort" << std::endl
              << "5) SelectionSort" << std::endl
              << "6) MergeSort" << std::endl
              << "7) OddEvenSort" << std::endl
              << "8) GnomeSort" << std::endl
              << "9) CoctailSort" << std::endl
              << ">";

    int typ;
    std::cin >> typ;
    switch (typ)
    {
        case 1:
            bubbleSort(&array[0], array.size());
            break;
        case 2:
            insertionSort(&array[0], array.size());
            break;
        case 3:
            quickSort(&array[0], 0, array.size() - 1);
            break;
        case 4:
            heapSort(&array[0], tab.size());
            break;
        case 5:
            selectionSort(&array[0], tab.size());
            break;
        case 6:
            mergesort(&array[0], 0, array.size() - 1);
            break;
        case 7:
            oddEvenSort(&array[0], tab.size());
            break;
        case 8:
            gnomeSort(&array[0], tab.size());
            break;
        case 9:
            CocktailSort(&array[0], array.size());
            break;
        default:
            break;
    }

    return	0;
}
