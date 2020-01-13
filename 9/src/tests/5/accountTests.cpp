#include <gtest/gtest.h>
#include "../../9/5/account.h"
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>


TEST(Account, map) {
	Account first("Ivan", "Ivanov");
	Account second("Petr", "Petrov");
	std::map<Account, int> map;
	map[first] = 10;
	map[second] = 20;

	EXPECT_EQ(map.at(first), 10);
	EXPECT_EQ(map.at(second), 20);
}

TEST(Account, unordered_map) {
	Account first("Ivan", "Ivanov");
	Account second("Petr", "Petrov");
	std::unordered_map<Account, int> umap;
	umap[first] = 10;
	umap[second] = 20;

	EXPECT_EQ(umap.at(first), 10);
	EXPECT_EQ(umap.at(second), 20);
}

TEST(Account, set) {
	Account first("Ivan", "Ivanov");
	Account second("Petr", "Petrov");
	std::set<Account> set;
	set.insert(first);
	set.insert(second);

	EXPECT_TRUE(*set.find(first) == first);
	EXPECT_TRUE(*set.find(second) == second);
}

TEST(Account, unordered_set) {
	Account first("Ivan", "Ivanov");
	Account second("Petr", "Petrov");
	std::unordered_set<Account> uset;
	uset.insert(first);
	uset.insert(second);

	EXPECT_TRUE(*uset.find(first) == first);
	EXPECT_TRUE(*uset.find(second) == second);
}
