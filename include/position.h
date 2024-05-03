#ifndef POSITION_H
#define POSITION_H

template <typename T>
struct Position
{
	T row {};
	T col {};
};

// Overloaded template operator function for 'Position<T> + Position<U>'
template <typename T, typename U>
inline Position<T> operator+(const Position<T>& p1, const Position<U>& p2)
{
	return {p1.row + p2.row, p1.col + p2.col};
}

#endif