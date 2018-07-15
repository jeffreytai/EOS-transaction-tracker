//
//  main.cpp
//  eos-transaction-memos
//
//  Created by Jeffrey Tai on 7/12/18.
//  Copyright © 2018 Jeffrey Tai. All rights reserved.
//

#include "eostracker.hpp"
#include "eosflare.hpp"

#include <iostream>

int main(int argc, const char * argv[]) {
    // EosTracker *tracker = new EosTracker();
    // std::unordered_set<std::string> transactions = tracker->get_transaction_list(10);
    
    EosFlare *flare = new EosFlare();
    // flare->transaction_info(std::list<std::string> (std::begin(transactions), std::end(transactions)));
    flare->transaction_info(std::list<std::string> {"c8657eacb5f3a2f6246909d12828fb90cbbf232b320ae0ec095be4eed3cfc6dc"});
    
    delete flare;
    // delete tracker;
}
