// =================================================================
//
// File: test1.cpp
// Author: Pedro Perez
// Description: This file contains the test cases for the functions
//				of this activity have to pass. IMPORTANT: this file
//				should not be modified.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.h"
#include "activity.h"

TEST_CASE( "Testing sumaIterativa", "[sumaIterativa]" ) {
	REQUIRE(sumaIterativa(1) == 1);
	REQUIRE(sumaIterativa(10) == 55);
	REQUIRE(sumaIterativa(50) == 1275);
	REQUIRE(sumaIterativa(100) == 5050);
	REQUIRE(sumaIterativa(500) == 125250);
}

TEST_CASE( "Testing sumaRecursiva", "[sumaRecursiva]" ) {
	REQUIRE(sumaRecursiva(1) == 1);
	REQUIRE(sumaRecursiva(10) == 55);
	REQUIRE(sumaRecursiva(50) == 1275);
	REQUIRE(sumaRecursiva(100) == 5050);
	REQUIRE(sumaRecursiva(500) == 125250);
}

TEST_CASE( "Testing sumaDirecta", "[sumaDirecta]" ) {
	REQUIRE(sumaDirecta(1) == 1);
	REQUIRE(sumaDirecta(10) == 55);
	REQUIRE(sumaDirecta(50) == 1275);
	REQUIRE(sumaDirecta(100) == 5050);
	REQUIRE(sumaDirecta(500) == 125250);
}
