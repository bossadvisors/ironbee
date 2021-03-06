/*****************************************************************************
 * Licensed to Qualys, Inc. (QUALYS) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * QUALYS licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ****************************************************************************/

/**
 * @file
 * @brief IronBee --- CLIPP PB Generator.
 *
 * @author Christopher Alfeld <calfeld@qualys.com>
 */

#ifndef __IRONBEE__CLIPP__BURPGENERATOR__
#define __IRONBEE__CLIPP__BURPGENERATOR__

#include <clipp/input.hpp>

#include <boost/shared_ptr.hpp>

namespace IronBee {
namespace CLIPP {

/**
 * Generator that reads from burp xml files..
 **/
class BurpGenerator
{
public:
    //! Default Constructor.
    BurpGenerator();

    /**
     * Construct pointing at a particular XML file.
     *
     * @param[in] path Path to a Burp Proxy XML file.
     */
    explicit
    BurpGenerator(const std::string& path);

    /**
     * Produce an input.
     *
     * @param[in] out_input The output object to populate with events.
     *
     * @returns True if output was generated. False if no output
     * was generated and no output remains.
     *
     * @see input_t and input_generator_t.
     */
    bool operator()(Input::input_p& out_input);

private:
    struct State;
    boost::shared_ptr<State> m_state;
};

} // CLIPP
} // IronBee

#endif
