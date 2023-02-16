//
// Created by 本間優之介 on 2023/02/15.
//

#include "ClapTrap.h"

// John Doe -> 英語圏だと名無しの権兵衛らしい
ClapTrap::ClapTrap():name_("John Doe"), hit_point_(init_hp) ,energy_point_(init_ep), attack_damage_(init_ad) {
	std::cout << "ClapTrap " << "name entry incomplete -> set \"John Doe\"" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name):name_(name), hit_point_(init_hp) ,energy_point_(init_ep), attack_damage_(init_ad) {
	std::cout << "ClapTrap " << "name: " << name << " entry complete" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src) {
	std::cout << "ClapTrap " << "name: " << src.name_ << " Copy constructor called" << std::endl;
	this->name_ = src.name_;
	this->hit_point_ = src.hit_point_;
	this->energy_point_ = src.energy_point_;
	this->attack_damage_ = src.attack_damage_;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name_ << "'s " << "Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& source) {
	std::cout << "ClapTrap " << "Copy assignment operator called" << std::endl;
	this->name_ = source.name_;
	this->hit_point_ = source.hit_point_;
	this->energy_point_ = source.energy_point_;
	this->attack_damage_ = source.attack_damage_;
	return *this;
}

void ClapTrap::attack(const std::string &target) {
	std::cout <<
	"ClapTrap " << name_ <<
	" attacks " << target <<
	" causing " << attack_damage_ <<
	" points of damage!"
	<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hit_point_ == 0) {
		std::cout <<
		"ClapTrap " << name_ <<
		" is already broken..."
		<< std::endl;
	} else if (hit_point_ < amount) {
		std::cout <<
		"ClapTrap " << name_ <<
		" took " << amount << " damage!" <<
		" Overkilled! ｡ ﾟ( ﾟஇωஇﾟ)ﾟ｡"
		<< std::endl;
		hit_point_ = 0;
	} else if (hit_point_ == amount){
		std::cout <<
		"ClapTrap " << name_ <<
		" took " << amount << " damage!" <<
		" It's just broken..."
		<< std::endl;
		hit_point_ = 0;
	} else {
		std::cout <<
		"ClapTrap " << name_ <<
		" took " << amount << " damage!"
		<< std::endl;
		hit_point_ -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energy_point_ == 0) {
		std::cout << "ClapTrap " << "Energy Point is not enough orz" << std::endl;
	} else if (hit_point_ == 0) {
		std::cout << "ClapTrap " << "No HP anymore, cannot repair..." << std::endl;
	} else if (amount == 0) {
		std::cout << "ClapTrap " << "Invalid repair order" << std::endl;
	} else {
		energy_point_ -= 1;
		hit_point_ += amount;
		std::cout << "ClapTrap " << name_ <<
		" repaired " << amount << " HP! ٩( ᐛ )و"
		<< std::endl;
	}
}

const std::string& ClapTrap::get_name() const {
	return this->name_;
}

unsigned int ClapTrap::get_hit_point() const {
	return this->hit_point_;
}

unsigned int ClapTrap::get_energy_point() const {
	return this->energy_point_;
}

unsigned int ClapTrap::get_attack_damage() const {
	return this->attack_damage_;
}