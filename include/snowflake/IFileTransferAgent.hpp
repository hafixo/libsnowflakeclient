/*
 * Copyright (c) 2018-2019 Snowflake Computing, Inc. All rights reserved.
 */

#ifndef SNOWFLAKECLIENT_IFILETRANSFERAGENT_HPP
#define SNOWFLAKECLIENT_IFILETRANSFERAGENT_HPP

#include "ITransferResult.hpp"
#include "ISFLogger.hpp"
#include "IStatementPutGet.hpp"

namespace Snowflake
{
namespace Client
{

/**
 * Config struct that is passed from external component
 */
struct TransferConfig
{
  char * caBundleFile;
};

class IFileTransferAgent
{
public:
  virtual ~IFileTransferAgent() {};
  /**
   * Called by external component to execute put/get command
   * @param command put/get command
   * @return a fixed view result set representing upload/download result
   */
  virtual ITransferResult *execute(std::string *command) = 0;

  /**
  * Set upload stream to enable upload file from stream in memory.
  * @param uploadStream The stream to be uploaded.
  * @param dataSize The data size of the stream.
  */
  virtual void setUploadStream(std::basic_iostream<char>* uploadStream,
                               size_t dataSize) = 0;
  /**
   * Static method to instantiate a IFileTransferAgent class
   * @return a newly allocated IFileTransferAgent, caller need to delete instance
   */
  static IFileTransferAgent *getTransferAgent(
    IStatementPutGet * statementPutGet,
    TransferConfig * transferConfig);


  /**
   * Used by ODBC to inject logger. If this method is not called, default logger
   * will be used.
   */
  static void injectExternalLogger(ISFLogger * logger);
};

}
}
#endif //SNOWFLAKECLIENT_IFILETRANSFERAGENT_HPP
