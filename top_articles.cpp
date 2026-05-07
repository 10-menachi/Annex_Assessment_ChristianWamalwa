#define CPPHTTPLIB_OPENSSL_SUPPORT

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "httplib.h"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

vector<string> topArticles(int limit)
{
    httplib::SSLClient cli("jsonmock.hackerrank.com");

    vector<pair<int, string>> articles;

    int current_page = 1;
    int total_pages = 1;

    while (current_page <= total_pages)
    {
        string endpoint =
            "/api/articles?page=" + to_string(current_page);

        auto res = cli.Get(endpoint.c_str());

        if (res && res->status == 200)
        {
            json response = json::parse(res->body);

            total_pages = response["total_pages"];

            for (const auto &item : response["data"])
            {
                string name = "";

                if (!item["title"].is_null())
                {
                    name = item["title"];
                }
                else if (!item["story_title"].is_null())
                {
                    name = item["story_title"];
                }
                else
                {
                    continue;
                }

                int comments = 0;

                if (!item["num_comments"].is_null())
                {
                    comments = item["num_comments"];
                }

                articles.push_back({comments, name});
            }
        }

        current_page++;
    }

    sort(
        articles.begin(),
        articles.end(),
        [](const pair<int, string> &a,
           const pair<int, string> &b)
        {
            if (a.first != b.first)
                return a.first > b.first;

            return a.second > b.second;
        });

    vector<string> result;

    for (int i = 0;
         i < limit && i < articles.size();
         i++)
    {
        result.push_back(articles[i].second);
    }

    return result;
}

int main()
{
    vector<string> result = topArticles(5);

    for (const auto &article : result)
    {
        cout << article << endl;
    }

    return 0;
}