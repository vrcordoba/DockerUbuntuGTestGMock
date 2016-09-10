#ifndef CHAT_MEDIASERVER_H_
#define CHAT_MEDIASERVER_H_

class MediaServer
{
public:
   virtual ~MediaServer() {};

   virtual bool allowMoreUsers() = 0;
   virtual void addUser() = 0;
   virtual void removeUser() = 0;
};

#endif
