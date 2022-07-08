#include <bits/stdc++.h>
class Solution {
public:
    #define uset unordered_set
    int numUniqueEmails(vector<string>& emails) {
        uset<string> mail;
        for(auto email : emails)
        {
            cout<<"email : "<<email<<endl;
            // ltrim(email); rtrim(email);
            string username = email.substr(0, email.find("@"));
            cout<<"username : "<<username<<endl;
            // process the username
            username = username.substr(0, username.find("+"));
            cout<<"valid part of username : "<<username<<endl;
            char dot = '.';
            username.erase(remove(username.begin(), username.end(), dot), username.end());
            cout<<"res username : "<<username<<endl;
            // process the domain
            string domain = email.substr(email.find("@"), email.size() - email.find("@"));
            
            mail.insert(username + "@" + domain);
        }
        return mail.size();
    }
};