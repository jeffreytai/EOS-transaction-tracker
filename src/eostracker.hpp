//
//  eostracker.hpp
//  eos-transaction-memos
//
//  Created by Jeffrey Tai on 7/12/18.
//  Copyright © 2018 Jeffrey Tai. All rights reserved.
//

#ifndef eostracker_hpp
#define eostracker_hpp

#include <unordered_set>
#include <stdio.h>
#include <string>

class EosTracker {
public:
    std::unordered_set<std::string> get_transaction_list(int limit = 0);
    
private:
    std::unordered_set<std::string> extract_transactions(std::string);
};

#endif /* eostracker_hpp */
