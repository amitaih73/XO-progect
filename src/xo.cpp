#include "xo.hpp"
#include "bord.hpp"
#include "ui.hpp"

namespace xo{

namespace{

Bord openingPlay()
{
    //make sure tha dimention between 1 - 10
    int userDimention = openingGame();
    while(userDimention < 1 || userDimention > 10){
        userDimention = openingGame();
    }
    Bord bord(userDimention);
    bord.print();
    return bord;
}
}//namespace

Xo::Xo()
: m_bord(openingPlay())
{}




std::optional<char> Xo::checkRows()
{
    int size = m_bord.dimention();
    int row = 0;
    int toReturnCOlo = 0;
    for(; row < size; ++row){
        for(int colo = 0; colo < size -1; ++colo){
            if(m_bord.get(row,colo) != m_bord.get(row, colo + 1)){
               return std::optional<char>();
            }
            toReturnCOlo = colo;
        }
    }
    return m_bord.get(row, toReturnCOlo);
}

std::optional<char> Xo::checkColos()
{
    int size = m_bord.dimention();
    int colo = 0;
    int toRetuRow = 0;
    for(; colo < size; ++colo){
        for(int row = 0; row < size -1; ++row){
            if(m_bord.get(row,colo) != m_bord.get(row, colo + 1)){
               return std::optional<char>();
            }
            toRetuRow = row;
        }
    }
    return m_bord.get(toRetuRow, colo);
}


std::optional<char> Xo::checkUpDiagonal()
{
    int size = m_bord.dimention();
    int colo = 0, row = size -1;
        for(; colo < size -1; ++colo, --row){
            if(m_bord.get(row,colo) != m_bord.get(row - 1, colo + 1)){
               return std::optional<char>();
            }
        }
        return m_bord.get(colo, row);
}

std::optional<char> Xo::checkDownDiagonal()
{
    int size = m_bord.dimention();
    int colo = 0, row = 0;
        for(; colo < size -1; ++colo, ++row){
            if(m_bord.get(row,colo) != m_bord.get(row + 1, colo + 1)){
               return std::optional<char>();
            }
        }
        return m_bord.get(colo, row);
}



std::optional<char> Xo::checkWiner()
{
    std::optional<char> winer = checkRows();
    if(not winer.has_value()){
        winer = checkColos();
        if(not winer.has_value()){
            winer = checkUpDiagonal();
            if(not winer.has_value()){
                winer = checkDownDiagonal();
            }
        }
    }
    return winer;
}

void Xo::game()
{
    checkWiner();
}

}//xo