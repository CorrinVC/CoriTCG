#include <chrono>
#include <random>

namespace Cori {

namespace Random {

    inline std::mt19937 generate() {
        std::random_device rand {};
        std::seed_seq seedSequence {
            static_cast<std::seed_seq::result_type>(
                std::chrono::steady_clock::now().time_since_epoch().count()
            ),
            rand(), rand(), rand(), rand(), rand(), rand(), rand()
        };

        return std::mt19937{ seedSequence };
    }

    inline std::mt19937 mt { generate() };

    inline int get(int min, int max) {
        return std::uniform_int_distribution { min, max }(mt);
    }

}

}