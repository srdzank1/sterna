#include "Log.h"

Log* Log::pInstance = NULL;

Log* Log::Inst(char* filename){
  if(pInstance == NULL)
  {
    pInstance = new Log(filename);
  }
  return pInstance;
}

Log::Log(){ // constructor
  Initialize(); // you can ignore this function
}
