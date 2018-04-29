/*
 * Copyright (c) 2017-2018 Snowflake Computing, Inc. All rights reserved.
 */

#ifndef SNOWFLAKECLIENT_PARAM_HPP
#define SNOWFLAKECLIENT_PARAM_HPP

#include "client.h"

namespace Snowflake {
    namespace Client {
        class Param {
        public:
            Param();

            ~Param();

            size_t len();

            void set_len(size_t len_);

            SF_DB_TYPE dbDataType();

            void set_dbDataType(SF_DB_TYPE type_);

            SF_C_TYPE cDataType();

            void set_cDataType(SF_C_TYPE type_);

            void* value();
            
            void set_value(void *value_, SF_C_TYPE type_);

        private:
            SF_BIND_INPUT m_param;
        };
    }
}

#endif //SNOWFLAKECLIENT_PARAM_HPP