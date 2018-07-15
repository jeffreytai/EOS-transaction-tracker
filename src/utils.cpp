//
//  utils.cpp
//  eos-transaction-memos
//
//  Created by Jeffrey Tai on 7/12/18.
//  Copyright © 2018 Jeffrey Tai. All rights reserved.
//

#include "utils.hpp"

#include <curl/curl.h>
#include <iostream>
#include <string>

static size_t write_callback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size* nmemb);
    return size * nmemb;
}

std::string Utils::html_contents(const char* url) {
    CURL *curl;
    CURLcode response;
    std::string readBuffer;
    
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        response = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    else {
        printf("Unable to read from %s", url);
    }
    
    return readBuffer;
}

Json::Value Utils::get_root_node(std::string contents) {
    Json::CharReaderBuilder builder;
    Json::CharReader* reader = builder.newCharReader();
    Json::Value root;
    std::string errors;

    bool parseSuccess = reader->parse(contents.c_str(), contents.c_str() + contents.size(), &root, &errors);

    if (parseSuccess) {
        return root;
    }

    return nullptr;
}
