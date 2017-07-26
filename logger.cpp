#include <fstream>
#include <string>
#include "logger.h"

Logger::Logger() {
	board_.resize(15, std::vector<int>(15, -1));
	// Player value: 0 for opponent, 1 for self
	player_ = 1;
}

Logger::~Logger() {

}

void Logger::writeLog(int x, int y) {
	// Open log file
	std::ofstream outfile;
  	outfile.open("log/log.txt", std::ios_base::app);

  	// Generate log contents
  	std::string current_board = "";
  	for (int i = 0; i < 15; i++) {
  		for (int j = 0; j < 15; j++) {
  			int chess_val = board_[i][j];
  			if (chess_val != -1 && player_ == 0) {
  				chess_val = 1 - chess_val;
  			}
  			current_board += std::to_string(chess_val);
  			current_board.push_back(' ');
  		}
  	}
  	current_board.pop_back();
  	current_board.push_back('\t');
  	current_board += std::to_string(x * 15 + y);
  	current_board.push_back('\n');

  	// Write to log file
  	outfile << current_board;
  	outfile.close();

  	// Update board and player
  	board_[x][y] = player_;
  	player_ = 1 - player_;
}
