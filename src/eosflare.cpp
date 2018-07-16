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

std::unordered_map<std::string, int> EosFlare::transaction_info(std::list<std::string> transactionIds) {
    std::unordered_map<std::string, int> totalMemoCount;

    int count = 0;
    for (std::string transactionId : transactionIds) {
        // TODO: Maybe cycle between a couple API endpoints in case of rate limiting
        std::string url = "http://api.eosnewyork.io/v1/history/get_transaction";

        std::ostringstream postfieldsBuilder;
        postfieldsBuilder << "{\"id\": \"" << transactionId << "\", \"json\": \"true\"}";
        std::string postfields = postfieldsBuilder.str();

        printf("Extracting memos for transaction %s\n", transactionId.c_str());
        std::string response = Utils::http_response(url.c_str(), postfields.c_str());
        try {
            extract_memos(response, totalMemoCount);
        } catch (Json::LogicError e) {
            printf("Skipping transaction %s\n", transactionId.c_str());
            continue;
        }
        
        printf("Current number of distinct memos: %lu\n", totalMemoCount.size());
        printf("Processed %d transactions\n", ++count);

        if (count % 5 == 0) {
            for (auto elem : totalMemoCount) {
                std::cout << elem.first << ": " << elem.second << std::endl;
            }
        }
    }

    return totalMemoCount;
}

void EosFlare::extract_memos(std::string contents, std::unordered_map<std::string, int>& memoCount) {

    Json::StreamWriterBuilder writer;
    Json::Value root = Utils::get_root_node(contents);

    if (!root.empty()) {
        Json::Value actions = root["trx"]["trx"]["actions"];

        for (Json::Value::ArrayIndex i=0; i != actions.size(); ++i) {
            Json::Value memo = actions[i]["data"];
            if (memo.isMember("memo")) {
                std::string unsanitizedMessage = Json::writeString(writer, memo["memo"]);
                std::string message = unsanitizedMessage.substr(1, unsanitizedMessage.size() - 2);

                int& count = memoCount[message];
                if (count) ++count;
                else count = 1;
            }
        }
    }
}