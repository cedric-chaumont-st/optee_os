/*
 * Copyright (c) 2014, STMicroelectronics International N.V.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef TEE_SYSCALL_NUMBERS_H
#define TEE_SYSCALL_NUMBERS_H

#define TEE_SCN_RETURN				0
#define TEE_SCN_LOG				1
#define TEE_SCN_PANIC				2
#define TEE_SCN_DUMMY				3
#define TEE_SCN_DUMMY_7ARGS			4
#define TEE_SCN_GET_PROPERTY			5
#define TEE_SCN_OPEN_TA_SESSION			6
#define TEE_SCN_CLOSE_TA_SESSION		7
#define TEE_SCN_INVOKE_TA_COMMAND		8
#define TEE_SCN_CHECK_ACCESS_RIGHTS		9
#define TEE_SCN_GET_CANCELLATION_FLAG		10
#define TEE_SCN_UNMASK_CANCELLATION		11
#define TEE_SCN_MASK_CANCELLATION		12
#define TEE_SCN_WAIT				13
#define TEE_SCN_GET_TIME			14
#define TEE_SCN_SET_TA_TIME			15
#define TEE_SCN_CRYP_STATE_ALLOC		16
#define TEE_SCN_CRYP_STATE_COPY			17
#define TEE_SCN_CRYP_STATE_FREE			18
#define TEE_SCN_HASH_INIT			19
#define TEE_SCN_HASH_UPDATE			20
#define TEE_SCN_HASH_FINAL			21
#define TEE_SCN_CIPHER_INIT			22
#define TEE_SCN_CIPHER_UPDATE			23
#define TEE_SCN_CIPHER_FINAL			24
#define TEE_SCN_CRYP_OBJ_GET_INFO		25
#define TEE_SCN_CRYP_OBJ_RESTRICT_USAGE		26
#define TEE_SCN_CRYP_OBJ_GET_ATTR		27
#define TEE_SCN_CRYP_OBJ_ALLOC			28
#define TEE_SCN_CRYP_OBJ_CLOSE			29
#define TEE_SCN_CRYP_OBJ_RESET			30
#define TEE_SCN_CRYP_OBJ_POPULATE		31
#define TEE_SCN_CRYP_OBJ_COPY			32
#define TEE_SCN_CRYP_DERIVE_KEY			33
#define TEE_SCN_CRYP_RANDOM_NUMBER_GENERATE	34
#define TEE_SCN_AUTHENC_INIT			35
#define TEE_SCN_AUTHENC_UPDATE_AAD		36
#define TEE_SCN_AUTHENC_UPDATE_PAYLOAD		37
#define TEE_SCN_AUTHENC_ENC_FINAL		38
#define TEE_SCN_AUTHENC_DEC_FINAL		39
#define TEE_SCN_ASYMM_OPERATE			40
#define TEE_SCN_ASYMM_VERIFY			41
#define TEE_SCN_STORAGE_OBJ_OPEN		42
#define TEE_SCN_STORAGE_OBJ_CREATE		43
#define TEE_SCN_STORAGE_OBJ_DEL			44
#define TEE_SCN_STORAGE_OBJ_RENAME		45
#define TEE_SCN_STORAGE_ENUM_ALLOC		46
#define TEE_SCN_STORAGE_ENUM_FREE		47
#define TEE_SCN_STORAGE_ENUM_RESET		48
#define TEE_SCN_STORAGE_ENUM_START		49
#define TEE_SCN_STORAGE_ENUM_NEXT		50
#define TEE_SCN_STORAGE_OBJ_READ		51
#define TEE_SCN_STORAGE_OBJ_WRITE		52
#define TEE_SCN_STORAGE_OBJ_TRUNC		53
#define TEE_SCN_STORAGE_OBJ_SEEK		54
#define TEE_SCN_CRYP_OBJ_GENERATE_KEY		55
#define TEE_SCN_SE_SERVICE_OPEN			56
#define TEE_SCN_SE_SERVICE_CLOSE		57
#define TEE_SCN_SE_SERVICE_GET_READERS		58
#define TEE_SCN_SE_READER_GET_PROP		59
#define TEE_SCN_SE_READER_GET_NAME		60
#define TEE_SCN_SE_READER_OPEN_SESSION		61
#define TEE_SCN_SE_READER_CLOSE_SESSIONS	62
#define TEE_SCN_SE_SESSION_IS_CLOSED		63
#define TEE_SCN_SE_SESSION_GET_ATR		64
#define TEE_SCN_SE_SESSION_OPEN_CHANNEL		65
#define TEE_SCN_SE_SESSION_CLOSE		66
#define TEE_SCN_SE_CHANNEL_SELECT_NEXT		67
#define TEE_SCN_SE_CHANNEL_GET_SELECT_RESP	68
#define TEE_SCN_SE_CHANNEL_TRANSMIT		69
#define TEE_SCN_SE_CHANNEL_CLOSE		70
#define TEE_SCN_CACHE_CLEAN			71
#define TEE_SCN_CACHE_FLUSH			72
#define TEE_SCN_CACHE_INVALIDATE		73

#define TEE_SCN_MAX				73

/* Maximum number of allowed arguments for a syscall */
#define TEE_SVC_MAX_ARGS			10

#endif /* TEE_SYSCALL_NUMBERS_H */
