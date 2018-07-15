//
//  eostracker.hpp
//  eos-transaction-memos
//
//  Created by Jeffrey Tai on 7/14/18.
//  Copyright © 2018 Jeffrey Tai. All rights reserved.
//

#ifndef eosflare_hpp
#define eosflare_hpp

#include <list>
#include <string>
#include <unordered_map>

class EosFlare {
public:
    std::unordered_map<std::string, int> transaction_info(std::list<std::string> transactionId);
private:
    void extract_memos(std::string contents, std::unordered_map<std::string, int>& memoCount);
};

#endif /* eosflare_hpp */
