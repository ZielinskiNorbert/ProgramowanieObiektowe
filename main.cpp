#include <string>
#include <iostream>
#include <random>
#include <thread>
#include <chrono>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <fstream>


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
    std::vector<std::vector<char>> board(75, std::vector<char>(75, ' ')); //rozmiar planszy

    std::cout << "Prosze podac dlugosc symulacji: ";
    int ile;    //ile ma trwac symulacja
    std::fstream zapis_statystyk; 
    std::cin >> ile; //dlugosc trwania symualacji

    std::vector<animal *> zwierzeta;

    for(int i=0; i<25;i++){ //rozlosowanie miejsc startowych i ilosci gatunkow
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
        }
        std::cout << zwierzeta[i]->getZnak() << std::endl;
        zwierzeta[i]->info();
        zwierzeta[i]->setX(start1);
        zwierzeta[i]->setY(start2);

        board[start1][start2]=zwierzeta[i]->getZnak();
    }
    int ilosc_x_start=count_if(zwierzeta.begin(), zwierzeta.end(), [](animal *a){return a->getZnak()=='x';}); //zapis ilosci zwierzat na poczatku
    int ilosc_W_start=count_if(zwierzeta.begin(), zwierzeta.end(), [](animal *a){return a->getZnak()=='w';});
    int ilosc_a_start=count_if(zwierzeta.begin(), zwierzeta.end(), [](animal *a){return a->getZnak()=='a';});
    int ilosc_B_start=count_if(zwierzeta.begin(), zwierzeta.end(), [](animal *a){return a->getZnak()=='B';});
    int ilosc_u_start=count_if(zwierzeta.begin(), zwierzeta.end(), [](animal *a){return a->getZnak()=='u';});
    int ilosc_m_start=count_if(zwierzeta.begin(), zwierzeta.end(), [](animal *a){return a->getZnak()=='m';});
    int ilosc_z_start=count_if(zwierzeta.begin(), zwierzeta.end(), [](animal *a){return a->getZnak()=='z';});

    for(int i = 0; i < ile; i++)
    {
        system("cls");
        std::cout << std::endl;
        for(int j = 0; j < board.size(); j++)   //wywolanie planszy
        {
            for(int k = 0; k < board[j].size(); k++)
            {
                std::cout << board[j][k];
            }
            std::cout << std::endl;
        }

        for(int j=0; j<zwierzeta.size(); j++) //poruszanie sie zwierzat
        {  
            auto x = zwierzeta[j]->getX();
            auto y = zwierzeta[j]->getY();

            if(x >= 0 && x < 75 && y >= 0 && y < 75)
                board[zwierzeta[j]->getX()][zwierzeta[j]->getY()] = ' ';
            if(zwierzeta[j]->alive()==true){
            x += poruszanie(zwierzeta[j]);
            y += poruszanie(zwierzeta[j]);
            zwierzeta[j]->setX(x);
            zwierzeta[j]->setY(y);
            if(x >= 0 && x < 75 && y >= 0 && y < 75)
            {
                board[zwierzeta[j]->getX()][zwierzeta[j]->getY()] = zwierzeta[j]->getZnak();
            }}
        }
        int size=zwierzeta.size();
        for(int j=0; j<size; j++){
            for(int k=0; k<size; k++){
                if(j==k)
                    continue;
                if(zwierzeta[j]->getX()==zwierzeta[k]->getX()&&zwierzeta[j]->getY()==zwierzeta[k]->getY()){ //rozmnarzanie sie zwierzat
                    if(zwierzeta[j]->alive()&&zwierzeta[k]->alive()){
                    if(zwierzeta[j]->getZnak()==zwierzeta[k]->getZnak()){
                        switch (zwierzeta[j]->getZnak())
                        {
                        case 'a':
                            zwierzeta.push_back(new ant);
                            zwierzeta[zwierzeta.size()-1]->setX(zwierzeta[j]->getX());
                            zwierzeta[zwierzeta.size()-1]->setY(zwierzeta[j]->getY());
                            break;
                        case 'x':
                            zwierzeta.push_back(new woodpacker);
                            zwierzeta[zwierzeta.size()-1]->setX(zwierzeta[j]->getX());
                            zwierzeta[zwierzeta.size()-1]->setY(zwierzeta[j]->getY());
                            break;
                        case 'm':
                            zwierzeta.push_back(new moose);
                            zwierzeta[zwierzeta.size()-1]->setX(zwierzeta[j]->getX());
                            zwierzeta[zwierzeta.size()-1]->setY(zwierzeta[j]->getY());
                            break;
                        case 'u':
                            zwierzeta.push_back(new deer);
                            zwierzeta[zwierzeta.size()-1]->setX(zwierzeta[j]->getX());
                            zwierzeta[zwierzeta.size()-1]->setY(zwierzeta[j]->getY());
                            break;
                        case 'w':
                            zwierzeta.push_back(new wolf);
                            zwierzeta[zwierzeta.size()-1]->setX(zwierzeta[j]->getX());
                            zwierzeta[zwierzeta.size()-1]->setY(zwierzeta[j]->getY());
                            break;
                        case 'B':
                            zwierzeta.push_back(new boar);
                            zwierzeta[zwierzeta.size()-1]->setX(zwierzeta[j]->getX());
                            zwierzeta[zwierzeta.size()-1]->setY(zwierzeta[j]->getY());
                            break;
                        case 'z':
                            zwierzeta.push_back(new wisent);
                            zwierzeta[zwierzeta.size()-1]->setX(zwierzeta[j]->getX());
                            zwierzeta[zwierzeta.size()-1]->setY(zwierzeta[j]->getY());
                            break;
                    }
                    if(zwierzeta[j]->getZnak()=='w'&&zwierzeta[k]->getZnak()=='u'){ //zabijanie zwierzat 
                        zwierzeta[k]->setAlive(false);}
                    if(zwierzeta[j]->getZnak()=='w'&&zwierzeta[k]->getZnak()=='z'){
                        zwierzeta[k]->setAlive(false);}
                    if(zwierzeta[j]->getZnak()=='w'&&zwierzeta[k]->getZnak()=='B'){
                        zwierzeta[k]->setAlive(false); }
                    if(zwierzeta[j]->getZnak()=='x'&&zwierzeta[k]->getZnak()=='a'){
                        zwierzeta[k]->setAlive(false);}
                    if(zwierzeta[j]->getZnak()=='B'&&zwierzeta[k]->getZnak()=='a'){
                        zwierzeta[k]->setAlive(false);
                    }
                    }

              
                }

            }

        }
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(2ms);

    }}

    int ilosc_x_end=count_if(zwierzeta.begin(), zwierzeta.end(), [](animal *a){return a->getZnak()=='x';}); //zapisywanie ilosci zwierzat na koncu 
    int ilosc_W_end=count_if(zwierzeta.begin(), zwierzeta.end(), [](animal *a){return a->getZnak()=='w';});
    int ilosc_a_end=count_if(zwierzeta.begin(), zwierzeta.end(), [](animal *a){return a->getZnak()=='a';});
    int ilosc_B_end=count_if(zwierzeta.begin(), zwierzeta.end(), [](animal *a){return a->getZnak()=='B';});
    int ilosc_u_end=count_if(zwierzeta.begin(), zwierzeta.end(), [](animal *a){return a->getZnak()=='u';});
    int ilosc_m_end=count_if(zwierzeta.begin(), zwierzeta.end(), [](animal *a){return a->getZnak()=='m';});
    int ilosc_z_end=count_if(zwierzeta.begin(), zwierzeta.end(), [](animal *a){return a->getZnak()=='z';});

    zapis_statystyk.open("statystyki.txt", std::ios::out | std::ios::app); //wpisywanie statystyk do pliku txt i ich wypisywanie
    zapis_statystyk<<"Dlugosc symulacji: "<<ile<<std::endl;
    std::cout<<"Dlugosc symulacji: "<<ile<<std::endl;
    zapis_statystyk<<"Wilka start: "<<ilosc_W_start<<" Wilk koniec: "<<ilosc_W_end<<std::endl;
    std::cout<<"Wilka start: "<<ilosc_W_start<<" Wilk koniec: "<<ilosc_W_end<<std::endl;
    zapis_statystyk<<"Mysz start: "<<ilosc_m_start<<" Mysz koniec: "<<ilosc_m_end<<std::endl;
    std::cout<<"Mysz start: "<<ilosc_m_start<<" Mysz koniec: "<<ilosc_m_end<<std::endl;
    zapis_statystyk<<"Dzieciol start: "<<ilosc_x_start<<" Dzeciol koniec: "<<ilosc_x_end<<std::endl;
    std::cout<<"Dzieciol start: "<<ilosc_x_start<<" Dzeciol koniec: "<<ilosc_x_end<<std::endl;
    zapis_statystyk<<"Mrowka start: "<<ilosc_a_start<<" Mrowka koniec: "<<ilosc_a_end<<std::endl;
    std::cout<<"Mrowka start: "<<ilosc_a_start<<" Mrowka koniec: "<<ilosc_a_end<<std::endl;
    zapis_statystyk<<"Dzik start: "<<ilosc_B_start<<" Dzik koniec: "<<ilosc_B_end<<std::endl;
    std::cout<<"Dzik start: "<<ilosc_B_start<<" Dzik koniec: "<<ilosc_B_end<<std::endl;
    zapis_statystyk<<"Jelen start: "<<ilosc_u_start<<" Jelen koniec: "<<ilosc_u_end<<std::endl;
    std::cout<<"Jelen start: "<<ilosc_u_start<<" Jelen koniec: "<<ilosc_u_end<<std::endl;
    zapis_statystyk<<"zubr start: "<<ilosc_z_start<<" Zubr koniec: "<<ilosc_z_end<<std::endl;
    std::cout<<"zubr start: "<<ilosc_z_start<<" Zubr koniec: "<<ilosc_z_end<<std::endl;
    zapis_statystyk<<std::endl;

    zapis_statystyk.close();
    system("pause");
}   

int start()
{
    std::random_device dev;
    std::mt19937 rng(dev());

    std::uniform_int_distribution<std::mt19937::result_type>vektor1(0,60);

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


