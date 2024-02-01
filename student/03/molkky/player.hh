#ifndef PLAYER_HH
#define PLAYER_HH

#include <string>

int const Winnig_Points = 50;
int const Penalty_Points =25;


class Player
{
public:
    Player(std::string const &name);
    void add_points(int points);
    bool has_won();
    int get_points();
    std::string get_name();

private:
    std::string name_;
    int points_;



};

#endif // PLAYER_H
