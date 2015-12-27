//
// runtime.cpp
// This file is part of RenCpp
// Copyright (C) 2015 HostileFork.com
//
// Licensed under the Boost License, Version 1.0 (the "License")
//
//      http://www.boost.org/LICENSE_1_0.txt
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
// implied.  See the License for the specific language governing
// permissions and limitations under the License.
//
// See http://rencpp.hostilefork.com for more information on this project
//

#include "rencpp/runtime.hpp"
#include "rencpp/context.hpp"


namespace ren {

optional<AnyValue> Runtime::evaluate(
    internal::Loadable const loadables[],
    size_t numLoadables,
    AnyContext const * contextPtr,
    Engine * engine
) {
    AnyValue result (AnyValue::Dont::Initialize);

    AnyContext context = contextPtr
        ? *contextPtr
        : AnyContext::current(engine);

    if (AnyValue::constructOrApplyInitialize(
        context.getEngine(),
        &context,
        nullptr, // no applicand
        loadables,
        numLoadables,
        nullptr, // don't construct
        &result // do apply
    )) {
        return result;
    }

    return nullopt;
}

}
