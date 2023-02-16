//
// Created by 本間優之介 on 2023/02/16.
//

#include "ScavTrap.h"

ScavTrap::ScavTrap(): ClapTrap() {
	std::cout << "ScavTrap Default Constructor called" << std::endl;
	this->hit_point_ = init_hp;
	this->energy_point_ = init_ep;
	this->attack_damage_ = init_ad;
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name) {
	std::cout << "ScavTrap " << this->name_ << " Default Constructor called" << std::endl;
	this->name_ = name;
	this->hit_point_ = init_hp;
	this->energy_point_ = init_ep;
	this->attack_damage_ = init_ad;
}

ScavTrap::ScavTrap(const ScavTrap &src) {
	std::cout << "name: " << src.name_ << " Copy constructor called" << std::endl;
	this->name_ = src.name_;
	this->hit_point_ = src.hit_point_;
	this->energy_point_ = src.energy_point_;
	this->attack_damage_ = src.attack_damage_;
}

ScavTrap::~ScavTrap() {
	std::cout << "name: " << this->name_ << " Destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &src) {
	std::cout << "ScavTrap " << src.name_ << " Copy assignment operator called" << std::endl;
	this->name_ = src.name_;
	this->hit_point_ = src.hit_point_;
	this->energy_point_ = src.energy_point_;
	this->attack_damage_ = src.attack_damage_;
	return *this;
}

void ScavTrap::attack(const std::string &target) {
	std::cout <<
	"ScavTrap " << name_ <<
	" attacks " << target <<
	" causing " << attack_damage_ <<
	" points of damage!"
	<< std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << name_ << " is now in Gate keeper mode" << std::endl;
}