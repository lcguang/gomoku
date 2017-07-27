#include <iostream>
#include <string>
#include "logger.h"

Logger::Logger(std::string fname) {
    log_file_.open("/Users/chenguangliu/Src/Qt/gomoku/log/" + fname, std::ios_base::app);
	if (!log_file_.is_open()) {
        std::cout << "File error, couldn't open \"" << fname << "\"" << std::endl;
        exit(EXIT_FAILURE);
    }
	board_.resize(15, std::vector<int>(15, -1));
	// Player value: 0 for opponent, 1 for self
	player_ = 1;
}

Logger::~Logger() {
	log_file_.close();
}

void Logger::writeLog(int x, int y) {
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
  	log_file_ << current_board;

  	// Update board and player
  	board_[x][y] = player_;
  	player_ = 1 - player_;
}
