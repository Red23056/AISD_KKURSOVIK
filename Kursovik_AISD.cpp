#include <vector>
#include <iostream>
using namespace std;
const short int undefined = -1;

void filling_mass(vector <int>& mass, int len)
{
    mass.resize(0);
    for (int i = 0; i < len; i++)
    {
        mass.push_back(i);
    }
}

int line_search(vector<int>& mass, int search)
{
    for (int i = 0; i < mass.size(); i++)
    {
        if (mass[i] == search)
        {
            return (i);
        }
    }
    return (undefined);
}

int binare_search(vector<int>& mass, int search) 
{
    int middle_index;
    int left = 0;
    int right = mass.size() - 1;
    while (left <= right)
    {
        middle_index = (left + right) / 2;
        if (mass[middle_index] == search)
        {
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
    return (undefined);
}

int ternary_search(vector<int>& mass, int search)
{
    int right = mass.size() - 1;
    int left = 0;
    while (right >= left) {
        int middle_1 = left + (right - left) / 3;
        int middle_2 = right - (right - left) / 3;

        if (mass[middle_1] == search) 
        {
            return (middle_1);
        }

        if (mass[middle_2] == search) 
        {
            return (middle_2);
        }

        if (search < mass[middle_1]) 
        {
            right = middle_1 - 1;
        }

        else if (search > mass[middle_2]) 
        {
            left = middle_2 + 1;
        }
        else 
        {
            left = middle_1 + 1;
            right = middle_2 - 1;
        }
    }
}


void regroup_search_algoritm(vector <int> mass, int command, int search)
{
    int index;
    switch (command)
    {
    case(1):index = line_search(mass, search);
        if (index >= 0)
        {
            cout << "Найденный элемент: " << mass[index] << "|его индекс: " << index << endl;
        }
        else
        {
            cout << "Элемент не найден" << endl;
        }
        break;
    case(2):index = binare_search(mass, search);
        if (index >= 0)
        {
            cout << "Найденный элемент: " << mass[index] << "|его индекс: " << index << endl;
        }
        else
        {
            cout << "Элемент не найден" << endl;
        }
        break;
    }
}

int main()
{
    int command;
    int search;
    vector <int> mass;
    setlocale(LC_ALL, "RU");
    cout << "Выберите алгоритм поиска" << endl << "1 - Линейный" << endl << "2 - Бинарный" << endl;
    cin >> command;
    for (int i = 10000; i <= 100000; i += 10000)
    {
        search = i - 1;
        //search = i / 2;
        filling_mass(mass, i);
        regroup_search_algoritm(mass, command, search);
    }
}