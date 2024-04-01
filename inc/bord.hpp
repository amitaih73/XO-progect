#pragma once
#include <vector>

namespace xo{

using BORD = std::vector<std::vector<char>>;

class Bord final{
public:
    explicit Bord(int a_dimentions = 3);
    Bord(Bord const& a_other) = default;
    Bord& operator=(Bord const& a_other) = delete;
    ~Bord() = default;

    char const& get(int a_row, int a_colo) noexcept;
    void set(int a_row, int a_colo, char a_toSet) noexcept;
    int dimention() noexcept;
    void print() noexcept;

private:
    BORD m_bord; 
    int m_dimention;
};

}//xo
