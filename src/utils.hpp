//
//  utils.hpp
//  eos-transaction-memos
//
//  Created by Jeffrey Tai on 7/12/18.
//  Copyright © 2018 Jeffrey Tai. All rights reserved.
//

#ifndef utils_hpp
#define utils_hpp

#include <stdio.h>
#include <string>
#include <json/json.h>

class Utils {
public:
    static std::string html_contents(const char* url);
    static Json::Value get_root_node(std::string contents);
};

#endif /* utils_hpp */
