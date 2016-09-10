#ifndef CHAT_MEDIASERVERMOCK_H_
#define CHAT_MEDIASERVERMOCK_H_

#include "gmock/gmock.h"
#include "MediaServer.h"

class MediaServerMock final : public MediaServer
{
public:
   MOCK_METHOD0(allowMoreUsers, bool());
   MOCK_METHOD0(addUser, void());
   MOCK_METHOD0(removeUser, void());
};

#endif
