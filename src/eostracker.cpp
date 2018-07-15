//
//  eostracker.cpp
//  eos-transaction-memos
//
//  Created by Jeffrey Tai on 7/12/18.
//  Copyright © 2018 Jeffrey Tai. All rights reserved.
//

#include "eostracker.hpp"
#include "utils.hpp"

#include <json/json.h>
#include <iostream>
#include <sstream>

std::unordered_set<std::string> EosTracker::get_transaction_list() {
    std::unordered_set<std::string> transactionCollection;

    int page = 1;
    while (true) {
        std::ostringstream urlBuilder;
        urlBuilder << "https://api.eostracker.io/transactions?page=" << page++ << "&size=1000";
        std::string url = urlBuilder.str();

        printf("Extracting transactions from %s\n", url.c_str());
        std::string contents = Utils::html_contents(url.c_str());
        std::unordered_set<std::string> batch = extract_transactions(contents);

        if (batch.empty()) {
            break;
        }
        transactionCollection.insert(batch.begin(), batch.end());

        break;
    }
    
    return transactionCollection;
}

std::unordered_set<std::string> EosTracker::extract_transactions(std::string contents) {
    std::unordered_set<std::string> transactions;

    Json::StreamWriterBuilder writer;
    Json::Value root = Utils::get_root_node(contents);
    
    if (!root.empty()) {
        for (Json::Value::ArrayIndex i=0; i != root.size(); ++i) {
            Json::Value transactionId = root[i]["id"];
            std::string unsanitizedTransactionId = Json::writeString(writer, transactionId);
            transactions.insert(unsanitizedTransactionId.substr(1, unsanitizedTransactionId.size() - 2));
        }
    } else {
        printf("Couldn't parse JSON");
    }

    return transactions;
}