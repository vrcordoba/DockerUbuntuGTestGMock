#ifndef CHAT_USER_H_
#define CHAT_USER_H_

#include <string>

class User
{
public:
   virtual ~User() {};

   virtual std::string getName() const = 0;
   virtual void onMessage(const std::string& chat, const std::string& user,
      const std::string& message) const = 0;
   virtual void newUserInChat(const std::string& chat,
      const std::string& user) const = 0;
   virtual void userExitedFromChat(const std::string& chat,
      const std::string& user) const = 0;
};

#endif
