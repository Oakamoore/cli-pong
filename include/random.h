#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include <chrono>

namespace Random
{
	// Returns a seeded Mersenne Twister
	inline std::mt19937 generate()
	{
		std::random_device rd {};

		std::seed_seq ss {static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
						  rd(), rd(), rd(), rd(), rd(), rd(), rd()};

		return std::mt19937 {ss};
	}

	inline std::mt19937 mt {generate()};

	// Randomly returns either one of the parameters 
	template <typename T>
	T chooseBetween(T a, T b)
	{
		// Generates either 'true' or 'false', 1/2 of the time
		std::bernoulli_distribution dist {0.5};

		return (dist(mt)) ? a : b;
	}
}

#endif
