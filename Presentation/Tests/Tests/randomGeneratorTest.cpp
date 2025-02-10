#include "../test.h"
#include "../../../Domain/Entites/RandomGenerator/randomGenerator.h"

void Test::randomGeneratorTest()
{
	cout << "generateNumber. Result: " << RandomGenerator::generateNumber(-1000, 1000) << ";" << endl;
}