class LinearCongruentialGenerator {
private:
    unsigned int seed;
    unsigned int a;
    unsigned int c;
    const unsigned int m;

public:
    LinearCongruentialGenerator(double seed, unsigned int a, unsigned int c, unsigned int m)
        : seed(seed), a(a), c(c), m(m) {}

    // Generate a pseudo-random number
    double generateRandomNumber() {
        seed = ( a * seed + c) % m;
        return seed / (m+0.0);
    }

    // Generate a vector of pseudo-random numbers
    std::vector<double> generateRandomVector(size_t size) {
        std::vector<double> randomNumbers;
        randomNumbers.reserve(size);

        for (size_t i = 0; i < size; ++i) {
            randomNumbers.push_back(generateRandomNumber());
        }

        return randomNumbers;
    }
};


