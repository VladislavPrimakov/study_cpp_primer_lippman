//”пражнение 12.27. лассы TextQuery и QueryResult используют только
//те возможности, которые уже были описаны ранее.Ќе загл€дыва€ вперед,
//напишите собственные версии этих классов.

#include <fstream>
#include "TextQuery.h"

int main(int agrc, char* argv[]) {
	if (agrc != 2) {
		std::cerr << "Usage: " << argv[0] << " <file>\n";
		return 1;
	}
	std::ifstream infile(argv[1]);
	if (!infile) {
		std::cerr << "Could not open file " << argv[1] << "\n";
		return 1;
	}
	runQueries(infile);
	return 0;
}