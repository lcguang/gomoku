#include "logger.h"

int main() {
	Logger* logger = new Logger("test_log.txt");
	logger->writeLog(0, 0);
	logger->writeLog(0, 1);
	logger->writeLog(0, 2);
	logger->writeLog(0, 3);
	logger->writeLog(0, 4);
	delete logger;
	return 0;
}