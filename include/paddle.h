#ifndef PADDLE_H
#define	PADDLE_H

#include "position.h"
#include "directions.h"
#include <cstddef>
#include <utility>
	
class Paddle
{
public:
	using Controls = std::pair<char, char>;

	Paddle(Position<std::size_t> startPos, Controls controls)
		: m_centre {startPos}
		, m_controls {controls}
	{
	}

	const Position<std::size_t>& getPositon() const { return m_centre; }
	const Controls& getControlScheme() const { return m_controls; }

private:
	Position<std::size_t> m_centre {};
	Controls m_controls {};
	Directions::Type m_direction {Directions::none}; 
};

#endif