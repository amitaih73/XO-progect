#pragma once
#include "bord.hpp"
#include <optional>
namespace xo{

class Xo final{
public:
    Xo();
    Xo(Xo const& a_other) = delete;

    void game();

private:
    std::optional<char> checkWiner();
    std::optional<char> checkRows();
    std::optional<char> checkColos();
    std::optional<char> checkUpDiagonal();
    std::optional<char> checkDownDiagonal();
private:
    Bord m_bord;
};



}//xo