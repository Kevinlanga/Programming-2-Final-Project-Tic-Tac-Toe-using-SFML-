#pragma once

class Cell
{
private:

    char value;


public:

    Cell();

    ~Cell();


    void setValue(char newValue);

    char getValue() const;

    bool isEmpty() const;
};
