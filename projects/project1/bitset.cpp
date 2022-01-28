#include "bitset.hpp"

// TODO COMMENT
//Default Constructor
Bitset::Bitset()
{
    bSize = 8; //Setting bitsize to 8
    intmax_t *newBitArr = new intmax_t[8]; //Creating the new array

    for(intmax_t i=0;i<bSize;i++)
    {
        newBitArr[i] = 0;
    }

    delete []bitArr; //Deleting the array
    bitArr = newBitArr; //Making the new array the default array
    

    
}

// TODO COMMENT
Bitset::Bitset(intmax_t size)
{
    if(size <=0)
    {
        valid = false; //Shows that it aint valid
    }

    else
    {

        bSize = size; //Setting bitsize to whatever the user wants
        intmax_t *newBitArr = new intmax_t[size]; //Creating the new array
        for(intmax_t i=0;i<bSize;i++)
        {
            newBitArr[i] = 0;
        }

        delete []bitArr; //Deleting the array
        bitArr = newBitArr; //Making the new array the default array
        
    }

}

// TODO COMMENT
Bitset::Bitset(const std::string & value)
{
    bSize = value.length(); //Getting the bitsize
    intmax_t *newBitArr = new intmax_t[bSize]; //Creating the new array

    //Setting the values of the bits
    int j=0;
    for(int i=bSize-1;i>=0;i--)
    {
        int hold = std::stoi(value.substr(j,1));
        j ++;
        newBitArr[i] = (intmax_t) hold;

        //Adding an error check
        if(newBitArr[i] != 0 && newBitArr[i] != 1)
        {
            valid = false;
        }
    }

    delete []bitArr; //Deleting the array
    bitArr = newBitArr; //Making the new array the default array
   
}

// TODO COMMENT
Bitset::~Bitset()
{
    delete []bitArr; //Deleting the array
}


// TODO COMMENT
intmax_t Bitset::size() const
{
    return bSize; //Returning the size of the bitset
}

// TODO COMMENT
bool Bitset::good() const
{
    return valid; //Returning if the bitset is valid or nah
}

// TODO COMMENT
void Bitset::set(intmax_t index)
{
    //Error checking to see if it is valid or nah
    if(index>=bSize)
    {
        valid = false;
    }

    bitArr[index] = 1; //Setting the nth bit to 1
}

// TODO COMMENT
void Bitset::reset(intmax_t index)
{
    //Error checking to see if it is valid or nah
    if(index<0 || index>=bSize)
    {
        valid = false;
    }

    else
    {
        bitArr[index] = 0; //Setting the nth bit to 0
    }
    

}

// TODO COMMENT
void Bitset::toggle(intmax_t index)
{
    //Error checking to see if it is valid or nah
    if(index<0 || index>=bSize)
    {
        valid = false;
    }

    if(bitArr[index] == 1)
    {
        bitArr[index] = 0;
    }

    else if(bitArr[index] == 0){
        bitArr[index] = 1;
    }

}

// TODO COMMENT
bool Bitset::test(intmax_t index)
{
    //Error checking to see if it is valid or nah
    if(index<0 || index>=bSize)
    {
        valid = false;
        return false;
    }

    if(bitArr[index] == 1)
    {
        return true;
    }

    else if(bitArr[index] == 0){
        return false;
    }

    
    
}

// TODO COMMENT
std::string Bitset::asString() const
{
    std::string bitString;

    for(int i = bSize-1;i>=0;i--)
    {
        bitString.append(std::to_string(bitArr[i]));
    }

    return bitString;

}

