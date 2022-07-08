#include <bits/stdc++.h>
class Solution {
public:
    #define uset unordered_set
    int numUniqueEmails(vector<string>& emails) {
        uset<string> mail;
        for(auto email : emails)
        {

            // process the username
            /*get username*/string username = email.substr(0, email.find("@"));
            /*remove everything after '+'*/username = username.substr(0, username.find("+"));
            // remove all the '.'s
            char dot = '.';
            username.erase(remove(username.begin(), username.end(), dot), username.end());
            
            // process the domain
            // get the domain
            string domain = email.substr(email.find("@"), email.size() - email.find("@"));
            
            // insert the processed email into the set
            mail.insert(username + "@" + domain);
        }
        return mail.size();
    }
};