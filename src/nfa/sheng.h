/*
 * Copyright (c) 2016, Intel Corporation
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *  * Neither the name of Intel Corporation nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SHENG_H_
#define SHENG_H_

#include "callback.h"
#include "ue2common.h"

struct mq;
struct NFA;

#define nfaExecSheng0_B_Reverse NFA_API_NO_IMPL
#define nfaExecSheng0_zombie_status NFA_API_ZOMBIE_NO_IMPL

char nfaExecSheng0_Q(const struct NFA *n, struct mq *q, s64a end);
char nfaExecSheng0_Q2(const struct NFA *n, struct mq *q, s64a end);
char nfaExecSheng0_QR(const struct NFA *n, struct mq *q, ReportID report);
char nfaExecSheng0_inAccept(const struct NFA *n, ReportID report, struct mq *q);
char nfaExecSheng0_inAnyAccept(const struct NFA *n, struct mq *q);
char nfaExecSheng0_queueInitState(const struct NFA *nfa, struct mq *q);
char nfaExecSheng0_queueCompressState(const struct NFA *nfa, const struct mq *q,
                                      s64a loc);
char nfaExecSheng0_expandState(const struct NFA *nfa, void *dest,
                               const void *src, u64a offset, u8 key);
char nfaExecSheng0_initCompressedState(const struct NFA *nfa, u64a offset,
                                       void *state, u8 key);
char nfaExecSheng0_testEOD(const struct NFA *nfa, const char *state,
                           const char *streamState, u64a offset,
                           NfaCallback callback, void *context);
char nfaExecSheng0_reportCurrent(const struct NFA *n, struct mq *q);

char nfaExecSheng0_B(const struct NFA *n, u64a offset, const u8 *buffer,
                    size_t length, NfaCallback cb, void *context);

#endif /* SHENG_H_ */
