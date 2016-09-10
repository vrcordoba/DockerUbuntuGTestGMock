#ifndef CHAT_USERMOCK_H_
#define CHAT_USERMOCK_H_

#include <string>
#include "gmock/gmock.h"
#include "User.h"

class UserMock final : public User
{
public:
   MOCK_CONST_METHOD0(getName, std::string());
   MOCK_CONST_METHOD3(onMessage, void(const std::string&, const std::string&,
      const std::string&));
   MOCK_CONST_METHOD2(newUserInChat, void(const std::string&,
      const std::string&));
   MOCK_CONST_METHOD2(userExitedFromChat, void(const std::string&,
      const std::string&));
};

#endif
