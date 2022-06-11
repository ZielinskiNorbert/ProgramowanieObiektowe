#include <string>
#include <iostream>
#include <random>
#include <thread>
#include <chrono>
#include <vector>
#include <stdlib.h>

#include"animals/animal.h"
#include"animals/ant.h"
#include"animals/boar.h"
#include"animals/deer.h"
#include"animals/moose.h"
#include"animals/wisent.h"
#include"animals/wolf.h"
#include"animals/woodpacker.h"

int start();
int poruszanie(animal *anim);
int losowe();
void board();

void board()
{
    std::vector<std::vector<char>> board(50, std::vector<char>(50, ' '));

    std::cout << "Ile ma trwac symulacja: ";
    int ile;
    std::cin >> ile;

    std::vector<animal *> zwierzeta;

    for(int i=0; i<20;i++){
        int wartosc=losowe();
        int start1=start(), start2=start();
       while (board[start1][start2] != ' ')
        {
            start1=start(); start2=start();
        }
        std::cout << start1 << " " << start2 << std::endl;
        switch (wartosc)
        {
        case 1: 
           zwierzeta.push_back(new woodpacker);
            break;
        case 2: 
           zwierzeta.push_back(new moose);
            break;
        case 3: 
           zwierzeta.push_back(new deer);
            break;
        case 4: 
           zwierzeta.push_back(new wisent);
            break;
        case 5: 
           zwierzeta.push_back(new boar);
            break;
        case 6: 
           zwierzeta.push_back(new ant);
            break;
        case 7: 
           zwierzeta.push_back(new wolf);
            break;
        default:
            break;
        }
        std::cout << zwierzeta[i]->getZnak() << std::endl;
        zwierzeta[i]->info();
        zwierzeta[i]->setX(start1);
        zwierzeta[i]->setY(start2);

        board[start1][start2]=zwierzeta[i]->getZnak();
    }

    for(int i = 0; i < ile; i++)
    {
        system("cls");
        std::cout << std::endl;
        for(int j = 0; j < board.size(); j++)
        {
            for(int k = 0; k < board[j].size(); k++)
            {
                std::cout << board[j][k];
            }
            std::cout << std::endl;
        }

        for(int j=0; j<zwierzeta.size(); j++)
        {
            auto x = zwierzeta[j]->getX();
            auto y = zwierzeta[j]->getY();

            if(x >= 0 && x < 50 && y >= 0 && y < 50)
                board[zwierzeta[j]->getX()][zwierzeta[j]->getY()] = ' ';

            x += poruszanie(zwierzeta[j]);
            y += poruszanie(zwierzeta[j]);
            zwierzeta[j]->setX(x);
            zwierzeta[j]->setY(y);
            if(x >= 0 && x < 50 && y >= 0 && y < 50)
            {
                board[zwierzeta[j]->getX()][zwierzeta[j]->getY()] = zwierzeta[j]->getZnak();
            }
        }
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(200ms);

    }
    system("pause");
}

int start()
{
    std::random_device dev;
    std::mt19937 rng(dev());

    std::uniform_int_distribution<std::mt19937::result_type>vektor1(0,49);

    return vektor1(rng);
}

int poruszanie(animal *anim)
{
    std::random_device dev;
    std::mt19937 rng(dev());

    std::uniform_int_distribution<std::mt19937::result_type>vektor1(-anim->getSpeed(), anim->getSpeed());

    return vektor1(rng);
}

int losowe()
{
    std::random_device dev;
    std::mt19937 rng(dev());

    std::uniform_int_distribution<std::mt19937::result_type>vektor1(1,7);

    return vektor1(rng);
}

int main()
{
    board();
}
