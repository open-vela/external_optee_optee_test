/*
 * Copyright (C) 2023 Xiaomi Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <user_ta_wasm_header.h>
#include "./ta_entry.c"

struct user_ta_head storage_user_ta_head = {
        .uuid = TA_STORAGE_UUID,
        .name = "storage",
        .flags = TA_FLAG_USER_MODE,
        .create_entry_point = TA_CreateEntryPoint,
        .destroy_entry_point = TA_DestroyEntryPoint,
        .open_session_entry_point = TA_OpenSessionEntryPoint,
        .close_session_entry_point = TA_CloseSessionEntryPoint,
        .invoke_command_entry_point = TA_InvokeCommandEntryPoint
};

#ifndef USER_TA_WASM
user_ta_register(.uuid = TA_UUID, .name = "storage",
        .flags = TA_FLAG_USER_MODE,
        .create_entry_point = TA_CreateEntryPoint,
        .destroy_entry_point = TA_DestroyEntryPoint,
        .open_session_entry_point = TA_OpenSessionEntryPoint,
        .close_session_entry_point = TA_CloseSessionEntryPoint,
        .invoke_command_entry_point = TA_InvokeCommandEntryPoint);
#else
struct user_ta_head *user_ta = &storage_user_ta_head;
#endif
