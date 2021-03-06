// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <iostream>
#include <string>
using namespace std;

#include <boost/program_options.hpp>
namespace po = boost::program_options;

#include <boost/any.hpp>
using namespace boost;

#include <boost/signals2.hpp>
using namespace boost::signals2;

#include <boost/filesystem.hpp>
using namespace boost::filesystem;

#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/trim_all.hpp>
#include <boost/bimap.hpp>
#include <boost/units/unit.hpp>
#include <boost/units/systems/si.hpp>
#include <boost/units/systems/si/prefixes.hpp>
using namespace boost::algorithm;
using namespace boost::units;
using namespace boost::units::si;
//#define BOOST_ALL_DYN_LINK


// TODO: reference additional headers your program requires here
