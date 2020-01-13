#pragma once
#include <string>


class Account {
private:
	unsigned int ID;
	std::string name;
	std::string familyName;

public:
	static unsigned int key;

	Account(std::string const name, std::string const familyName) : name(name), familyName(familyName), ID(++key) {}

	unsigned int getID() const {
		return ID;
	}

	std::string getName() const {
		return name;
	}

	std::string getFamilyName() const {
		return familyName;
	}

	std::string to_string() const {
		return name + " " + familyName;
	}

	bool operator<(Account const & other) const { // for set
		return to_string() < other.to_string();
	}

	bool operator==(const Account& other) const // for unordered_map
	{
		return (ID == other.ID
			&& name == other.name
			&& familyName == other.familyName);
	}

};

unsigned int Account::key = 0;


template <>
struct std::hash<Account> {
	typedef size_t result_type;
	typedef Account argument_type;
	result_type operator()(argument_type x) const {
		return static_cast<result_type>(x.getID());
	}
};