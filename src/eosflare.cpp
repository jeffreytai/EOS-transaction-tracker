//
//  eostracker.hpp
//  eos-transaction-memos
//
//  Created by Jeffrey Tai on 7/14/18.
//  Copyright © 2018 Jeffrey Tai. All rights reserved.
//

#include "eosflare.hpp"
#include "utils.hpp"

#include <json/json.h>
#include <iostream>
#include <sstream>

std::unordered_set<std::string> EosFlare::check_transaction(std::string transactionId) {
    std::unordered_set<std::string> memoCollection;

    std::ostringstream urlBuilder;
    urlBuilder << "https://eosflare.io/tx/" << transactionId;
    std::string url = urlBuilder.str();

    printf("Extracting memos from %s\n", url.c_str());
    std::string contents = Utils::html_contents(url.c_str());
    extract_memos(contents);

    return memoCollection;
}

std::unordered_set<std::string> EosFlare::extract_memos(std::string contents) {
    std::unordered_set<std::string> memos;

    Json::StreamWriterBuilder writer;
    std::cout << contents << std::endl;
    
    // TODO: Collect memos from transactions

    return memos;
}