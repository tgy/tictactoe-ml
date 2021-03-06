#include <memory>
#include <iostream>
#include <fstream>

#include "utils/make_unique.h"
#include "game.h"
#include "players/human.h"
#include "players/minmax.h"
#include "players/individual.h"
#include "players/random.h"
#include "utils/bsm.h"
#include "genetic.h"

using namespace std;

int main(int argc, char *argv[])
{
    srand(time(NULL));
    BSM::load("resources/states");

    //Genetic genetic;
    //genetic.run();
    
    //return 0;
    
    auto p1 = make_shared<Individual>(1);
    p1->load("resources/individuals/2014-04-21-06-22-57");
    auto p2 = make_shared<RandomPlayer>(2);
    for (int i = 0; i < 10000; ++i)
    {
        Game g(p1, p2);
        g.run(2);
    }

    return 0;
}
