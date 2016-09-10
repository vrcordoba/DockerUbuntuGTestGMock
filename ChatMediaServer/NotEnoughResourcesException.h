#ifndef CHAT_NOTENOUGHRESOURCESEXCEPTION_H_
#define CHAT_NOTENOUGHRESOURCESEXCEPTION_H_

#include <exception>

class NotEnoughResourcesException : public std::exception
{
   virtual const char* what() const throw()
   {
      return "Not enough resources";
   }
};

#endif
