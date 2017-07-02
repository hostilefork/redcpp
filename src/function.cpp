//
// function.cpp
// This file is part of RenCpp
// Copyright (C) 2015-2017 HostileFork.com
//
// Licensed under the Boost License, Version 1.0 (the "License")
//
//      http://www.boost.org/LICENSE_1_0.txt
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
// implied.  See the License for the specific language governing
// permissions and limitations under the License..
//
// See http://rencpp.hostilefork.com for more information on this project
//

#include "rencpp/value.hpp"
#include "rencpp/function.hpp"

namespace ren {

#ifdef REN_RUNTIME

namespace internal {
    std::mutex keepaliveMutex;
}

#endif

}
