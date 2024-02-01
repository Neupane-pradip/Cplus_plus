#include "player.hh"

#include <iostream>

Player::Player( const std::string &name):
    name_(name),
    points_(0)
{
//std:: cout << "Player Initialised" << std::endl;
}

void Player::add_points(int points)
{
    points_ +=points;
    if (points_ > Winnig_Points)
    {
        points_ = Penalty_Points;
    }
}

bool Player::has_won()
{
    return points_ == Winnig_Points;

}

int Player::get_points()
{
    return points_;
}

std::string Player::get_name()
{
return name_;
}


