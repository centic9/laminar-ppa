///
/// Copyright 2019 Oliver Giles
///
/// This file is part of Laminar
///
/// Laminar is free software: you can redistribute it and/or modify
/// it under the terms of the GNU General Public License as published by
/// the Free Software Foundation, either version 3 of the License, or
/// (at your option) any later version.
///
/// Laminar is distributed in the hope that it will be useful,
/// but WITHOUT ANY WARRANTY; without even the implied warranty of
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
/// GNU General Public License for more details.
///
/// You should have received a copy of the GNU General Public License
/// along with Laminar.  If not, see <http://www.gnu.org/licenses/>
///
#include <kj/async-unix.h>
#include <gtest/gtest.h>
#include <kj/debug.h>

#include "laminar-fixture.h"
#include "leader.h"

// gtest main supplied in order to call captureChildExit and handle process leader
int main(int argc, char **argv) {
    if(argv[0][0] == '{')
        return leader_main();

    // TODO: consider handling this differently
    auto ioContext = kj::setupAsyncIo();
    LaminarFixture::ioContext = &ioContext;

    kj::UnixEventPort::captureChildExit();
    //kj::_::Debug::setLogLevel(kj::_::Debug::Severity::INFO);

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
