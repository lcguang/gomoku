#ifndef LOGGER_H
#define LOGGER_H

#include <vector>
#include <fstream>

class Logger {
public:
	Logger(std::string fname);
	~Logger();

	void writeLog(int x, int y);

private:
	std::ofstream log_file_;
	std::vector<std::vector<int>> board_;
	int player_;
};

#endif // LOGGER_H
