/*
Реализуйте простую симуляцию игры в рыбалку. В исходном текстовом файле реки (river.txt) задаётся список из видов рыб,
которые можно в ней поймать. Рыбок может быть сколько угодно, разных видов. Виды при этом могут повторяться.

В начале программы пользователь указывает, какую именно рыбу он сейчас будет ловить — вид этой рыбы. После этого из первого
файла друг за другом осуществляется чтение его содержимого, вид за видом. Если на отдельных шагах вид совпал с указанным пользователем,
в выходной файл basket.txt (корзинка) записывается этот вид.

В конце программы показывается, сколько было поймано рыб за текущую ловлю. Программу можно запускать несколько раз,
при этом уже пойманные рыбы должны сохраняться в файле-корзинке.

Пример содержания исходного файла

sunfish
shad
carp
bass
bullhead
carp
walleye
catfish
carp

Что оценивается

Корректность работы программы симуляции игры в рыбалку. Пойманные рыбы должны записываться в выходной файл.
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string sFishName;
    cout << " say ""none"" for exit " << endl;

    while (sFishName != "none")
    {
        cout << "Did you catch a fish? ";

        cin >> sFishName;
        
        bool bCatchFish = false;
        //open river.txt

        ifstream river("river.txt");
        if (river.is_open())
        {
            while (!river.eof())
            {
                string sTemp;
                river >> sTemp;
                if (sTemp == sFishName)
                {
                    bCatchFish = true;
                }
                
            }
            
            if (!bCatchFish) cout << "There are no fish in the river " << endl;
        }
        else
        {
            // show error message
            cout << "Error opening river.txt";
            continue;
        }
        
        river.close();
        
        if (bCatchFish)
        {

            //open basket.txt

            ofstream basket("basket.txt", ios::app);
            if (basket.is_open())
            {
                basket << sFishName << endl;
                cout << "Congratilation!" << endl;
            }
            else
            {
                // show message:
                cout << "Error opening basket.txt";
            }

            basket.close();
        }

        


    }

        

}
