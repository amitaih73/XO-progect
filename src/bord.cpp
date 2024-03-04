#include <iostream>
#include <algorithm>
#include "bord.hpp"

namespace xo{

namespace{

std::vector<std::vector<char>> createXoBord(int a_dimentions)
{
    std::vector<std::vector<char>> bord(a_dimentions);

    for (std::vector<char>& row : bord){
        std::generate_n(std::back_inserter(row), a_dimentions,
            []()
            {
                return ' ';   
            });
    }
    return bord;
}


}//namespace

Bord::Bord(int a_dimentions)
: m_bord(createXoBord(a_dimentions))
, m_dimention(a_dimentions)
{}

char const& Bord::get(int a_row, int a_colo) noexcept
{
    return m_bord[a_row][a_colo];
}

void Bord::set(int a_row, int a_colo, char a_toSet) noexcept
{
    m_bord[a_row][a_colo] = a_toSet;
}

int Bord::dimention() noexcept
{
    return m_dimention;
}

void Bord::print() noexcept
{
    //prints colos numbers
    std::cout << "  ";
    for(int i = 1; i < m_dimention + 1; ++i){
        std::cout << i <<"|"; 
    }
    std::cout << "\n";
    char colo = 'a';
    for(std::vector<char>& row : m_bord){
    //prints row numbers in 'abc' format
        printf("%c|", colo);
    //prints rows
        for(char& sign : row){
            std::cout << sign << "|";
        }
        ++colo;
        std::cout << "\n";
    }
}

}//xo