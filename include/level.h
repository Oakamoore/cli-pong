#ifndef LEVEL_H
#define LEVEL_H

#include <array>

class Level
{
public:
	enum Side
	{
		left,
		right,
	};

public:
	static constexpr std::size_t s_rows {21};
	static constexpr std::size_t s_columns {65};
	static constexpr std::size_t s_centreColumn {(s_columns / 2) - 1};
	static constexpr std::size_t s_centreRow {(s_rows / 2)};

	auto& setGrid() { return m_grid; }
	const auto& getGrid() const { return m_grid; }

private:
	std::array<std::array<char, s_columns>, s_rows> m_grid {};

};

#endif