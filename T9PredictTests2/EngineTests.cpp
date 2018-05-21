#include "stdafx.h"

#define CATCH_CONFIG_MAIN

#include "Catch.h"

#include "../T9Predict2/Engine.h"

TEST_CASE("Called with word encoding and word is know return word")
{
	Engine t9engine;

	Digits digits;

	auto result = t9engine.GetWordsByDigits(digits);
	SECTION("Called with empty digit list --> returns no results", "[Init][Empty]")
	{
		REQUIRE(result.size() == 0);
	}

	SECTION("When called with 43556 and known word then return hello", "[Search][End2End]")
	{
		t9engine.LearnNewWords({ "hello" });

		digits = { 4,3,5,5,6 };

		result = t9engine.GetWordsByDigits(digits);

		REQUIRE(result.size() == 1);
		REQUIRE(result[0] == "hello");
	}

	SECTION("When called with 4663 and known words then return these words", "[Search][multiple words][End2End]")
	{
		t9engine.LearnNewWords({ "good", "gone", "home" });

		digits = { 4, 6, 6, 3 };

		result = t9engine.GetWordsByDigits(digits);

		REQUIRE(result.size() == 3);
		REQUIRE(std::find(result.begin(), result.end(), "good") != result.end());
		REQUIRE(std::find(result.begin(), result.end(), "gone") != result.end());
		REQUIRE(std::find(result.begin(), result.end(), "home") != result.end());

		SECTION("When called with 4663 and known words but other words exist then return only these words", "[Search][multiple words][End2End]")
		{
			t9engine.LearnNewWords({ "hello", "bug", "trail" });

			auto result = t9engine.GetWordsByDigits(digits);

			REQUIRE(result.size() == 3);
			REQUIRE(std::find(result.begin(), result.end(), "good") != result.end());
			REQUIRE(std::find(result.begin(), result.end(), "gone") != result.end());
			REQUIRE(std::find(result.begin(), result.end(), "home") != result.end());
		}
	}
}