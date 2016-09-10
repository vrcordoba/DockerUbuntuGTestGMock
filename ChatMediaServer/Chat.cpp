
#include "Chat.h"
#include "MediaServer.h"
#include "NotEnoughResourcesException.h"

Chat::Chat(const std::string& name, MediaServer* mediaServer) : nameM(name), mediaServerM(mediaServer),
   userCompM([] (const User* lhs, const User* rhs) {return lhs->getName() < rhs->getName();}),
   usersM(userCompM)
{
}

Chat::~Chat()
{
}

void Chat::addUser(User& user)
{
   if (not mediaServerM->allowMoreUsers())
      throw NotEnoughResourcesException();
   for (auto chatUser : usersM)
   {
      chatUser->newUserInChat(nameM, user.getName());
   }
   usersM.insert(&user);
   mediaServerM->addUser();
}

void Chat::removeUser(User& user)
{
   usersM.erase(&user);
   mediaServerM->removeUser();
   for (auto chatUser : usersM)
   {
      chatUser->userExitedFromChat(nameM, user.getName());
   }
}

void Chat::sendMessage(const User& user, const std::string& message) const
{
   for (auto chatUser : usersM)
   {
      if (user.getName() != chatUser->getName())
      {
         chatUser->onMessage(nameM, user.getName(), message);
      }
   }
}
