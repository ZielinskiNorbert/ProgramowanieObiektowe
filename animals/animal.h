#pragma once
#include<string>
#include<iostream>

class animal{
public:
    virtual ~animal() {}

    virtual void info() const
    {
        std::cout << "Gatunek: " << kind 
                << "\n" << isAlive << "\nSymbol: " << znak << "\n\n";
    }

    virtual void death()
    {
        isAlive = false;
    }

    virtual int getX() const
    {
        return x;
    }

    virtual int getY() const
    {
        return y;
    }

    virtual void setX(int val)
    {
        x = val;
    }

    virtual void setY(int val)
    {
        y = val;
    }

    virtual char getZnak() const
    {
        return znak;
    }

    virtual void setZnak(char z)
    {
        znak = z;
    }
    
    virtual int getSpeed() const
    {
        return speed;
    }

    virtual void setSpeed(int val)
    {
        speed = val;
    }

    virtual void setKind(const std::string &k)
    {
        kind = k;
    }

    virtual bool alive() const
    {
        return isAlive;
    }

    virtual void setAlive(bool value)
    {
        isAlive = value;
    }


private:
    std::string kind;
    bool isAlive;
    int x, y;
    char znak;
    int speed;
};