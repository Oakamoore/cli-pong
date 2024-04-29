#ifndef LEVEL_H
#define LEVEL_H

#include <array>

class Level
{
public:
	static constexpr std::size_t s_rows {20};
	static constexpr std::size_t s_columns {60};

	using Grid = std::array<std::array<char, s_columns>, s_rows>;

public:
	Grid& setGrid() { return m_grid; }
	const Grid& getGrid() { return m_grid; }

private:
	Grid m_grid {};

};

#endif