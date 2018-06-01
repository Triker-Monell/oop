#include <iostream>
#include "Douban_by_movies.h"
using namespace std;
int main() {
    BaseCatcher* bas;
    bas=new Douban_by_movies;
    bas->MakeCatcher();
    delete bas;
    return 0;
}