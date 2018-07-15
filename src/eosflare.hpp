//
//  eostracker.hpp
//  eos-transaction-memos
//
//  Created by Jeffrey Tai on 7/14/18.
//  Copyright © 2018 Jeffrey Tai. All rights reserved.
//

#ifndef eosflare_hpp
#define eosflare_hpp

#include <string>
#include <unordered_set>

class EosFlare {
public:
    std::unordered_set<std::string> check_transaction(std::string transactionId);
private:
    std::unordered_set<std::string> extract_memos(std::string contents);
};

#endif /* eosflare_hpp */
