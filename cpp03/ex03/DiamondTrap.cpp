//
// Created by 本間優之介 on 2023/02/17.
//

#include "DiamondTrap.h"

// private に書いてるから呼ばれない
//DiamondTrap::DiamondTrap() {
//
//}

// 基底クラスのコンストラクタが呼ばれる順番は自分が書いた順番ではなく継承してる順番
// cmakeは怒るのかも
DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name_(name) {
	std::cout << "DiamondTrap " << name_ << " was born" << std::endl;
	this->hit_point_ = init_hp;
	this->energy_point_ = init_ep;
	this->attack_damage_ = init_ad;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src): ClapTrap(src), FragTrap(src), ScavTrap(src), name_(src.name_){
	std::cout << "DiamondTrap " << name_ << " was copied" << std::endl;
	this->hit_point_ = src.hit_point_;
	this->energy_point_ = src.energy_point_;
	this->attack_damage_ = src.attack_damage_;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << name_ << " GoodBye (T^T)ゞ" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &src) {
	this->name_ = src.name_;
	this->hit_point_ = src.hit_point_;
	this->energy_point_ = src.energy_point_;
	this->attack_damage_ = src.attack_damage_;
	return *this;
}

void DiamondTrap::attack(const std::string &target) {
	this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "I am Diamond " << name_ << " ヽ(`Д´)ノ" << std::endl;
	std::cout << "Also known as ClapTrap " << ClapTrap::name_ << " 三└(┐卍^o^)卍" << std::endl;
}