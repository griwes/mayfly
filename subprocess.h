/**
 * Mayfly License
 *
 * Copyright © 2014 Michał "Griwes" Dominiak
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation is required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 **/

#pragma once

#include <boost/algorithm/string.hpp>

#include "testcase.h"
#include "suite.h"
#include "reporter.h"

namespace reaver
{
    namespace mayfly { inline namespace _v1
    {
        class subprocess_reporter : public reporter
        {
        public:
            virtual void suite_started(const suite & s) const override
            {
            }

            virtual void suite_finished(const suite & s) const override
            {
            }

            virtual void test_started(const testcase & t) const override
            {
            }

            virtual void test_finished(const testcase_result & result) const override
            {
                std::cout << static_cast<std::uintmax_t>(result.status) << ' ' << result.description << std::flush;
            }

            virtual void summary(const std::vector<std::pair<testcase_status, std::string>> & summary, std::uintmax_t passed, std::uintmax_t total) const override
            {
                if (!total)
                {
                    std::cout << static_cast<std::uintmax_t>(testcase_status::not_found) << std::flush;
                }
            }
        };

        MAYFLY_REPORTER_REGISTER("subprocess", subprocess_reporter)
    }}
}