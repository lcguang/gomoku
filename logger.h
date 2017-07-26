#ifndef LOGGER_H
#define LOGGER_H

#include <vector>

class Logger {
public:
	Logger();
	~Logger();

	void writeLog(int x, int y);

private:
	std::vector<std::vector<int>> board_;
	int player_;
};

#endif // LOGGER_H
