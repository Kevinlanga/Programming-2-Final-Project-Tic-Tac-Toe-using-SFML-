#include "Cell.h"


Cell::Cell()
{
    value = ' ';
}


Cell::~Cell()
{

}


void Cell::setValue(char newValue)
{
    value = newValue;
}


char Cell::getValue() const
{
    return value;
}


bool Cell::isEmpty() const
{
    return value == ' ';
}