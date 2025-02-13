#include "../test.h"
#include "../../../Domain/Entites/RandomGenerator/randomGenerator.h"

void Test::randomGeneratorTest()
{
	cout << "generateNumber. Result: " << RandomGenerator::generateNumber(long long(-1000), long long(1000)) << ";" << endl;
	cout << "generateNumber. Result: " << RandomGenerator::generateNumber(-1000.0, 1000.0) << ";" << endl;
}