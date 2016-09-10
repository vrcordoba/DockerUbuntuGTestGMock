#ifndef CHAT_CHAT_H_
#define CHAT_CHAT_H_

class MediaServer;

#include <string>
#include <functional>
#include <set>
#include "User.h"

class Chat final
{
public:
   Chat(const std::string& name, MediaServer* mediaServer);
   ~Chat();

   void addUser(User& user);
   void removeUser(User& user);
   void sendMessage(const User& user, const std::string& message) const;

private:
   const std::string nameM;
   MediaServer* mediaServerM;
   std::function<bool(const User* lhs, const User* rhs)> userCompM;
   std::set<User*, decltype(userCompM)> usersM;
};

#endif
