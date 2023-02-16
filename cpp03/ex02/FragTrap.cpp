//
// Created by 本間優之介 on 2023/02/17.
//

#include "FragTrap.h"

FragTrap::FragTrap(): ClapTrap() {
	std::cout << "FragTrap " << name_ << " Default Constructor called" << std::endl;
	this->hit_point_ = init_hp;
	this->energy_point_ = init_ep;
	this->attack_damage_ = init_ad;
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name) {
	std::cout << "FragTrap " << this->name_ << " Default Constructor called" << std::endl;
	this->name_ = name;
	this->hit_point_ = init_hp;
	this->energy_point_ = init_ep;
	this->attack_damage_ = init_ad;
}

FragTrap::FragTrap(const FragTrap &src) {
	std::cout << "FragTrap " << "name: " << src.name_ << " Copy constructor called" << std::endl;
	this->name_ = src.name_;
	this->hit_point_ = src.hit_point_;
	this->energy_point_ = src.energy_point_;
	this->attack_damage_ = src.attack_damage_;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << "name: " << this->name_ << " Destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &src) {
	std::cout << "FragTrap " << src.name_ << " Copy assignment operator called" << std::endl;
	this->name_ = src.name_;
	this->hit_point_ = src.hit_point_;
	this->energy_point_ = src.energy_point_;
	this->attack_damage_ = src.attack_damage_;
	return *this;
}

void FragTrap::attack(const std::string &target) {
	std::cout <<
			  "FragTrap " << name_ <<
			  " attacks " << target <<
			  " causing " << attack_damage_ <<
			  " points of damage!"
			  << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << "Let's high five, guys!" << std::endl;
}