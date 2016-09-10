
#include "Chat.h"
#include "UserMock.h"
#include "MediaServerMock.h"
#include "NotEnoughResourcesException.h"
#include "gmock/gmock.h"

TEST(ChatMediaServerTest, newUserInChatEnoughResources)
{
   MediaServerMock mediaServer;
   Chat chat("Test chat", &mediaServer);
   UserMock user;

   EXPECT_CALL(mediaServer, allowMoreUsers()).WillOnce(::testing::Return(true));

   EXPECT_CALL(mediaServer, addUser()).Times(1);

   EXPECT_NO_THROW(chat.addUser(user));
}

TEST(ChatMediaServerTest, newUserInChatNotEnoughResources)
{
   MediaServerMock mediaServer;
   Chat chat("Test chat", &mediaServer);
   UserMock user;

   EXPECT_CALL(mediaServer, allowMoreUsers()).WillOnce(::testing::Return(false));

   EXPECT_CALL(mediaServer, addUser()).Times(0);

   EXPECT_THROW(chat.addUser(user), NotEnoughResourcesException);
}

TEST(ChatMediaServerTest, newUserInChatReachingResourceLimit)
{
   MediaServerMock mediaServer;
   Chat chat("Test chat", &mediaServer);
   UserMock user1, user2;

   EXPECT_CALL(mediaServer, allowMoreUsers())
      .WillOnce(::testing::Return(true))
      .WillOnce(::testing::Return(false));

   EXPECT_CALL(mediaServer, addUser()).Times(1);
   EXPECT_NO_THROW(chat.addUser(user1));
   EXPECT_THROW(chat.addUser(user2), NotEnoughResourcesException);
}

TEST(ChatMediaServerTest, userLeaveChat)
{
   MediaServerMock mediaServer;
   Chat chat("Test chat", &mediaServer);
   UserMock user;

   EXPECT_CALL(user, getName()).WillRepeatedly(::testing::Return("Juan"));
   EXPECT_CALL(mediaServer, allowMoreUsers()).WillOnce(::testing::Return(true));

   EXPECT_CALL(mediaServer, addUser()).Times(1);
   EXPECT_CALL(mediaServer, removeUser()).Times(1);

   chat.addUser(user);
   chat.removeUser(user);
}

