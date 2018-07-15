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
    // std::unordered_set<std::string> transactions = tracker->get_transaction_list();

    // delete tracker;

    EosFlare *flare = new EosFlare();
    flare->check_transaction("a1509de7e1867804e3aa573355636c34cd3cf51728256651f771e69497e7e158");
    
    delete flare;
}
