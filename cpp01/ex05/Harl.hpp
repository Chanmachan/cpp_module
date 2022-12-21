//
// Created by 本間優之介 on 2022/12/13.
//

#ifndef CPP_MODULE_HARL_HPP
#define CPP_MODULE_HARL_HPP

#include <iostream>

class Harl {
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
public:
	Harl();
	~Harl();
	void complain( std::string level );
};


#endif //CPP_MODULE_HARL_HPP
