#include <vector>
#include <iostream>
#include <chrono>
#include <math.h>
using namespace std;
const short int undefined = -1;

void filling_mass(vector <int>& mass, int len)
{
    mass.resize(0);
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        mass.push_back(j);
        j += 100;
    }
}

int line_search(vector<int>& mass, int search)
{
    auto begin = std::chrono::steady_clock::now();
    for (int i = 0; i < mass.size(); i++)
    {
        if (mass[i] == search)
        {
            auto end = std::chrono::steady_clock::now();
            auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            cout << elapsed_ms.count() << endl;
            return (i);
        }
    }
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << elapsed_ms.count() << endl;
    return (undefined);
}

int binare_search(vector<int>& mass, int search) 
{
    auto begin = std::chrono::steady_clock::now();
    int middle_index;
    int left = 0;
    int right = mass.size() - 1;
    while (left <= right)
    {
        middle_index = (left + right) / 2;
        if (mass[middle_index] == search)
        {
            auto end = std::chrono::steady_clock::now();
            auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            cout << elapsed_ms.count() << endl;
            return(middle_index);
        }
        if (mass[middle_index] < search)
        {
            left = middle_index + 1;
        }
        else
        {
            right = middle_index - 1;
        }
    }
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << elapsed_ms.count() << endl;
    return (undefined);
}

int ternary_search(vector<int>& mass, int search)
{
    auto begin = std::chrono::steady_clock::now();
    int middle_index_1;
    int middle_index_2;
    int left = 0;
    int right = mass.size() - 1;
    while (right >= left) 
    {
        middle_index_1 = left + (right - left) / 3;
        middle_index_2 = right - (right - left) / 3;

        if (mass[middle_index_1] == search) 
        {
            auto end = std::chrono::steady_clock::now();
            auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            cout << elapsed_ms.count() << endl;
            return (middle_index_1);
        }

        if (mass[middle_index_2] == search) 
        {
            auto end = std::chrono::steady_clock::now();
            auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            cout << elapsed_ms.count() << endl;
            return (middle_index_2);
        }

        if (search < mass[middle_index_1]) 
        {
            right = middle_index_1 - 1;
        }

        else if (search > mass[middle_index_2]) 
        {
            left = middle_index_2 + 1;
        }

        else 
        {
            left = middle_index_1 + 1;
            right = middle_index_2 - 1;
        }
    }
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << elapsed_ms.count() << endl;
    return(undefined);
}

int interpolation_search(vector <int>& mass, int search)
{
    auto begin = std::chrono::steady_clock::now();
    int search_index;
    int left = 0;
    int right = mass.size() - 1;
    while (right >= left)
    {
        search_index = left + (((double)(right - left) / (mass[right] - mass[left])) * (search - mass[left]));

        if (mass[search_index] == search)
        {
            auto end = std::chrono::steady_clock::now();
            auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            cout << elapsed_ms.count() << endl;
            return (search_index);
        }

        if (mass[search_index] < search)
        {
            left = search_index + 1;
        }

        if (mass[search_index] > search)
        {
            right = search_index - 1;
        }
    }
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << elapsed_ms.count() << endl;
    return (undefined);
}


void regroup_search_algoritm(vector <int> mass, int command, int search)
{
    cout << mass.size() << " ";
    int index;
    switch (command)
    {
    case(1):
        //index = line_search(mass, search);
        /*if (index >= 0)
        {
            cout << "Найденный элемент: " << mass[index] << "|его индекс: " << index << endl;
        }
        else
        {
            cout << "Элемент не найден" << endl;
        }*/
        break;

    case(2):
        //index = binare_search(mass, search);
        /*if (index >= 0)
        {
            cout << "Найденный элемент: " << mass[index] << "|его индекс: " << index << endl;
        }
        else
        {
            cout << "Элемент не найден" << endl;
        }*/
        break;

    case(3):
        //index = ternary_search(mass, search);
        /*if (index >= 0)
        {
            cout << "Найденный элемент: " << mass[index] << "|его индекс: " << index << endl;
        }
        else
        {
            cout << "Элемент не найден" << endl;
        }*/
        break;

    case(4):
        index = interpolation_search(mass, search);
        /*if (index >= 0)
        {
            cout << "Найденный элемент: " << mass[index] << "|его индекс: " << index << endl;
        }
        else
        {
            cout << "Элемент не найден" << endl;
        }*/
        break;
    }
}

int main()
{
    int command;
    int search;
    vector <int> mass;
    setlocale(LC_ALL, "RU");
    cout << "Выберите алгоритм поиска" << endl << "1 - Линейный" << endl << "2 - Бинарный" << endl
        << "3 - Тернарный" << endl << "4 - Интерполяционный" << endl;
    cin >> command;
    for (int i = 10000; i <= 100000; i += 10000)
    {
        //search = 0;
        filling_mass(mass, i);
        search = i/2;
        regroup_search_algoritm(mass, command, search);
    }
}